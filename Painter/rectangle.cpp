#include "rectangle.h"

void Rectangle::Draw(QPainter& painter)
{
    int window_width = painter.window().width();
    int window_height = painter.window().height();
    painter.drawRect(x / xr * window_width,
                     y / yr * window_height,
                     width / xr * window_width,
                     height / yr * window_height);
}
