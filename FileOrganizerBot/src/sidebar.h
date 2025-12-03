#pragma once 
#include <QWidget>
#include <QPropertyAnimation>
#include <QEnterEvent>
#include <vector>
#include "menuItem.hpp"
class Sidebar : public QWidget {
    Q_OBJECT
    public : 
        Sidebar(QWidget *parent = nullptr);
        std::vector<MenuItem*> items;
    protected:
        void enterEvent(QEnterEvent *event) override;
        void resizeEvent(QResizeEvent *event) override;
        void leaveEvent(QEvent *event) override;
    private:
        QPropertyAnimation *anim;
        void expand();
        void collapse();
        int collapsedWidth = 40;
        int expandedWidth = 120;
};
