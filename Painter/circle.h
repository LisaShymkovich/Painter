#ifndef CIRCLE_H
#define CIRCLE_H

#include <QColor>
#include <QPainter>
#include <cmath>
#include "figure.h"

class Circle : public Figure
{
public:
    Circle(QColor color, int pen_width, double x, double y, double w, double h)
        : Figure(std::move(color), pen_width), x(x), y(y), width(w), height(h) {}

    void Draw(QPainter& painter) override;
private:
    double x, y, width, height;
};


#endif // CIRCLE_H
