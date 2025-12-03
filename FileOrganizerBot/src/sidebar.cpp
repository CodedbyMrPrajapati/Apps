#include "sidebar.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QFile>
Sidebar::Sidebar(QWidget *parent) : QWidget(parent) {
    setObjectName("sidebar");
    setAttribute(Qt::WA_StyledBackground);
    QFile file("../styles/sidebar.qss");
    if (file.open(QFile::ReadOnly)){
        QString style = QLatin1String(file.readAll());
        this->setStyleSheet(style);
    } else {
        throw std::invalid_argument("Error Loading StyleSheet for sidebar");
    }

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    setMinimumWidth(collapsedWidth);
    setMaximumWidth(expandedWidth);

    QVBoxLayout *vl = new QVBoxLayout(this);
    vl->setContentsMargins(5, 5, 5, 5);
    vl->setSpacing(5);

    auto addItem = [&](const QString &iconPath,const QString& TextLabel){
        MenuItem *it = new MenuItem(iconPath,TextLabel);
        vl->addWidget(it);
        items.push_back(it);
        connect(it,&MenuItem::clicked,this,[this](MenuItem *clickedItem){
            for (MenuItem *it : items)
                it->setSelected(false);
            clickedItem->setSelected(true);
        });
    };

    addItem(":/Icons/A.png", "Dashboard");
    addItem(":/Icons/B.png", "Search");
    addItem(":/Icons/C.png", "Settings");

    vl->addStretch();

    anim = new QPropertyAnimation(this, "maximumWidth");
    anim->setDuration(200);
    anim->setEasingCurve(QEasingCurve::InOutQuad);
    items[0]->setSelected(true);
}

void Sidebar::expand(){
    anim->stop();
    anim->setStartValue(width());
    anim->setEndValue(expandedWidth);
    anim->start();
};


void Sidebar::collapse(){
    anim->stop();
    anim->setStartValue(width());
    anim->setEndValue(collapsedWidth);
    anim->start();
};
void Sidebar::enterEvent(QEnterEvent *event) {
    expand();
    QWidget::enterEvent(event);
}
void Sidebar::resizeEvent(QResizeEvent *event) {
    for (auto *it : items)
        it->updateForSidebarWidth(width(), collapsedWidth, expandedWidth);
    QWidget::resizeEvent(event);
};

void Sidebar::leaveEvent(QEvent *event){
    collapse();
    QWidget::leaveEvent(event);
};