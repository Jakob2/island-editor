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
        int range;
        int ground; //0=>grass, 1=>rock, 2=>water
        QString textGround;
        QString textMountain;
        bool alterGround;
        bool alterMountain;
        std::vector<int> tile;
        int name;
        int height;
    }editor;

    static struct Mouse{
        int pickedColor;
    }mouse;

    static struct Height{
        std::vector<float> one;
        std::vector<float> two;
        std::vector<float> three;
        std::vector<float> four;
    }color;

    static std::vector<QString> names;
};

#endif // WORLD_H
