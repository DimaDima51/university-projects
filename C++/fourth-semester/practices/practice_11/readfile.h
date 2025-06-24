#ifndef READFILE_H
#define READFILE_H

#include "qtextedit.h"
#include <QThread>
#include <QProgressBar>
#include <QPushButton>
#include <QString>

class ReadFile : public QThread
{
    Q_OBJECT

public:
    // передаём путь к файлу, указатель на ProgressBar и на кнопку OK
    ReadFile(const QString &fileName, QProgressBar *pb, QPushButton *btn, QTextEdit *log, QObject *parent = nullptr);

protected:
    void run() override;

private:
    QString fileName;
    QProgressBar *progressBar;
    QPushButton *buttonOK;
    QTextEdit *logEdit;
};

#endif // READFILE_H
