/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#ifndef NOTES_LISTITERACTIONS_H
#define NOTES_LISTITERACTIONS_H

#include <QListWidget>
#include <QListWidgetItem>
#include <vector>
#include <QStringList>
#include "../../../util/consts.h"
#include "../../../util/IllegalStateException.h"

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
    void addItem(QListWidgetItem *item);
    void addItems(vector<QListWidgetItem *> *items);
    void addItems(QStringList stringList);
    int getItemIndex(QListWidgetItem &item);
    QListWidgetItem * getItem(int index);
    void removeItem(int index);
    void deleteAll();
    bool isEmpty();
    QListWidget * getList();
    QString getItemTitle(QListWidgetItem *item);
    int getItemCount();
    bool doubles(QString title);
};


#endif //NOTES_LISTITERACTIONS_H
