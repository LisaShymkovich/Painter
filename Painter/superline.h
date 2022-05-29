#ifndef SUPERLINE_H
#define SUPERLINE_H

#include <QColor>
#include <QPainter>
#include <cmath>
#include "figure.h"

class SuperLine : public Figure
{
public:
    SuperLine(QColor color, int width, double x1, double y1, double x2, double y2)
        : Figure(std::move(color), width), points({{x1, y1}, {x2, y2}}) {}

    void AddPoint(const QPointF& point);
    void Draw(QPainter& painter) override;
private:
    std::vector<QPointF> points;
};




#endif // SUPERLINE_H
