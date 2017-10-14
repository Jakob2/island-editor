#include "gui.h"

Gui::Gui(){

}

void Gui::connectGui(){
    connect(comboBox_range, SIGNAL(currentIndexChanged(int)), this, SLOT(range()));
    connect(comboBox_ground, SIGNAL(currentIndexChanged(int)), this, SLOT(ground()));
    connect(dial_zoom, SIGNAL(valueChanged(int)), this, SLOT(zoom()));
    connect(pushButton_newmap, SIGNAL(pressed()), this, SLOT(add()));
    connect(comboBox_names, SIGNAL(currentIndexChanged(int)), this, SLOT(select()));
    connect(pushButton_savemap, SIGNAL(pressed()), this, SLOT(save()));
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
            Tilemap::initTiles(10);
            setNames(10);
        break;
        case 1:
            World::editor.range = 15;
            Tilemap::initTiles(15);
            setNames(15);
        break;
        case 2:
            World::editor.range = 20;
            Tilemap::initTiles(20);
            setNames(20);
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
    newIsland(Tilemap::tiles);
    setNames(Tilemap::tiles.size());
    fillInNames();
}

void Gui::setName(){
    World::editor.name = comboBox_names->currentText().toInt();
    //std::cout<<"NAME: "<<World::editor.name<<std::endl;
}

void Gui::save(){
    //std::cout<<"TEST NAME: "<<World::editor.name<<std::endl;
    if(World::editor.name) saveIsland(Tilemap::tiles, World::editor.range, QString::number(World::editor.name));
}

void Gui::select(){
    setName();
    setTiles(World::editor.range, QString::number(World::editor.name));
}

