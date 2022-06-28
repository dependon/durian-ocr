#include "loadingwidget.h"

loadingWidget::loadingWidget(QWidget *parent)
    : QLabel(parent)
{

}

void loadingWidget::resizeEvent(QResizeEvent *event)
{
    emit sigChangeSize();
    return QLabel::resizeEvent(event);
}
