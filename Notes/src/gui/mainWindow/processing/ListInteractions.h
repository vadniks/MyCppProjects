/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#ifndef NOTES_LISTITERACTIONS_H
#define NOTES_LISTITERACTIONS_H

#include "include.h"

using namespace std;

class ListInteractions
{

private:
    QListWidget *list;
    vector<QListWidgetItem> items;

public:
    explicit ListInteractions(QListWidget *list);

    ~ListInteractions();

    void addItem(const QListWidgetItem *item);
    void addItems(const vector<QListWidgetItem *> *items);
    void addItems(const QStringList stringList);
    static int getItemIndex(QListWidgetItem &item);
    QListWidgetItem * getIttem(int index);
    void removeItem(int index);
    void deleteAll();
    bool isEmpty();
    QListWidget * getList();
};


#endif //NOTES_LISTITERACTIONS_H
