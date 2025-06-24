#ifndef READFILE_H
#define READFILE_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QDataStream>

class ReadFile {
    private:
        int *m;
        int count_m = 0;
        QFile  *file;

        void read_stream(QDataStream &stream) {
            stream.setVersion(QDataStream::Qt_2_0);
            stream.setByteOrder(QDataStream::LittleEndian);

            int i = 0;
            int n;
            for (; !stream.atEnd(); ++i) {
                stream >> n;
                m[i] = n;
                count_m++;
            }
        }

    public:
        ReadFile(const QString fileN) {
            file = new QFile(fileN);
            count_m = file->size() / 4;
            m = new int[count_m];
        }

        ~ReadFile() {
            delete file;
            delete m;
        }

        void ReadF() {
            if (file->open(QIODevice::ReadOnly)) {
                QDataStream stream(file);
                read_stream(stream);
                file->close();
            }
        }

        int operator[](int i) {
            return m[i];
        }

        int getCount() {
            return count_m;
        }
};

#endif // READFILE_H
