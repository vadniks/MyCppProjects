/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#ifndef NOTES_MAINWINDOW_H //TODO: unterminated conditional directive.
#define NOTES_MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStringList>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include "processing/ListInteractions.h"
#include "../../util/consts.h"
#include "../createWindow/CreateWindow.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

private:
    ListInteractions *inters;

public:
    MainWindow();
    ~MainWindow() override;

public:
    void Execute();
    void addToList(QString title, QString text); //TODO: add writing to SQL in this function.

    [[deprecated("useless, directly add-remove operations do the trick")]]
    void updateList();

public slots:
    void onItemClicked(QListWidgetItem *item);
    void onCreateClicked();

private:
    QListWidget * makeList();
    QPushButton * makeCreateBt();
};


#endif //NOTES_MAINWINDOW_H
