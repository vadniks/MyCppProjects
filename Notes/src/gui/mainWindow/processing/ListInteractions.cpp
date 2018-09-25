/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#include "include.h"
#include "ListInteractions.h"

using namespace std;

ListInteractions::ListInteractions(QListWidget *_list)
{
    ListInteractions::list = _list;
}

void ListInteractions::addItem(const QListWidgetItem *item)
{

}

void ListInteractions::addItems(const vector<QListWidgetItem *> *items)
{

}

void ListInteractions::addItems(const QStringList stringList)
{
    int i = 0;
    foreach(QString s, stringList)
    {
        QListWidgetItem *ptr = nullptr;
        ptr = new QListWidgetItem(s, this->list);

        ptr->setWhatsThis(QString::number(i));
        i++;
    }
}

QListWidgetItem * ListInteractions::getIttem(const int index)
{
    return nullptr;
}

void ListInteractions::removeItem(const int index)
{

}

void ListInteractions::deleteAll()
{

}

bool ListInteractions::isEmpty()
{
    return false;
}

int ListInteractions::getItemIndex(QListWidgetItem &item)
{
    QString index = item.whatsThis();
    bool successful;
    int idx = index.toInt(&successful);

    if (successful)
        return idx;

    return 0;
}

QListWidget *ListInteractions::getList()
{
    return this->list;
}

ListInteractions::~ListInteractions() = default;
