#ifndef SHAPE_H
#define SHAPE_H

#include "general.h"
#include "world.h"

class Shape
{
public:
    //Shape();
    void cube(float x, float z, std::vector<float> color);

private:
    void top(float x, float z, std::vector<float> color);
    void left(float x, float z, std::vector<float> color);
    void right(float x, float z, std::vector<float> color);
    void front(float x, float z, std::vector<float> color);
    void back(float x, float z, std::vector<float> color);

};

#endif // SHAPE_H
