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

std::vector<float> Mouseray::direction(std::vector<float> a, std::vector<float> b){
    std::vector<float> res;
    res.resize(3);
    res[0] = b[0] - a[0];
    res[1] = b[1] - a[1];
    res[2] = b[2] - a[2];
    return res;
}

void Mouseray::intersect(std::vector<float> in){
    float t,x,y,z;
    t = (World::editor.height-World::view.eyeY)/in[1];
    x = World::view.eyeX + (t*in[0]);
    y = World::editor.height;
    z = World::view.eyeZ + (t*in[2]);
    if(x < 0) x = 0;
    if(x > World::editor.range-1) x = World::editor.range-1;
    if(z < 0) z = 0;
    if(z > World::editor.range-1) z = World::editor.range-1;
    World::editor.tile = {(int)floor(x),(int)floor(z)};
    std::cout<<"X: "<<x<<" - Y: "<<y<<" - Z: "<<z<<std::endl;
}

void Mouseray::readPixelColor(int x, int y){
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    unsigned char pixelcolor[3];
    glReadPixels(x,World::view.height-y, 1,1, GL_RGB,GL_UNSIGNED_BYTE, pixelcolor);
    World::mouse.pickedColor = pixelcolor[0] + pixelcolor[1] * 256 + pixelcolor[2] * 256*256;
    //std::cout<<"PIXELID: "<<World::mouse.pickedColor<<std::endl;
}

void Mouseray::setEditorHeight(int pickedColor){
    if(pickedColor == 8421504) World::editor.height = 0;
    if(pickedColor == 51) World::editor.height = 1;
    if(pickedColor == 76) World::editor.height = 2;
    if(pickedColor == 102) World::editor.height = 3;
    std::cout<<"HEIGHT: "<<World::editor.height<<std::endl;
}

