#include "mainwindow.h"
#include "sidebar.h"
#include "jsonDirectoryPage.hpp"
#include <QPushButton>
#include <QDebug>
#include <QStackedWidget>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
    setAttribute(Qt::WA_TranslucentBackground);
    QWidget *central = new QWidget(this);
    setCentralWidget(central);
    QHBoxLayout *layout = new QHBoxLayout(central);
    layout->setContentsMargins(8,8,8,8);
    layout->setSpacing(2);

    Sidebar *leftPanel = new Sidebar(central);

    QStackedWidget *rightPanel= new QStackedWidget(central);
    rightPanel->setObjectName("rightPanel");

    layout->addWidget(leftPanel,1);
    layout->addWidget(rightPanel,1);

    JsonDirectoryPage *page1 = new JsonDirectoryPage();
    page1->setStyleSheet("background: rgba(100,0,200,0.2);");

    QWidget *page2 = new QWidget();
    page2->setStyleSheet("background: rgba(0,200,200,0.2);");

    QWidget *page3 = new QWidget();
    page2->setStyleSheet("background: rgba(0,0,200,0.2);");
    rightPanel->addWidget(page1);
    rightPanel->addWidget(page2);
    rightPanel->addWidget(page3);

    int totalItems = leftPanel->items.size();
    for(int idx=0;idx<totalItems;idx++){
        connect(leftPanel->items[idx],&MenuItem::clicked,this,[rightPanel,idx](){rightPanel->setCurrentIndex(idx);});
    }
}

MainWindow::~MainWindow(){}