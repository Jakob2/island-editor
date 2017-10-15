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
            cube(x,z, color(tiles[x][z]));
        }
    }
}

std::vector<float> Tilemap::color(int ground){
    if(ground == 0) return {0,1,0};
    if(ground == 1) return {.4,.4,.4};
    if(ground == 2) return {0,0,1};
}

