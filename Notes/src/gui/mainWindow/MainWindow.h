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

    void Execute();

public slots:
    void onItemClicked(QListWidgetItem *item);

private:
    QListWidget * makeList();
};


#endif //NOTES_MAINWINDOW_H
