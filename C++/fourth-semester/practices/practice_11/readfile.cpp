#include "ReadFile.h"
#include <QFile>
#include <QDataStream>
#include <QDebug>

ReadFile::ReadFile(const QString &fileName, QProgressBar *pb, QPushButton *btn, QTextEdit *log, QObject *parent)
    : QThread(parent),
    fileName(fileName),
    progressBar(pb),
    buttonOK(btn),
    logEdit(log)
{}


void ReadFile::run()
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Невозможно открыть файл:" << fileName;
        QMetaObject::invokeMethod(buttonOK, "setEnabled", Qt::QueuedConnection, Q_ARG(bool, true));
        return;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_2_0);
    stream.setByteOrder(QDataStream::LittleEndian);

    qint64 totalBytes = file.size();
    const qint64 intSize = sizeof(qint32);
    qint64 totalInts = totalBytes / intSize;
    if (totalInts <= 0) {
        file.close();
        QMetaObject::invokeMethod(buttonOK, "setEnabled", Qt::QueuedConnection, Q_ARG(bool, true));
        return;
    }

    // шаг в элементах для 1%
    qint64 step = totalInts / 100;
    if (step == 0) step = 1;

    for (qint64 i = 0; i < totalInts; ++i) {
        qint32 value;
        stream >> value;

        QString logMessage = QString("%1) Значение: %2").arg(i + 1).arg(value);

        if (value < 0) {
            file.seek(file.pos() - intSize);
            stream << static_cast<qint32>(0);
            logMessage += " (меняем на 0)";
        }

        QMetaObject::invokeMethod(logEdit, "setText", Qt::QueuedConnection, Q_ARG(QString, logMessage));

        if (i % step == 0) {
            int pct = static_cast<int>((i * 100) / totalInts);
            QMetaObject::invokeMethod(progressBar, "setValue", Qt::QueuedConnection, Q_ARG(int, pct));
        }

        if (i % 100 == 0) {
            QThread::msleep(10);
        }
    }


    QMetaObject::invokeMethod(progressBar, "setValue", Qt::QueuedConnection, Q_ARG(int, 100));
    file.close();

    // включаем кнопку обратно
    QMetaObject::invokeMethod(buttonOK, "setEnabled", Qt::QueuedConnection, Q_ARG(bool, true));

}
