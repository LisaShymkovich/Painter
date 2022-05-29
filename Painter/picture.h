#ifndef PICTURE_H
#define PICTURE_H
#include <QColor>
#include <QPainter>
#include <cmath>
#include "figure.h"

class Picture : public Figure
{
public:
    Picture(QColor color, int pen_width, double x, double y, double w, double h, const QPixmap& pixmap)
        : Figure(std::move(color), pen_width),
          x(std::min(x, x + w)), y(std::min(y, y + h)),
          width(fabs(w)), height(fabs(h)), pixmap(pixmap) {}
    void Draw(QPainter& painter) override;
private:
    double x, y, width, height;
    QPixmap pixmap;
};



#endif // PICTURE_H
