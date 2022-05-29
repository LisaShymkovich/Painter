#ifndef FIGURE_H
#define FIGURE_H

#include <QColor>
#include <QPainter>
#include <cmath>

class Figure
{
public:
    Figure(QColor  color, int width) : color(std::move(color)), pen_width(width) {}
    virtual void Draw(QPainter& painter) = 0;
    virtual ~Figure() = default;

    QColor GetColor() const
    {
        return color;
    }

    int GetPenWidth() const
    {
        return pen_width;
    }

protected:
    QColor color;
    int pen_width;
    const double xr = 16;
    const double yr = 9;
};


#endif // FIGURE_H
