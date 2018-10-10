/*************************************************
 **  Created by Vad Nik on 05-Oct-18.
 *************************************************/

#ifndef NOTES_SQLINTERACTIONS_H
#define NOTES_SQLINTERACTIONS_H

#include <vector>
#include <QString>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QDebug>
#include <iostream>
#include "../util/ListItem.h"
#include "../util/consts.h"

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>

using namespace std;

class SQLInteractions
{

private:
    static QSqlDatabase db;

//public:
//    SQLInteractions();
//    ~SQLInteractions();

public:
    static void init();
    static vector<ListItem> loadItems();
    static bool putItem(ListItem item);
    static ListItem getItem(int id);
    static bool updateItem(int id, ListItem nw);
    static int getItemCount();
    static bool deleteItem(int id);

private:
    static bool createConnection();
    static bool createDB();
    static QByteArray toByteArray(ListItem &item);
    static ListItem fromByteArray(QByteArray arr);
    static bool hasCreated();
};


#endif //NOTES_SQLINTERACTIONS_H
