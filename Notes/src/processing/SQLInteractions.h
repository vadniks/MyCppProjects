/*************************************************
 **  Created by Vad Nik on 05-Oct-18.
 *************************************************/

#ifndef NOTES_SQLINTERACTIONS_H
#define NOTES_SQLINTERACTIONS_H

#include <vector>
#include <QString>
#include <QtSql/QtSql>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include "../util/ListItem.h"
#include "../util/consts.h"

using namespace std;

class SQLInteractions
{

private:
    QSqlDatabase db;

public:
    SQLInteractions();
    ~SQLInteractions();

public:
    vector<ListItem> loadItems();
    bool putItem(ListItem &item);
    ListItem getItem(int id);
    bool updateItem(int id, ListItem nw);
    int getItemCount();

private:
    bool createConnection();
    bool createDB();
    QByteArray toByteArray(ListItem &item);
    ListItem fromByteArray(QByteArray arr);
};


#endif //NOTES_SQLINTERACTIONS_H
