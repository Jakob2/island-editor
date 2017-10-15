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
            cube(x,z,color(tiles[x][z][0]),0);
        }
    }
}

void Tilemap::mountain(std::vector<std::vector<int> > &mountains){
    int x,z,height;
    for(int i=0; i<(int)mountains.size(); i++){
        x = mountains[i][0];
        z = mountains[i][1];
        height = mountains[i][2];
        cube(x,z,color(1),height);
    }
}

std::vector<float> Tilemap::color(int ground){
    if(ground == 0) return {0,1,0};
    if(ground == 1) return {.4,.4,.4};
    if(ground == 2) return {0,0,1};
    return {0,0,0};
}

