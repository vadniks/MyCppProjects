/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#include <QApplication>
#include <QtCore>
#include "gui/mainWindow/MainWindow.h"
#include "util/consts.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow window;
    window.resize(MAIN_WIN_W, MAIN_WIN_H);
    window.setWindowTitle(MAIN_WIN_TITLE);
    //window.setWindowIcon(); TODO: add icon.
    window.Execute();

    return QApplication::exec();
}
