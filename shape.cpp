#include "shape.h"

/*Shape::Shape(){

}*/

void Shape::cube(float x, float z, std::vector<float> color){
    glLineWidth(2.0);
    top(x,z, color);
    left(x,z, color);
    right(x,z, color);
    front(x,z, color);
    back(x,z, color);
}

void Shape::top(float x, float z, std::vector<float> color){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, 0, z+World::view.z);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z+1);
    glVertex3f(x+World::view.x, 0, z+World::view.z+1);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, 0, z+World::view.z);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z+1);
    glVertex3f(x+World::view.x, 0, z+World::view.z+1);
    glEnd();
}

void Shape::left(float x, float z, std::vector<float> color){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, 0, z+World::view.z);
    glVertex3f(x+World::view.x, -1, z+World::view.z);
    glVertex3f(x+World::view.x, -1, z+World::view.z+1);
    glVertex3f(x+World::view.x, 0, z+World::view.z+1);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, 0, z+World::view.z);
    glVertex3f(x+World::view.x, -1, z+World::view.z);
    glVertex3f(x+World::view.x, -1, z+World::view.z+1);
    glVertex3f(x+World::view.x, 0, z+World::view.z+1);
    glEnd();
}

void Shape::right(float x, float z, std::vector<float> color){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z);
    glVertex3f(x+World::view.x+1, -1, z+World::view.z);
    glVertex3f(x+World::view.x+1, -1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z+1);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z);
    glVertex3f(x+World::view.x+1, -1, z+World::view.z);
    glVertex3f(x+World::view.x+1, -1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z+1);
    glEnd();
}

void Shape::front(float x, float z, std::vector<float> color){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, 0, z+World::view.z+1);
    glVertex3f(x+World::view.x, -1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, -1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z+1);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, 0, z+World::view.z+1);
    glVertex3f(x+World::view.x, -1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, -1, z+World::view.z+1);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z+1);
    glEnd();
}

void Shape::back(float x, float z, std::vector<float> color){
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, 0, z+World::view.z);
    glVertex3f(x+World::view.x, -1, z+World::view.z);
    glVertex3f(x+World::view.x+1, -1, z+World::view.z);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POLYGON);
    glVertex3f(x+World::view.x, 0, z+World::view.z);
    glVertex3f(x+World::view.x, -1, z+World::view.z);
    glVertex3f(x+World::view.x+1, -1, z+World::view.z);
    glVertex3f(x+World::view.x+1, 0, z+World::view.z);
    glEnd();
}
