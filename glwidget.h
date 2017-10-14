#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "general.h"
#include "world.h"
#include "tilemap.h"
#include "db.h"
#include "mouseray.h"

class GlWidget : public QGLWidget, public Tilemap, public Mouseray
{
public:
    explicit GlWidget(QWidget * parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    QTimer timer;
    void ddd();
    std::vector<float> camMoveUnit = {.5,.5};
    void text(int x,int y, QString text);
};

#endif // GLWIDGET_H
