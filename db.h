#ifndef DB_H
#define DB_H

#include "general.h"
#include "world.h"
#include "tilemap.h"

class Db
{
public:
    Db();

    void createSmallTable();
    void createMediumTable();
    void createBigTable();

    QString database;
    QString smallTable;
    QString mediumTable;
    QString bigTable;
    void connectDatabase();
    void setNames(int range);
    void setTiles(int range, QString name);

    QString newIsland(std::vector<std::vector<std::vector<int>>> &tiles);
    QString saveIsland(QString name, QString xx, QString zz, QString ground, int range);

    static void setMountains(QString name);
    static void addMountain(QString name, QString xx, QString zz, QString height);

private:
    QString tableName(int range);
    /*std::vector<std::vector<int>> cube = {{0,0,0},{1,0,0},{1,0,1},{0,0,1}, //top
                                          {0,0,0},{0,-1,0},{0,-1,1},{0,0,1}, //left
                                          {1,0,0},{1,-1,0},{1,-1,1},{1,0,1}, //right
                                          {0,0,1},{0,-1,1},{1,-1,1},{1,0,1}, //front
                                          {0,0,0},{0,-1,0},{1,-1,0},{1,0,0}}; //back*/
};

#endif // DB_H
