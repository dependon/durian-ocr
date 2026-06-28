#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include "src/paddleocr-ncnn/paddleocr.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qDebug() << "Testing model file loading...";

    // 测试创建 PaddleOCRApp 实例
    PaddleOCRApp *ocr = PaddleOCRApp::instance();

    if (ocr) {
        qDebug() << "PaddleOCRApp instance created successfully";
    } else {
        qDebug() << "Failed to create PaddleOCRApp instance";
        return -1;
    }

    // 测试文件存在性
    qDebug() << "\nChecking model files:";

    QStringList modelFiles = {
        "../assets/model/det.param.bin",
        "../assets/model/det.bin",
        "../assets/model/rec_eng.param.bin",
        "../assets/model/rec_eng.bin"
    };

    for (const QString &file : modelFiles) {
        if (QFile::exists(file)) {
            qDebug() << "✓" << file << "exists";
        } else {
            qDebug() << "✗" << file << "does not exist";
        }
    }

    qDebug() << "\nTest completed";
    return 0;
}