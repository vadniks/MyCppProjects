/*************************************************
 **  Created by Vad Nik on 05-Oct-18.
 *************************************************/

#include "SQLInteractions.h"

//SQLInteractions::SQLInteractions() = default;
//{
////    if (!createConnection())
////        throw -1;
////
////    if (!createDB())
////        throw -2;
//
//    //if (!hasCreated())
//        createConnection();
//    createDB();
//}

vector<ListItem> SQLInteractions::loadItems()
{
    vector<ListItem> vector;

    QSqlQuery query;
    QString str = "SELECT data FROM " + QString::asprintf(DB_NAME);
    bool s = query.exec(str);

    if (!s)
        return vector;

    while (query.next())
        vector.push_back(fromByteArray(query.value(1).toByteArray()));

//    int count = getItemCount();

//    if (count == 0)
//        return vector;

    //vector.reserve(count);
//    for (int i = 0; i < count; i++)
//        vector.push_back(getItem(i));

    return vector;
}

bool SQLInteractions::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase(DB_TYPE);
    db.setDatabaseName(QString::asprintf("./") + QString::asprintf(DB_NAME) + QString::asprintf(".db"));
    db.setUserName(DB_USER_NAME);
    db.setHostName(DB_HOST_NAME);
    db.setPassword(DB_PASSWORD);

    //this->db = db;
    return db.open();//this->db.open();
}

bool SQLInteractions::putItem(ListItem item)
{
    QSqlQuery query;
    QString str = "INSERT INTO " + QString::asprintf(DB_NAME) + " (id, data) VALUES(?, ?)";
    query.prepare(str);
    query.bindValue(0, item.getId());
    query.bindValue(1, toByteArray(item));

    return query.exec();
}

bool SQLInteractions::createDB()
{
    QSqlQuery query;
    QString str = "CREATE TABLE IF NOT EXISTS " + QString::asprintf(DB_NAME) + " (" +
                      "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," +
                      "data BLOB" +
                  ")";
    return query.exec(str);
}

//TODO: update ListItem that stored in db when user edits and deletes items.

QByteArray SQLInteractions::toByteArray(ListItem &item)
{
    QJsonObject obj;
    obj[DB_ID] = item.getId();
    obj[DB_TITLE] = *item.getTitle();
    obj[DB_TEXT] = *item.getText();

    qDebug() << *item.getTitle();

    QJsonDocument doc(obj);
    return doc.toJson();
}

ListItem SQLInteractions::fromByteArray(QByteArray arr)
{
    QJsonObject obj = QJsonDocument::fromJson(arr).object();
    int id = obj[DB_ID].toInt();
    QString title = obj[DB_TITLE].toString();
    QString text = obj[DB_TEXT].toString();

    qDebug() << title;

    return ListItem(id, title, text);
}

ListItem SQLInteractions::getItem(int id)
{
    QSqlQuery query;
    QString str = "SELECT data FROM " + QString::asprintf(DB_NAME) + " WHERE id = ?";
    query.prepare(str);
    query.bindValue(0, id);
    bool s = query.exec();

    if (!s)
        return ListItem();

    QSqlRecord rec = query.record();
    QByteArray arr;

//    while (query.next())
//        arr = query.value(rec.indexOf(DB_ID)).toByteArray();

    if (query.first())
        arr = query.value(rec.indexOf(DB_ID)).toByteArray();

    return fromByteArray(arr);
}

bool SQLInteractions::updateItem(int id, ListItem nw)
{
    QSqlQuery query;
    QString str = "UPDATE " + QString::asprintf(DB_NAME) + " SET data = ? WHERE id = ?";
    query.prepare(str);
    query.bindValue(0, toByteArray(nw));
    query.bindValue(1, id);
    return query.exec();
}

int SQLInteractions::getItemCount()
{
    QSqlQuery query;
    QString str = "SELECT * FROM " + QString::asprintf(DB_NAME);
    bool s = query.exec(str);

    if (!s)
        return -1;

    int count = 0;
    while (query.next())
        count++;

    return count;
}

bool SQLInteractions::deleteItem(int id)
{
    QSqlQuery query;
    QString str = "DELETE FROM " + QString::asprintf(DB_NAME) + " WHERE id = ?";
    query.prepare(str);
    query.bindValue(0, id);

    return query.exec();
}

bool SQLInteractions::hasCreated()
{
    if (FILE *file = fopen(DB_FILE_NAME, "r"))
    {
        fclose(file);
        return true;
    }
    return false;
}

void SQLInteractions::init()
{
    createConnection();
    createDB();
}

//SQLInteractions::~SQLInteractions() = default;
//{
//    this->db.close();
//}
