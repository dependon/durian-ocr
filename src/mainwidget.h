#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QPlainTextEdit>
#include <QLabel>
//#include <QGuiApplicationHelper>
#include <QStackedWidget>
#include <QFrame>

#include <QMutex>

#include <QToolButton>

#include "resulttextview.h"

#include "textloadwidget.h"
#include "paddleocr-ncnn/paddleocr.h"

class Frame;
class QThread;
class QGridLayout;
class QHBoxLayout;
class ImageView;
class loadingWidget;
class QShortcut;

enum ColorType {
    DarkType,
    LightType
};

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void setupUi(QWidget *Widget);
    void setupConnect();
    void retranslateUi(QWidget *Widget);

    void createLoadingUi();
    void deleteLoadingUi();
    void loadingUi();
    //初始化快捷键
    void initShortcut();

    bool openImage(const QString &path);
    void openImage(const QImage &img, const QString &name = "");

    void loadHtml(const QString &html);
    void loadString(const QString &string);
    void resultEmpty();

    //缩放显示label
    void initScaleLabel();
protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
private slots:
    void setIcons(ColorType themeType);

    void slotCopy();
    void slotExport();

//    void change()
private:
    QGridLayout *m_mainGridLayout{nullptr};
    QHBoxLayout *m_horizontalLayout{nullptr};
    ResultTextView *m_plainTextEdit{nullptr};
    QHBoxLayout *m_buttonHorizontalLayout{nullptr};
    QHBoxLayout *m_tipHorizontalLayout{nullptr};
    QLabel *m_tiplabel{nullptr};
    QToolButton *m_copyBtn{nullptr};
    QToolButton *m_exportBtn{nullptr};
    ImageView *m_imageview{nullptr};

    QHBoxLayout *m_frameLayout{nullptr};
    QFrame *m_frame{nullptr};

    QHBoxLayout *m_frameStackLayout{nullptr};
    Frame *m_frameStack{nullptr};

    QLabel *m_tipIconLabel{nullptr};
//    QHorizontalLine *m_line{nullptr};

    QString m_imgName;  //当前图片绝对路径
    QWidget *m_pwidget{nullptr};
    TextLoadWidget *m_loadingWidget{nullptr};
    QLabel *m_loadingTip{nullptr};

    bool m_isLoading{false};

    QThread *m_loadImagethread{nullptr};
    QMutex m_mutex;
    QString m_result;
    QImage *m_currentImg{nullptr};

    QStackedWidget *m_resultWidget{nullptr};
    QLabel *m_noResult{nullptr};
    loadingWidget *m_loadingOcr{nullptr};
    QShortcut *m_scAddView = nullptr;
    QShortcut *m_scReduceView = nullptr;

    int m_isEndThread = 1;
signals:
    void sigResult(const QString &);

};

#endif // WIDGET_H
