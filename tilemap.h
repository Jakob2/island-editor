#ifndef TILEMAP_H
#define TILEMAP_H

#include "general.h"
#include "world.h"

class Tilemap
{
public:
    static std::vector<std::vector<int>> tiles;
    static void setTiles(int size);

    Tilemap();

    void ground(std::vector<std::vector<int> > &tiles);
};

#endif // TILEMAP_H
