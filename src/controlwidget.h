#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
class ControlWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ControlWidget(QWidget *parent = nullptr);

signals:

public slots:


private :
    QPushButton *m_openImageBtn = nullptr;
};

#endif // CONTROLWIDGET_H
