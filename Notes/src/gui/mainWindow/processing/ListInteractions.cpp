/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#include "ListInteractions.h"

using namespace std;

ListInteractions::ListInteractions(QListWidget *_list)
{
    ListInteractions::list = _list;
}

void ListInteractions::addItem(QString title, QString text)
{
    if (doubles(title))
        throw IllegalStateException();

    auto *item = new QListWidgetItem(title, list);
    putData(getItemCount()-1, title, text, item);
    //item->setWhatsThis(QString::number(getItemCount()));
    list->addItem(item);
}

void ListInteractions::addItems(vector<ListItem> items)
{
    for (auto &item : items)
    {
        ListItem i = (ListItem) item;
        addItem(*i.getTitle(), *i.getText());
    }
}

void ListInteractions::addItems(QStringList stringList)
{
    int i = 0;
    foreach(QString s, stringList)
    {
        QListWidgetItem *ptr = nullptr;
        ptr = new QListWidgetItem(s, this->list);
        putData(i, s, QString::asprintf("<none>"), ptr);
        i++;
    }
}

QListWidgetItem * ListInteractions::getItem(int index)
{
    return list->item(index);
}

void ListInteractions::removeItem(int index)
{
    //list->removeItemWidget(getItem(index));

//    QTextStream out(stdout);
//    out << QString::number(index) << " " << QString::number(getItemCount()) << endl;

    delete getItem(index);

    updateItems();
}

void ListInteractions::deleteAll()
{
    for (int i = 0; i < getItemCount(); i++)
        removeItem(i);
}

bool ListInteractions::isEmpty()
{
    return !getItemCount();
}

int ListInteractions::getItemIndex(QListWidgetItem &item)
{
//    QString index = item.whatsThis();
//    bool successful;
//    int idx = index.toInt(&successful);
//
//    if (successful)
//        return idx;

    return getData(&item).getId();
}

QListWidget *ListInteractions::getList()
{
    return this->list;
}

QString ListInteractions::getItemTitle(QListWidgetItem *item)
{
    return *getData(item).getTitle();
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

void ListInteractions::putData(int id, QString title, QString text, QListWidgetItem *item)
{
//    QTextStream out(stdout);
//    out << id << " " << *title << " " << *text << endl;

    QJsonObject obj;
    obj[CREATE_ID_NAME] = id;
    obj[CREATE_TITLE_NAME] = title;
    obj[CREATE_TEXT_NAME] = text;

    QJsonDocument doc(obj);

//    ListItem i(id, *title, *text);
//    QVariant data(*i.toDataStream());
    auto *data = new QVariant(QVariant::Type::ByteArray);
    data->setValue<QByteArray>(doc.toJson());

//    if (data.canConvert<ListItem>()) {
//        data.setValue<ListItem>(i);
        item->setData(Qt::UserRole, *data);
//    }
}

ListItem ListInteractions::getData(QListWidgetItem *item)
{
    //return &ListItem::fromDataStream((QDataStream) item->data(Qt::UserRole).value());
    //return item->data(Qt::UserRole).value<ListItem>();

    QJsonObject obj = QJsonDocument::fromJson(item->data(Qt::UserRole).value<QByteArray>()).object();

    int id = obj[CREATE_ID_NAME].toInt(0);
    QString title = obj[CREATE_TITLE_NAME].toString();
    QString text = obj[CREATE_TEXT_NAME].toString();

//    QTextStream out(stdout);
//    out << item->text() << " " << id << " " << title << " " << text << obj.isEmpty() << endl;

    return ListItem(id, title, text);
}

void ListInteractions::edit(ListItem prev, ListItem nw)
{
//    if (doubles(*nw.getTitle()))
//        throw IllegalStateException(); //TODO: isn't necessary.

    QListWidgetItem *item = getItem(prev.getId());
    item->setText(*nw.getTitle());
    putData(prev.getId(), *nw.getTitle(), *nw.getText(), item);
}

int ListInteractions::getItemIndex(QString title)
{
    for (int i = 0; i < getItemCount(); i++) {
        if (QString::compare(getItem(i)->text(), title))
            return i;
    }
    return 0;
}

void ListInteractions::updateItems()
{
    for (int i = 0; i < getItemCount(); i++) {
        QListWidgetItem *item = getItem(i);
        putData(getItemIndex(item->text()), item->text(), *getData(item).getText(), item);
    }
}

ListInteractions::~ListInteractions() = default;
