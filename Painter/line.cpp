#include "line.h"

void Line::Draw(QPainter& painter)
{
    int window_width = painter.window().width();
    int window_height = painter.window().height();
    painter.drawLine(x1 / xr * window_width,
                     y1 / yr * window_height,
                     x2 / xr * window_width,
                     y2 / yr * window_height);
}
