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
    case Qt::Key_K: toggleGround(); break;
    case Qt::Key_L: toggleMountain(); break;
    case Qt::Key_X: deleteMountain(); break;
    }
}

void GlWidget::mousePressEvent(QMouseEvent *event){
    int mouseX, mouseY;
    mouseX = event->pos().x();
    mouseY = event->pos().y();
    //std::cout<<"mouseX: "<<mouseX<<" / mouseY: "<<mouseY<<std::endl;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    mountainColors(Tilemap::mountains);
    readPixelColor(mouseX,mouseY);
    updateGL();
    setEditorHeight(World::mouse.pickedColor);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ground(Tilemap::tiles);
    mountain(Tilemap::mountains);
    calculateGLCoords(mouseX,mouseY);
    updateGL();
    if(World::editor.alterGround) alterGround();
    if(World::editor.alterMountain) addMountain();
}


void GlWidget::ddd(){
    glViewport(0,0, World::view.width,World::view.height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)World::view.width/World::view.height, 0.01, 100.0);
    gluLookAt(World::view.eyeX+World::view.x,World::view.eyeY,World::view.eyeZ+World::view.z, 0+World::view.x,0,0+World::view.z, 0,1,0);
}

void GlWidget::text(int x, int y, QString text){
    glColor3f(0,0,0);
    renderText(x,y,text);
}

void GlWidget::alterGround(){
    Tilemap::tiles[World::editor.tile[0]][World::editor.tile[1]][0] = World::editor.ground;
    Tilemap::tiles[World::editor.tile[0]][World::editor.tile[1]][1] = 1;
}

void GlWidget::addMountain(){
    QString name,xx,zz,height;
    name = QString::number(World::editor.name);
    xx = QString::number(World::editor.tile[0]);
    zz = QString::number(World::editor.tile[1]);
    Db::addMountain(name,xx,zz,QString::number(World::editor.height+1));
    Db::setMountains(QString::number(World::editor.name));
}

void GlWidget::deleteMountain(){
    QString name,x,z,height;
    name = QString::number(World::editor.name);
    x = QString::number(World::editor.tile[0]);
    z = QString::number(World::editor.tile[1]);
    height = QString::number(World::editor.height);
    Db::deleteMountain(name,x,z,height);
    Db::setMountains(QString::number(World::editor.name));
}

void GlWidget::toggleGround(){
    World::editor.alterGround ? World::editor.alterGround = false : World::editor.alterGround = true;
    if(World::editor.alterGround) World::editor.textGround = "active ground option: "+QString::number(World::editor.ground);
    else World::editor.textGround = "toggle ground mode press k";
    if(World::editor.alterMountain){
        World::editor.textMountain = "toggle mountain mode press l (delete: x)";
        World::editor.alterMountain = false;
    }
}

void GlWidget::toggleMountain(){
    World::editor.alterMountain ? World::editor.alterMountain = false : World::editor.alterMountain = true;
    if(World::editor.alterMountain) World::editor.textMountain = "mountain mode";
    else World::editor.textMountain = "toggle mountain mode press l (delete: x)";
    if(World::editor.alterGround){
        World::editor.textGround = "toggle ground mode press k";
        World::editor.alterGround = false;
    }
}

