#include "gui.h"

Gui::Gui(){

}

void Gui::connectGui(){
    connect(comboBox_range, SIGNAL(currentIndexChanged(int)), this, SLOT(range()));
    connect(comboBox_ground, SIGNAL(currentIndexChanged(int)), this, SLOT(ground()));
    connect(dial_zoom, SIGNAL(valueChanged(int)), this, SLOT(zoom()));
    connect(pushButton_newmap, SIGNAL(pressed()), this, SLOT(add()));
    connect(comboBox_names, SIGNAL(currentIndexChanged(int)), this, SLOT(chooseName()));
}

void Gui::fillInNames(){
    comboBox_names->clear();
    for(QString s : World::names){
        comboBox_names->addItem(s);
    }
}

void Gui::range(){
    switch(comboBox_range->currentIndex()){
        case 0:
            World::editor.range = 10;
            Tilemap::setTiles(10);
            Db::setNames(10);
        break;
        case 1:
            World::editor.range = 15;
            Tilemap::setTiles(15);
            Db::setNames(15);
        break;
        case 2:
            World::editor.range = 20;
            Tilemap::setTiles(20);
            Db::setNames(20);
        break;
    }
    fillInNames();
}

void Gui::ground(){
    World::editor.ground = comboBox_ground->currentIndex();
}

void Gui::zoom(){
    World::view.zoom = (float)dial_zoom->value()/100;
}

void Gui::add(){
    Db::newIsland(Tilemap::tiles);
    Db::setNames(Tilemap::tiles.size());
    fillInNames();
}

void Gui::chooseName(){
    World::editor.name = comboBox_names->currentText().toInt();
    std::cout<<"NAME: "<<World::editor.name<<std::endl;
}

