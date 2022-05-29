#include "circle.h"

void Circle::Draw(QPainter& painter)
{
    int window_width = painter.window().width();
    int window_height = painter.window().height();
    painter.drawEllipse(x / xr * window_width,
                        y / yr * window_height,
                        width / xr * window_width,
                        height / yr * window_height);
}
