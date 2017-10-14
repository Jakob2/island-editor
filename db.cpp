#include "db.h"

Db::Db(){
    Db::database = "islands";
    Db::smallTable = "small";
    Db::mediumTable = "medium";
    Db::bigTable = "big";
    connectDatabase();
    createSmallTable();
    setNames(10);
}

void Db::connectDatabase(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/ok/jakob/QT4/DATABASES/"+Db::database);
    if(!db.open()) std::cout<< "Error: connection with database fail"<<std::endl;
    else std::cout<< "Database: connection ok"<<std::endl;
}

void Db::setNames(int range){
    World::names.clear();
    QString table = Db::tableName(range);
    /*switch(range){
        case 10:
            table = Db::smallTable;
        break;
        case 15:
            table = Db::mediumTable;
        break;
        case 20:
            table = Db::bigTable;
        break;
    }*/
    QSqlQuery query;
    if(query.exec("select distinct name from "+table)) std::cout<<"names selected"<<std::endl;
    else qDebug()<<"select names error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        World::names.push_back(QString::number(query.value(0).toInt()));
    }
}

void Db::setTiles(int range, QString name){
    std::cout<<"NAME: "<<name.toStdString()<<std::endl;
    Tilemap::initTiles(range);
    QSqlQuery query;
    QString table = Db::tableName(range);
    int x,z,ground;
    if(query.exec("select x,z,ground from "+table+" where name = '"+name+"'")) std::cout<<"tiles selected"<<std::endl;
    else qDebug()<<"select tiles error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        x = query.value(0).toInt();
        z = query.value(1).toInt();
        ground = query.value(2).toInt();
        Tilemap::tiles[x][z] = ground;
    }
}

void Db::createSmallTable(){
    QSqlQuery query;
    if(query.exec("create table if not exists small (`0` int)")) std::cout<<"small table created"<<std::endl;
    else qDebug()<<"create small table error: "<<query.lastError()<<" / "<<query.lastQuery();
    if(query.exec("alter table "+Db::smallTable+" add column name int")) std::cout<<"ID column added"<<std::endl;
    else qDebug()<<"add ID column error: "<<query.lastError()<<" / "<<query.lastQuery();
    if(query.exec("alter table "+Db::smallTable+" add column x int")) std::cout<<"X column added"<<std::endl;
    else qDebug()<<"add X column error: "<<query.lastError()<<" / "<<query.lastQuery();
    if(query.exec("alter table "+Db::smallTable+" add column z int")) std::cout<<"Z column added"<<std::endl;
    else qDebug()<<"add Z column error: "<<query.lastError()<<" / "<<query.lastQuery();
    if(query.exec("alter table "+Db::smallTable+" add column ground int")) std::cout<<"ground column added"<<std::endl;
    else qDebug()<<"add ground column error: "<<query.lastError()<<" / "<<query.lastQuery();
}

void Db::newIsland(std::vector<std::vector<int>> &tiles){
    QSqlQuery query;
    QString xx,zz, ground,name;
    int id;
    if(query.exec("select max(name) from "+Db::smallTable)) std::cout<<"distinct name selected"<<std::endl;
    else qDebug()<<"select distinct name error: "<<query.lastError()<<" / "<<query.lastQuery();
    while(query.next()){
        id = query.value(0).toInt();
    }
    std::cout<<"ID: "<<id<<std::endl;
    id++;
    name = QString::number(id);
    for(int x=0; x<(int)tiles.size(); x++){
        for(int z=0; z<(int)tiles[x].size(); z++){
            xx = QString::number(x);
            zz = QString::number(z);
            ground = QString::number(tiles[x][z]);
            if(query.exec("insert into "+Db::smallTable+" (name,x,z,ground) values ("+name+","+xx+","+zz+","+ground+")")) std::cout<<"small table created"<<std::endl;
            else qDebug()<<"create small table error: "<<query.lastError()<<" / "<<query.lastQuery();
        }
    }
}

void Db::saveIsland(std::vector<std::vector<int>> &tiles, int range, QString name){
    QSqlQuery query;
    QString xx,zz, ground;
    switch(range){
        case 10:
            for(int x=0; x<(int)tiles.size(); x++){
                for(int z=0; z<(int)tiles[x].size(); z++){
                    xx = QString::number(x);
                    zz = QString::number(z);
                    ground = QString::number(tiles[x][z]);
                    if(query.exec("insert into "+Db::smallTable+" (name,x,z,ground) values ("+name+","+xx+","+zz+","+ground+")")) std::cout<<"small table created"<<std::endl;
                    else qDebug()<<"create small table error: "<<query.lastError()<<" / "<<query.lastQuery();
                }
            }
        break;
    }
}

QString Db::tableName(int range){
    switch(range){
        case 10:
            return Db::smallTable;
        break;
        case 15:
            return Db::mediumTable;
        break;
        case 20:
            return Db::bigTable;
        break;
    }
}


