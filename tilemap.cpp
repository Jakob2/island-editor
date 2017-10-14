#include "tilemap.h"

std::vector<std::vector<int>> Tilemap::tiles;

void Tilemap::initTiles(int size){
    Tilemap::tiles.clear();
    for(int x=0; x<size; x++){
        Tilemap::tiles.push_back(std::vector<int>());
        for(int z=0; z<size; z++){
            Tilemap::tiles[x].push_back(0);
        }
    }
    //std::cout<<"TILES SIZE: "<<Tilemap::tiles[0].size()<<" - "<<Tilemap::tiles[1].size()<<std::endl;
}

Tilemap::Tilemap(){
    Tilemap::initTiles(10);
}

void Tilemap::ground(std::vector<std::vector<int>> &tiles){
    for(float x=0; x<(float)World::editor.range; x++){
        for(float z=0; z<(float)World::editor.range; z++){
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            glLineWidth(2.0);
            glColor3f(0,0,0);
            glBegin(GL_POLYGON);
            glVertex3f(x+World::view.x,0,z+World::view.z);
            glVertex3f(x+World::view.x+1,0,z+World::view.z);
            glVertex3f(x+World::view.x+1,0,z+World::view.z+1);
            glVertex3f(x+World::view.x,0,z+World::view.z+1);
            glEnd();
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            if(tiles[x][z] == 0) glColor3f(0,1,0);
            if(tiles[x][z] == 1) glColor3f(.4,.4,.4);
            if(tiles[x][z] == 2) glColor3f(0,0,1);
            glBegin(GL_POLYGON);
            glVertex3f(x+World::view.x,0,z+World::view.z);
            glVertex3f(x+World::view.x+1,0,z+World::view.z);
            glVertex3f(x+World::view.x+1,0,z+World::view.z+1);
            glVertex3f(x+World::view.x,0,z+World::view.z+1);
            glEnd();
        }
    }
}

