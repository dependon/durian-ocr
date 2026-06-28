#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QDebug>
#include "paddleocr-ncnn/paddleocr.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 测试模型文件路径
    qDebug() << "Testing model file paths...";

    PaddleOCRApp *ocr = PaddleOCRApp::instance();

    QMainWindow window;
    QPushButton button("Test OCR");
    button.setParent(&window);

    QObject::connect(&button, &QPushButton::clicked, [&]() {
        qDebug() << "OCR Test clicked";
    });

    window.show();

    return app.exec();
}