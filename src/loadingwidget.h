#ifndef LOADINGWIDGET_H
#define LOADINGWIDGET_H

#include <QLabel>

class loadingWidget : public QLabel
{
    Q_OBJECT
public:
    loadingWidget(QWidget *parent = nullptr);
signals:
    void sigChangeSize();
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // LOADINGWIDGET_H
