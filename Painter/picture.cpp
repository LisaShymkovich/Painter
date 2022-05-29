#include "picture.h"

void Picture::Draw(QPainter& painter)
{
    int window_width = painter.window().width();
    int window_height = painter.window().height();
    painter.drawPixmap(x / xr * window_width,
                       y / yr * window_height,
                       width / xr * window_width,
                       height / yr * window_height, pixmap);
}
