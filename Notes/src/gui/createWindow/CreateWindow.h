/*************************************************
 **  Created by Vad Nik on 26-Sep-18.
 *************************************************/

#ifndef NOTES_CREATEWINDOW_H
#define NOTES_CREATEWINDOW_H

#include "include.h"
#include <QLineEdit>
#include <QTextEdit>

typedef QWidget* QWidgetPtr;

class CreateWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateWindow(QMainWindow *parent);
    ~CreateWindow() override;

public:
    static QWidgetPtr toQWidgetPtr(QWidget *w);

public slots:
    void onDoneClicked();
    void onCancelClicked();
    void onTitleChanged(QLineEdit *title);
    void onTextChanged(QTextEdit *text);

private:
    template<typename ...QWidgetPtr>
    QVBoxLayout * makeMainLayout(QWidgetPtr... children);
    QHBoxLayout * makeButtonBar();
    QVBoxLayout * makeTextBar();
    QListWidgetItem * createItem(QString *title, QString *text);
};


#endif //NOTES_CREATEWINDOW_H
