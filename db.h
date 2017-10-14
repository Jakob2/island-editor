#ifndef DB_H
#define DB_H

#include "general.h"
#include "world.h"

class Db
{
public:
    Db();

    static void createSmallTable();
    static void createMediumTable();
    static void createBigTable();

    static QString database;
    static QString smallTable;
    static QString mediumTable;
    static QString bigTable;
    static void connectDatabase();
    static void setNames(int range);

    static void newIsland(std::vector<std::vector<int> > &tiles);
    static void saveIsland(std::vector<std::vector<int>> &tiles, int range, QString name);

};

#endif // DB_H
