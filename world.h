#ifndef WORLD_H
#define WORLD_H

#include "general.h"

class World
{
public:
    World();

    static struct Window{
        int width;
        int height;
        int eyeX;
        int eyeY;
        int eyeZ;
        float x;
        float z;
        float zoom;
    }view;

    static struct Editor{
        //std::vector<int> baseRange;
        int range;
        int ground; //0=>grass, 1=>rock, 2=>water
        QString textGround;
        QString textMountain;
        bool alterGround;
        bool alterMountain;
        std::vector<float> tile;
        int name;
        int height;
    }editor;

    static std::vector<QString> names;
};

#endif // WORLD_H
