#include "tilemap.h"

std::vector<std::vector<std::vector<int>>> Tilemap::tiles;
std::vector<std::vector<int>> Tilemap::mountains;

void Tilemap::initTiles(int size){
    Tilemap::tiles.clear();
    for(int x=0; x<size; x++){
        Tilemap::tiles.push_back(std::vector<std::vector<int>>());
        for(int z=0; z<size; z++){
            Tilemap::tiles[x].push_back(std::vector<int>());
            for(int a=0; a<3; a++){
                Tilemap::tiles[x][z].push_back(0); //0=>ground, 1=>saving
            }
        }
    }
}

void Tilemap::initMountains(int size){
    Tilemap::mountains.clear();
    for(int x=0; x<size; x++){
        Tilemap::mountains.push_back(std::vector<int>());
        for(int z=0; z<3; z++){
            Tilemap::mountains[x].push_back(0); //0=>x, 1=>z, 2=>height
        }
    }
}

Tilemap::Tilemap(){
    Tilemap::initTiles(10);
}

void Tilemap::ground(std::vector<std::vector<std::vector<int> > > &tiles){
    for(float x=0; x<(float)World::editor.range; x++){
        for(float z=0; z<(float)World::editor.range; z++){
            //cube(x,z,color(tiles[x][z][0]),5);
            //cube(x,z,color(tiles[x][z][0]),1);
            cube(x,z,color(tiles[x][z][0]),0);
        }
    }
}

void Tilemap::mountain(std::vector<std::vector<int> > &mountains){
    int x,z,height;
    std::vector<float> selected = {.8,.8,.8};
    for(int i=0; i<(int)mountains.size(); i++){
        x = mountains[i][0];
        z = mountains[i][1];
        height = mountains[i][2];
        //std::cout<<"HEIGHT: "<<height<<std::endl;
        if(World::editor.tile[0] == x && World::editor.tile[1] == z) cube(x,z,selected,height);
        else cube(x,z,color(1),height);
    }
}

void Tilemap::mountainColors(std::vector<std::vector<int> > &mountains){
    int x,z,height;
    for(int i=0; i<(int)mountains.size(); i++){
        x = mountains[i][0];
        z = mountains[i][1];
        height = mountains[i][2];
        switch(height){
            case 0: cube(x,z,color(3),height); break;
            case 1: cube(x,z,color(4),height); break;
            case 2: cube(x,z,color(5),height); break;
            case 3: cube(x,z,color(6),height); break;
        }
    }
}

std::vector<float> Tilemap::color(int ground){
   switch(ground){
        case 0: return {0,1,0}; break;
        case 1: return {.4,.4,.4}; break;
        case 2: return {0,0,1}; break;
        case 3: return World::color.one; break;
        case 4: return World::color.two; break;
        case 5: return World::color.three; break;
        case 6: return World::color.four; break;
        default: return {0,0,0};
    }
}

