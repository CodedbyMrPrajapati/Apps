#include "menuItem.hpp"
#include <QHBoxLayout>
#include <QStyle>
MenuItem::MenuItem(const QString &IconPath, const QString &LabelText, QWidget *parent) : QWidget(parent) , m_hoverScale(1.0)
{
    setFixedHeight(40);
    setAttribute(Qt::WA_StyledBackground, true);

    QBoxLayout *hl = new QHBoxLayout(this);
    hl->setContentsMargins(2,2,2,2);
    hl->setSpacing(5);

    iconLabel = new QLabel(this);
    iconLabel->setPixmap(QPixmap(IconPath).scaled(24,24,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    iconLabel->setFixedSize(24, 24);

    textLabel = new QLabel(LabelText,this);
    textLabel->setStyleSheet("color: gray;");
    textLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    opacityEffect = new QGraphicsOpacityEffect(this);
    opacityEffect->setOpacity(0.0);
    textLabel->setGraphicsEffect(opacityEffect);

    textWrapper = new QWidget(this);
    QHBoxLayout *wrapLayout = new QHBoxLayout(textWrapper);
    wrapLayout->setContentsMargins(0,0,0,0);
    wrapLayout->addWidget(textLabel);
    textWrapper->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    
    
    hl->addWidget(iconLabel);
    hl->addWidget(textWrapper);
    hl->addStretch();
    
    fullTextWidth = textLabel->sizeHint().width();
    textWrapper->setFixedWidth(0);

    hoverAnim = new QPropertyAnimation(this, "hoverScale");
    hoverAnim->setDuration(120);
    hoverAnim->setEasingCurve(QEasingCurve::InOutQuad);

}
void MenuItem::updateForSidebarWidth(int w, int collapsedW, int expandedW)
{
    double t = double(w - collapsedW) / double(expandedW - collapsedW);
    if (t < 0) t = 0;
    if (t > 1) t = 1;

    // Opacity
    opacityEffect->setOpacity(t);

    // Reveal width (grow wrapper)
    int revealWidth = int(fullTextWidth * t);
    textWrapper->setFixedWidth(revealWidth);

    // Slide-in via left margin
    int slideOffset = int((1.0 - t) * 20);   // 20px slide
    static_cast<QHBoxLayout*>(textWrapper->layout())->setContentsMargins(slideOffset, 0, 0, 0);
}

void MenuItem::setHoverScale(qreal s)
{
    m_hoverScale = s;
    qreal t = (m_hoverScale - 1.0) / 0.02;

    // 1) Icon scaling
    int newSize = int(24 + t *1.2);
    iconLabel->setFixedSize(newSize, newSize);

    int margin =int( 6 + t*1.2);
    static_cast<QHBoxLayout*>(layout())->setContentsMargins(margin, 2, margin, 2);

    // 3) Text brightness (map hoverScale 1.0->1.02 into 0->1 opacity)
    if (t < 0) t = 0;
    if (t > 1) t = 1;
    textLabel->setStyleSheet(QString("color: rgba(255,255,255,%1);").arg(t/2 + 0.5));

    update();
}
void MenuItem::enterEvent(QEnterEvent *event)
{
    hoverAnim->stop();
    hoverAnim->setStartValue(m_hoverScale);
    hoverAnim->setEndValue(1.02);
    hoverAnim->start();
}
void MenuItem::leaveEvent(QEvent *event)
{
    hoverAnim->stop();
    hoverAnim->setStartValue(m_hoverScale);
    hoverAnim->setEndValue(1.00);
    hoverAnim->start();
}
void MenuItem::mousePressEvent(QMouseEvent *event)
{
    emit clicked(this);
    QWidget::mousePressEvent(event);
}
void MenuItem::setSelected(bool state)
{
    isSelected = state;
    setProperty("selected", state);
    style()->unpolish(this);
    style()->polish(this);
    update();
}