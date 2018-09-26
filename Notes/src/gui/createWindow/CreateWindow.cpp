/*************************************************
 **  Created by Vad Nik on 26-Sep-18.
 *************************************************/

//#include "include.h" //TODO: remove all includings like this from all classes' sources.
#include "CreateWindow.h"

CreateWindow::CreateWindow(QMainWindow *parent)
{
    setParent(parent);

    QWidget *center = new QWidget(this);
}

template<typename... QWidgetPtr>
QVBoxLayout *CreateWindow::makeMainLayout(QWidgetPtr... children)
{


    return nullptr;
}

QHBoxLayout *CreateWindow::makeButtonBar()
{
    auto *btDone = new QPushButton(CREATE_DONE_BUTTON_TEXT, this);
    auto *btCreate = new QPushButton(CREATE_CANCEL_BUTTON_TEXT, this);

    QObject::connect(btDone, SIGNAL(clicked()), this, SLOT(onDoneClicked()));
    QObject::connect(btCreate, SIGNAL(clicked()), this, SLOT(onCancelClicked()));

    return nullptr;
}

QVBoxLayout *CreateWindow::makeTextBar()
{
    auto *titleT = new QLineEdit(this);
    titleT->setPlaceholderText(CREATE_TITLE_HINT);
    //titleT->setReadOnly(true);

    //QObject::connect(titleT, SIGNAL())

    return nullptr;
}

QWidgetPtr CreateWindow::toQWidgetPtr(QWidget * w)
{
    return w;
}

void CreateWindow::onDoneClicked()
{
    //((MainWindow *) parentWidget())->addToList(createItem());
}

void CreateWindow::onCancelClicked()
{
    this->close();
}

QListWidgetItem *CreateWindow::createItem(QString *title, QString *text)
{
    auto *item = new QListWidgetItem(title + QString(" : ") + text);
    return item;
}

void CreateWindow::onTitleChanged(QLineEdit *title)
{

}

void CreateWindow::onTextChanged(QTextEdit *text)
{

}

CreateWindow::~CreateWindow() = default;
