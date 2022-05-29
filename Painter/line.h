#ifndef LINE_H
#define LINE_H

#include <QColor>
#include <QPainter>
#include <cmath>
#include "figure.h"

class Line : public Figure
{
public:
    Line(QColor color, int width, double x1, double y1, double x2, double y2)
        : Figure(std::move(color), width), x1(x1), y1(y1), x2(x2), y2(y2) {}

    void Draw(QPainter& painter) override;

private:
    double x1, y1, x2, y2;
};
#endif // LINE_H
