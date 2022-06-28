#include "controlwidget.h"
#include <QFileDialog>
#include "ocrapplication.h"
ControlWidget::ControlWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout =new QVBoxLayout(this);
    this->setLayout(layout);
    m_openImageBtn =new QPushButton(tr("open Image"));
    layout->addWidget(m_openImageBtn);
    connect(m_openImageBtn,&QPushButton::clicked,this,[=]{
        QString path = QFileDialog::getOpenFileName();
        OcrApplication::instance()->openFile(path);
    });
}
