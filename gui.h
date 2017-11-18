#ifndef GUI_H
#define GUI_H

#include "general.h"
#include "world.h"
#include "ui_mainwindow.h"
#include "tilemap.h"
#include "db.h"

class Gui : public QDialog, public Ui::MainWindow, public Db
{
    Q_OBJECT
public:
    Gui();

    void connectGui();
    void fillInNames();

public slots:
    void range();
    void ground();
    void zoom();
    void add();
    void setName();
    void save();
    void select();
 };

#endif // GUI_H
