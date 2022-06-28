#ifndef TEXTLOADWIDGET_H
#define TEXTLOADWIDGET_H

#include <QWidget>
//#include <DSpinner>
#include <QLabel>

//DWIDGET_USE_NAMESPACE
class QVBoxLayout;

class TextLoadWidget : public QWidget
{
    Q_OBJECT
public:
    TextLoadWidget(QWidget *parent = nullptr);
private :
//    DSpinner *m_spinner{nullptr};
    QVBoxLayout *m_vboxLayout{nullptr};
    QLabel *m_label{nullptr};
};

#endif // TEXTLOADWIDGET_H
