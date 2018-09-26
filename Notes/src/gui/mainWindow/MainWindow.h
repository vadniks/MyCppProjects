/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#ifndef NOTES_MAINWINDOW_H
#define NOTES_MAINWINDOW_H

#include "include.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow() override;

public:
    void Execute();
    void updateList();
    void addToList(QListWidgetItem * item); //TODO: add writing to SQL in this function.

public slots:
    void onItemClicked(QListWidgetItem *item);
    void onCreateClicked();

private:
    QListWidget * makeList();
    QPushButton * makeCreateBt();
};


#endif //NOTES_MAINWINDOW_H
