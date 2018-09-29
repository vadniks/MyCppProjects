/*************************************************
 **  Created by Vad Nik on 24-Sep-18.
 *************************************************/

#include "MainWindow.h"

MainWindow::MainWindow() = default;

MainWindow::~MainWindow() = default;

void MainWindow::Execute()
{
    QWidget *center = new QWidget(this);

    auto *layout = new QVBoxLayout(center);
    layout->addWidget(makeList());
    layout->addWidget(makeCreateBt());

    setCentralWidget(center);
    show();
}

void MainWindow::onItemClicked(QListWidgetItem *item)
{
    int index = inters->getItemIndex(*item);

    //TODO: test.
    QMessageBox msg(this);
    msg.setWindowTitle(QString::number(index));
    msg.setText(item->text());
    msg.exec();
}

QListWidget * MainWindow::makeList()
{
    auto *list = new QListWidget(this);
    list->resize(MAIN_LIST_W, MAIN_LIST_H);
    list->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);

    QFont font = list->font();
    font.setPointSize(DEF_FONT_SIZE);

    list->setFont(font);

    //TODO: add SQL reading and loading from to list.
    QStringList sList;
    sList << "Item 1" << "Item 2";

    auto *inters = new ListInteractions(list);
    inters->addItems(sList);
    this->inters = inters;

    QObject::connect(list, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(onItemClicked(QListWidgetItem *)));

    list->show();

    return list;
}

QPushButton *MainWindow::makeCreateBt()
{
    auto *button = new QPushButton(this);
    button->setText(MAIN_CREATE_BUTTON_TEXT);

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(onCreateClicked()));

    return button;
}

void MainWindow::onCreateClicked()
{
    auto *crWin = new CreateWindow(this);
    crWin->resize(DEF_WIN_W, DEF_WIN_H);
    crWin->setWindowTitle(CREATE_WIN_TITLE);
    crWin->show();
}

void MainWindow::updateList()
{

}

void MainWindow::addToList(QListWidgetItem *item)
{
    inters->addItem(item);
}
