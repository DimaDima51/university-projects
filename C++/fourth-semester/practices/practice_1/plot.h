#ifndef PLOT_H
#define PLOT_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QObject>
#include <QPen>
#include <QSlider>
#include "./ui_mainwindow.h"
#include "readfile.h"
#include <algorithm>

#include <QDebug>

class Plot {

    private:
        int currentSegment;

    public:
        //конструктор
        Plot() : currentSegment(0) { }
        //деструктор
        ~Plot() { }

        void draw(Ui::MainWindow &ui, ReadFile &ReadF)
        {
            int zoom = ui.verticalSlider->sliderPosition();
            int dataSize = ReadF.getCount();

            if (currentSegment * zoom >= dataSize) {
                currentSegment = dataSize / zoom;
            }

            int startIdx = currentSegment * zoom;
            int endIdx = std::min(startIdx + zoom, dataSize);

            QGraphicsScene *scene = new QGraphicsScene(ui.graphicsView);
            ui.graphicsView->setScene(scene);

            QColor color = ui.comboBox->currentData().value<QColor>();
            QPen pen(color);

            QPen axisPen(Qt::green);

            // Инициализация переменных для хранения минимального и максимального значений
            double minVal = ReadF[startIdx];
            double maxVal = ReadF[startIdx];

            for (int i = startIdx + 1; i < endIdx; ++i) {
                scene->addLine(i - startIdx - 1, ReadF[i - 1] % zoom, i - startIdx, ReadF[i] % zoom, pen);

                if (ReadF[i] < minVal) {
                    minVal = ReadF[i];
                }

                if (ReadF[i] > maxVal) {
                    maxVal = ReadF[i];
                }
            }
            ui.graphicsView->setScene(scene);
        }

        void nextSegment(Ui::MainWindow &ui, ReadFile &ReadF) {
            int zoom = ui.label->text().toInt();
            if ((currentSegment + 1) * zoom < ReadF.getCount()) {
                ++currentSegment;
                draw(ui, ReadF);
            }
        }

        void prevSegment(Ui::MainWindow &ui, ReadFile &ReadF) {
            if (currentSegment > 0) {
                --currentSegment;
                draw(ui, ReadF);
            }
        }

        void setPenColor(const QColor &color);
};

#endif // PLOT_H
