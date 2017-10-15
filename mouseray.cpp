#include "mouseray.h"

Mouseray::Mouseray(){

}

void Mouseray::calculateGLCoords(int x, int y){
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetIntegerv(GL_VIEWPORT, viewport);
    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);
    e = {(float)World::view.eyeX, (float)World::view.eyeY, (float)World::view.eyeZ};
    p = {(float)posX, (float)posY, (float)posZ};
    intersect(direction(e,p));
}

void Mouseray::intersect(std::vector<float> in){
    float x, y, z, r, t, xx, zz; // yy,
    x = in[0];
    y = in[1];
    z = in[2];
    r = ((-World::view.eyeY*x) + (y*World::view.eyeX)) / y;
    t = (World::view.eyeX-r) / -x;
    xx = World::view.eyeX + (t * x);
    //yy = World::view.eyeY + (t * y);
    zz = World::view.eyeZ + (t * z);

    float txx, tzz;
    txx = floor(xx-World::view.x);
    tzz = floor(zz-World::view.z);
    if(txx < 0) txx = 0;
    if(txx > World::editor.range-1) txx = World::editor.range-1;
    if(tzz < 0) tzz = 0;
    if(tzz > World::editor.range-1) tzz = World::editor.range-1;
    World::editor.tile = {txx,tzz};
    std::cout<<"TILE: "<<World::editor.tile[0]<<"-"<<World::editor.tile[1]<<std::endl;
}

std::vector<float> Mouseray::direction(std::vector<float> a, std::vector<float> b){
    std::vector<float> res;
    res.resize(3);
    res[0] = b[0] - a[0];
    res[1] = b[1] - a[1];
    res[2] = b[2] - a[2];
    return res;
}

