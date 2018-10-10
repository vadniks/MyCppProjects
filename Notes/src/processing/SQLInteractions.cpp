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
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    vector<ListItem> vector;

    QSqlQuery query(SQLInteractions::db);
    QString str = "SELECT data FROM " + QString::asprintf(DB_NAME);
    bool s = query.exec(str);

    SQLInteractions::db.close();

    if (!s)
        return vector;

    QSqlRecord rec = query.record();

    while (query.next())
        vector.push_back(fromByteArray(query.value(rec.indexOf("data")).toByteArray()));

//    int count = getItemCount();

//    if (count == 0)
//        return vector;

    //vector.reserve(count);
//    for (int i = 0; i < count; i++)
//        vector.push_back(getItem(i));

    return vector;
}

QSqlDatabase SQLInteractions::db;

bool SQLInteractions::createConnection()
{
    SQLInteractions::db = QSqlDatabase::addDatabase(DB_TYPE);
    SQLInteractions::db.setDatabaseName(QString::asprintf("./") + QString::asprintf(DB_NAME) + QString::asprintf(".db"));
    SQLInteractions::db.setUserName(DB_USER_NAME);
    SQLInteractions::db.setHostName(DB_HOST_NAME);
    SQLInteractions::db.setPassword(DB_PASSWORD);

    return SQLInteractions::db.open();
}

bool SQLInteractions::putItem(ListItem item)
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "INSERT INTO " + QString::asprintf(DB_NAME) + " (id, data) VALUES(?, ?)";
    query.prepare(str);
    query.addBindValue(item.getId());
    query.addBindValue(toByteArray(item), QSql::In | QSql::Binary);

    bool s = query.exec();

    db.close();

    return s;
}

bool SQLInteractions::createDB()
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "CREATE TABLE IF NOT EXISTS " + QString::asprintf(DB_NAME) + " (" +
                      "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," +
                      "data BLOB NOT NULL" +
                  ")";

    bool s = query.exec(str);
    SQLInteractions::db.close();
    return s;
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
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "SELECT data FROM " + QString::asprintf(DB_NAME) + " WHERE id = ?";
    query.prepare(str);
    query.addBindValue(id);
    bool s = query.exec();

    SQLInteractions::db.close();

    if (!s)
        return ListItem();

    QSqlRecord rec = query.record();
    QByteArray arr;

//    while (query.next())
//        arr = query.value(rec.indexOf(DB_ID)).toByteArray();

    if (query.first())
        arr = query.value(rec.indexOf("data")).toByteArray();

    return fromByteArray(arr);
}

bool SQLInteractions::updateItem(int id, ListItem nw)
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "UPDATE " + QString::asprintf(DB_NAME) + " SET data = ? WHERE id = ?";
    query.prepare(str);
    query.addBindValue(toByteArray(nw), QSql::In | QSql::Binary);
    query.addBindValue(id);

    bool s = query.exec();
    SQLInteractions::db.close();
    return s;
}

int SQLInteractions::getItemCount()
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "SELECT * FROM " + QString::asprintf(DB_NAME);
    bool s = query.exec(str);

    SQLInteractions::db.close();

    if (!s)
        return -1;

    int count = 0;
    while (query.next())
        count++;

    return count;
}

bool SQLInteractions::deleteItem(int id)
{
    if (!SQLInteractions::db.isOpen())
        SQLInteractions::db.open();

    QSqlQuery query(SQLInteractions::db);
    QString str = "DELETE FROM " + QString::asprintf(DB_NAME) + " WHERE id = ?";
    query.prepare(str);
    query.addBindValue(id);

    bool s = query.exec();
    SQLInteractions::db.close();
    return s;
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
