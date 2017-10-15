#ifndef SHAPE_H
#define SHAPE_H

#include "general.h"
#include "world.h"

class Shape
{
public:
    //Shape();
    void cube(float x, float z, std::vector<float> color, int height);

private:
    void top(float x, float z, std::vector<float> color, int height);
    void left(float x, float z, std::vector<float> color, int height);
    void right(float x, float z, std::vector<float> color, int height);
    void front(float x, float z, std::vector<float> color, int height);
    void back(float x, float z, std::vector<float> color, int height);

};

#endif // SHAPE_H
