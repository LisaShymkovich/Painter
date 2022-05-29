#include "superline.h"

void SuperLine::AddPoint(const QPointF& point)
{
    points.push_back(point);
}

void SuperLine::Draw(QPainter& painter)
{
    int window_width = painter.window().width();
    int window_height = painter.window().height();
    std::vector<QPoint> points_screen_coordinates;
    points_screen_coordinates.resize(points.size());
    for (int i = 0; i < points.size(); i++)
    {
        points_screen_coordinates[i] = QPoint(points[i].x() / xr * window_width,
                                              points[i].y() / yr * window_height);
    }
    painter.drawPolyline(points_screen_coordinates.data(), points.size());
}

