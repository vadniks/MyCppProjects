/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#ifndef NOTES_LISTITERACTIONS_H
#define NOTES_LISTITERACTIONS_H

#include <QListWidget>
#include <vector>
#include <QStringList>
#include <QVariant>
#include <QDataStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QTextStream>
#include "../../../util/consts.h"
#include "../../../util/IllegalStateException.h"
#include "../../../util/ListItem.h"

using namespace std;

class ListInteractions
{

private:
    QListWidget *list;
    vector<QListWidgetItem> items;

public:
    explicit ListInteractions(QListWidget *list);
    ~ListInteractions();

public:
    void addItem(QString title, QString text);
    void addItems(vector<QListWidgetItem *> *items);
    int getItemIndex(QListWidgetItem &item);
    QListWidgetItem * getItem(int index);
    void removeItem(int index);
    void deleteAll();
    bool isEmpty();
    QListWidget * getList();
    QString getItemTitle(QListWidgetItem *item);
    int getItemCount();
    bool doubles(QString title);
    void putData(int id, QString *title, QString *text, QListWidgetItem *item);
    ListItem getData(QListWidgetItem *item);
    void edit(ListItem prev, ListItem nw);

    [[deprecated("only for testing")]]
    void addItems(QStringList stringList);
};


#endif //NOTES_LISTITERACTIONS_H
