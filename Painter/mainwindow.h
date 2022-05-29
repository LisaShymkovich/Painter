#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMainWindow>
#include <QSlider>
#include <QColorDialog>
#include "figure.h"
#include "circle.h"
#include "line.h"
#include "rectangle.h"
#include "superline.h"
#include "picture.h"


enum Mode
{
    line,
    superline,
    circle,
    rectangle,
    picture
};

class Window : public QMainWindow
{
    Q_OBJECT
public:
    Window();
    ~Window() override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

public slots:
    void ChangeWidth(int val);
    void ChangeColor(const QColor &);
    void LoadFromFile();
    void SaveToFile();
    void StepBack();
    void Clear();
    void paintEvent(QPaintEvent *event) override;
    void LineChosen();
    void SuperLineChosen();
    void CircleChosen();
    void RectangleChosen();

private:
    QPointF FromScreenCoord(const QPoint& point);
    void Paint(QPaintDevice* paint_device);

    int current_pen_width = 2;
    QColor current_color = Qt::black;
    Mode current_mode = line;

    int state = 0;
    QPointF prev_click_pos;
    std::vector<Figure*> figures{};

    QSlider width_slider{Qt::Horizontal};
    QColorDialog color_dialog{};
    QPixmap pixmap{};
};
#endif // MAINWINDOW_H
