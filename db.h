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

    void newIsland(std::vector<std::vector<std::vector<int>>> &tiles);
    QString saveIsland(QString name, QString xx, QString zz, QString ground, int range);

private:
    QString tableName(int range);
};

#endif // DB_H
