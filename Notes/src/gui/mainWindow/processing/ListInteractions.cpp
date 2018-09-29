/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#include "ListInteractions.h"

using namespace std;

ListInteractions::ListInteractions(QListWidget *_list)
{
    ListInteractions::list = _list;
}

void ListInteractions::addItem(QListWidgetItem *item)
{
    if (doubles(getItemTitle(item)))
        throw IllegalStateException();

    item->setWhatsThis(QString::number(getItemCount()));
    list->addItem(item);
}

void ListInteractions::addItems(vector<QListWidgetItem *> *items)
{

}

void ListInteractions::addItems(QStringList stringList)
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

QListWidgetItem * ListInteractions::getItem(int index)
{
    return list->item(index);
}

void ListInteractions::removeItem(int index)
{

}

void ListInteractions::deleteAll()
{

}

bool ListInteractions::isEmpty()
{
    return !getItemCount();
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

QString ListInteractions::getItemTitle(QListWidgetItem *item)
{
    return item->text();
}

int ListInteractions::getItemCount()
{
    return list->count();
}

bool ListInteractions::doubles(QString title)
{
//    QString t = *title;
//    QString &ti = t;

    for (int i = 0; i < getItemCount(); i++) {
        if (QString::compare(getItemTitle(getItem(i)), title, Qt::CaseInsensitive) == 0)
            return true;
    }

    return false;
}

ListInteractions::~ListInteractions() = default;
