#pragma once
#include <QtGlobal>
#include <QWidget>
#include <QLabel>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
class MenuItem : public QWidget {
    Q_OBJECT
    Q_PROPERTY(qreal hoverScale READ hoverScale WRITE setHoverScale)
    public : 
        MenuItem(const  QString &IconPath,const QString& LabelText , QWidget *parent = nullptr) ;
        void updateForSidebarWidth(int w, int collapsedW, int expandedW);
        qreal hoverScale() const { return m_hoverScale; };
        void setHoverScale(qreal s);
        bool isSelected = true;
        void setSelected(bool State);
    protected:
        void enterEvent(QEnterEvent *event) override;
        void leaveEvent(QEvent *event) override;
        void mousePressEvent(QMouseEvent *event) override;
    private:
        QLabel *iconLabel;
        QLabel *textLabel;
        QWidget *textWrapper;
        QGraphicsOpacityEffect *opacityEffect;
        int fullTextWidth;
        bool isHovered = false;
        qreal m_hoverScale;
        QPropertyAnimation *hoverAnim = nullptr;
    signals:
        void clicked(MenuItem *item);
};