#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QColor>
#include <utility>
#include <QPainter>
#include <cmath>
#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(QColor color, int pen_width, double x, double y, double w, double h)
        : Figure(std::move(color), pen_width), x(x), y(y), width(w), height(h) {}

    void Draw(QPainter& painter) override;

private:
    double x, y, width, height;
};

#endif // RECTANGLE_H
