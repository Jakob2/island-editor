#include "shape.h"

/*Shape::Shape(){

}*/

void Shape::cube(float x, float z, std::vector<float> color, int height){
    glLineWidth(2.0);
    top(x,z,color,height);
    left(x,z,color,height);
    right(x,z,color,height);
    front(x,z,color,height);
    back(x,z,color,height);
}

void Shape::top(float x, float z, std::vector<float> color, int height){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x,   height, z+World::view.z);
    glVertex3f(x+World::view.x+1, height, z+World::view.z);
    glVertex3f(x+World::view.x+1, height, z+World::view.z+1);
    glVertex3f(x+World::view.x,   height, z+World::view.z+1);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x,   height, z+World::view.z);
    glVertex3f(x+World::view.x+1, height, z+World::view.z);
    glVertex3f(x+World::view.x+1, height, z+World::view.z+1);
    glVertex3f(x+World::view.x,   height, z+World::view.z+1);
    glEnd();
}

void Shape::left(float x, float z, std::vector<float> color, int height){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, height, z+World::view.z);
    glVertex3f(x+World::view.x, height-1, z+World::view.z);
    glVertex3f(x+World::view.x, height-1, z+World::view.z+1);
    glVertex3f(x+World::view.x, height, z+World::view.z+1);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, height, z+World::view.z);
    glVertex3f(x+World::view.x, height-1, z+World::view.z);
    glVertex3f(x+World::view.x, height-1, z+World::view.z+1);
    glVertex3f(x+World::view.x, height, z+World::view.z+1);
    glEnd();
}

void Shape::right(float x, float z, std::vector<float> color, int height){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x+1, height, z+World::view.z);
    glVertex3f(x+World::view.x+1, height-1, z+World::view.z);
    glVertex3f(x+World::view.x+1, height-1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, height, z+World::view.z+1);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x+1, height, z+World::view.z);
    glVertex3f(x+World::view.x+1, height-1, z+World::view.z);
    glVertex3f(x+World::view.x+1, height-1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, height, z+World::view.z+1);
    glEnd();
}

void Shape::front(float x, float z, std::vector<float> color, int height){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x,   height, z+World::view.z+1);
    glVertex3f(x+World::view.x,   height-1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, height-1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, height, z+World::view.z+1);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x,   height, z+World::view.z+1);
    glVertex3f(x+World::view.x,   height-1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, height-1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, height, z+World::view.z+1);
    glEnd();
}

void Shape::back(float x, float z, std::vector<float> color, int height){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, height, z+World::view.z);
    glVertex3f(x+World::view.x, height-1, z+World::view.z);
    glVertex3f(x+World::view.x+1, height-1, z+World::view.z);
    glVertex3f(x+World::view.x+1, height, z+World::view.z);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, height, z+World::view.z);
    glVertex3f(x+World::view.x, height-1, z+World::view.z);
    glVertex3f(x+World::view.x+1, height-1, z+World::view.z);
    glVertex3f(x+World::view.x+1, height, z+World::view.z);
    glEnd();
}
