#include "glwidget.h"

GlWidget::GlWidget(QWidget * parent) : QGLWidget(parent){
    setFocusPolicy(Qt::StrongFocus);
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);
}

void GlWidget::initializeGL(){
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glClearColor(0.5, 0.5, 0.5, 1);
    glEnable(GL_DEPTH_TEST);
}

void GlWidget::paintGL(){
    setMouseTracking(true);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    resizeGL(0,0);
    ddd();
    glScalef(World::view.zoom,World::view.zoom,World::view.zoom);
    ground(Tilemap::tiles);
    mountain(Tilemap::mountains);
    text(10,20,World::editor.textGround);
    text(10,40,World::editor.textMountain);
}

void GlWidget::resizeGL(int w, int h){
    World::view.height = GlWidget::height();
    World::view.width = GlWidget::width();
}

void GlWidget::ddd(){
    glViewport(0,0, World::view.width,World::view.height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)World::view.width/World::view.height, 0.01, 100.0);
    gluLookAt(World::view.eyeX,World::view.eyeY,World::view.eyeZ, 0,0,0, 0,1,0);
}

void GlWidget::text(int x, int y, QString text){
    glColor3f(0,0,0);
    renderText(x,y,text);
}

void GlWidget::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_A:
        World::view.x += camMoveUnit[0];
        World::view.z -= camMoveUnit[1];
        break;
    case Qt::Key_D:
        World::view.x -= camMoveUnit[0];
        World::view.z += camMoveUnit[1];
        break;
    case Qt::Key_W:
        World::view.x += camMoveUnit[1];
        World::view.z += camMoveUnit[0];
        break;
    case Qt::Key_S:
        World::view.x -= camMoveUnit[1];
        World::view.z -= camMoveUnit[0];
        break;
    case Qt::Key_K:
        World::editor.alterGround ? World::editor.alterGround = false : World::editor.alterGround = true;
        if(World::editor.alterGround) World::editor.textGround = "active ground option: "+QString::number(World::editor.ground);
        else World::editor.textGround = "toggle ground mode press k";
        if(World::editor.alterMountain){
            World::editor.textMountain = "toggle mountain mode press l";
            World::editor.alterMountain = false;
        }
        break;
    case Qt::Key_L:
        World::editor.alterMountain ? World::editor.alterMountain = false : World::editor.alterMountain = true;
        if(World::editor.alterMountain) World::editor.textMountain = "active mountain height: ";
        else World::editor.textMountain = "toggle mountain mode press l";
        if(World::editor.alterGround){
            World::editor.textGround = "toggle ground mode press k";
            World::editor.alterGround = false;
        }
        break;
    }
}

void GlWidget::mousePressEvent(QMouseEvent *event){
    int mouseX, mouseY;
    mouseX = event->pos().x();
    mouseY = event->pos().y();
    //std::cout<<"mouseX: "<<mouseX<<" / mouseY: "<<mouseY<<std::endl;
    calculateGLCoords(mouseX,mouseY);
    if(World::editor.alterGround){
        Tilemap::tiles[World::editor.tile[0]][World::editor.tile[1]][0] = World::editor.ground;
        Tilemap::tiles[World::editor.tile[0]][World::editor.tile[1]][1] = 1;
    }
    if(World::editor.alterMountain){
        QString name,xx,zz,height;
        name = QString::number(World::editor.name);
        xx = QString::number(World::editor.tile[0]);
        zz = QString::number(World::editor.tile[1]);
        height = QString::number(1);
        Db::addMountain(name,xx,zz,height);
        Db::setMountains(QString::number(World::editor.name));
    }
}
