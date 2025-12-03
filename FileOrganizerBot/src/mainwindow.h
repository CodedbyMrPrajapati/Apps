#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "sidebar.h"
class MainWindow : public QMainWindow {
    Q_OBJECT
public :
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};