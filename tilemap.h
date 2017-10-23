#ifndef TILEMAP_H
#define TILEMAP_H

#include "general.h"
#include "world.h"
#include "shape.h"

class Tilemap : public Shape
{
public:
    static std::vector<std::vector<std::vector<int>>> tiles;
    static void initTiles(int size);

    static std::vector<std::vector<int>> mountains;
    static void initMountains(int size);

    Tilemap();

    void ground(std::vector<std::vector<std::vector<int>>> &tiles);
    void mountain(std::vector<std::vector<int>> &mountains);
    void mountainColors(std::vector<std::vector<int>> &mountains);

private:
    std::vector<float> color(int ground);
};

#endif // TILEMAP_H
