#include <QPainter>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QMouseEvent>
#include <cmath>
#include <QDebug>
#include <QFileDialog>
#include <QImage>
#include "mainwindow.h"

void Window::paintEvent(QPaintEvent* event)
{
    Paint(this);
    QWidget::paintEvent(event);
}

Window::Window()
{
    setMinimumSize(480, 270);
    resize(1600, 900);
    width_slider.setMinimum(1);
    width_slider.setMaximum(10);
    connect(&width_slider,
            SIGNAL(valueChanged(int)),
            this,
            SLOT(ChangeWidth(int)));
    width_slider.setFixedSize(300, 50);

    connect(&color_dialog, SIGNAL(colorSelected(const QColor&)),
            this, SLOT(ChangeColor(const QColor&)));

    setMenuBar(new QMenuBar());
    QMenu* figure_menu = new QMenu("Figure");
    menuBar()->addMenu(figure_menu);

    connect(figure_menu->addAction("Line"), SIGNAL(triggered(bool)),
            this, SLOT(LineChosen()));
    connect(figure_menu->addAction("Super-line"), SIGNAL(triggered(bool)),
            this, SLOT(SuperLineChosen()));
    connect(figure_menu->addAction("Circle"), SIGNAL(triggered(bool)),
            this, SLOT(CircleChosen()));
    connect(figure_menu->addAction("Rectangle"), SIGNAL(triggered(bool)),
            this, SLOT(RectangleChosen()));

    QMenu* settings_menu = new QMenu("Settings");
    menuBar()->addMenu(settings_menu);
    connect(settings_menu->addAction("Change pen width"), SIGNAL(triggered(bool)),
            &width_slider, SLOT(show()));
    connect(settings_menu->addAction("Change color"), SIGNAL(triggered(bool)),
            &color_dialog, SLOT(show()));
    connect(settings_menu->addAction("Step Back"), SIGNAL(triggered(bool)),
            this, SLOT(StepBack()));
    connect(settings_menu->addAction("Clear"), SIGNAL(triggered(bool)),
            this, SLOT(Clear()));

    QMenu* file_menu = new QMenu("File");
    menuBar()->addMenu(file_menu);
    connect(file_menu->addAction("Load from file"), SIGNAL(triggered(bool)),
            this, SLOT(LoadFromFile()));
    connect(file_menu->addAction("Save to file"), SIGNAL(triggered(bool)),
            this, SLOT(SaveToFile()));

    statusBar()->showMessage("Line", 20000);
}


void Window::LineChosen()
{
    current_mode = line;
    state = 0;
    statusBar()->showMessage("Line", 20000);
}


void Window::SuperLineChosen()
{
    current_mode = superline;
    state = 0;
    statusBar()->showMessage("Super-line", 20000);
}


void Window::CircleChosen()
{
    current_mode = circle;
    state = 0;
    statusBar()->showMessage("Circle", 20000);
}


void Window::RectangleChosen()
{
    current_mode = rectangle;
    state = 0;
    statusBar()->showMessage("Rectangle", 20000);
}


void Window::mouseMoveEvent(QMouseEvent* event)
{
    if (state == 0 || current_mode != superline)
    {
        return;
    }
    dynamic_cast<SuperLine*>(figures.back())->AddPoint(FromScreenCoord(event->pos()));
    repaint();
}


void Window::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() != Qt::LeftButton || state == 0 || current_mode != superline)
    {
        return;
    }
    state = 0;
    repaint();
}


void Window::mousePressEvent(QMouseEvent* event)
{
    if (event->y() <= menuBar()->height()
            || event->y() >= height() - statusBar()->height())
    {
        return;
    }

    if (state == 0)
    {
        prev_click_pos = FromScreenCoord(event->pos());

        if (current_mode == superline)
        {
            figures.push_back(new SuperLine(current_color, current_pen_width,
                                            prev_click_pos.x(), prev_click_pos.y(),
                                            prev_click_pos.x(), prev_click_pos.y()));
        }
        state++;
        return;
    }


    QPointF cur_click = FromScreenCoord(event->pos());
    if (current_mode == line)
    {
        figures.push_back(new Line(current_color, current_pen_width,
                                   prev_click_pos.x(), prev_click_pos.y(),
                                   cur_click.x(), cur_click.y()));
        state = 0;
    }

    else if (current_mode == circle)
    {
        double dx = cur_click.x() - prev_click_pos.x();
        double dy = cur_click.y() - prev_click_pos.y();
        double r = sqrt(dx * dx + dy * dy);
        figures.push_back(new Circle(current_color, current_pen_width,
                                     prev_click_pos.x() - r,
                                     prev_click_pos.y() - r,
                                     2 * r,
                                     2 * r));
        state = 0;
    }

    else if (current_mode == rectangle)
    {
        figures.push_back(new Rectangle(current_color, current_pen_width,
                                        prev_click_pos.x(), prev_click_pos.y(),
                                        cur_click.x() - prev_click_pos.x(),
                                        cur_click.y() - prev_click_pos.y()));
        state = 0;
    }

    else if (current_mode == picture)
    {
        figures.push_back(new Picture(current_color, current_pen_width,
                                      prev_click_pos.x(), prev_click_pos.y(),
                                      cur_click.x() - prev_click_pos.x(),
                                      cur_click.y() - prev_click_pos.y(),
                                      pixmap));
        state = 0;
    }
    repaint();
}



QPointF Window::FromScreenCoord(const QPoint& point)
{
    return {(double) point.x() / width() * 16, (double) point.y() / height() * 9};
}


void Window::ChangeWidth(int val)
{
    current_pen_width = val;
}


void Window::ChangeColor(const QColor& color)
{
    current_color = color;
}


void Window::StepBack()
{
    if (!figures.empty())
    {
        delete figures.back();
        figures.pop_back();
        state = 0;
        repaint();
    }
}

void Window::Clear()
{
    if (!figures.empty())
    {
        SaveToFile();
        figures.clear();
        state = 0;
        repaint();
    }
}


Window::~Window()
{
    for (auto& figure: figures)
    {
        delete figure;
    }
}


void Window::LoadFromFile()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Load Picture",
                                                "",
                                                tr("Images (*.png *.xpm *.jpg *jpeg *bmp)"));
    if (!file.isNull())
    {
        pixmap = QPixmap(file);
        Picture* loadedPicture = new Picture(current_color,current_pen_width,0,0,16,9,pixmap);
        figures.push_back(loadedPicture);
    }
}


void Window::SaveToFile()
{
    QImage image(1600,900, QImage::Format_RGB32);
    image.fill(Qt::white);
    Paint(&image);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image File"),
                                                    QString(),
                                                    tr("Images (*.png)"));
    if (!fileName.isEmpty())
    {
        image.save(fileName);
    }
}


void Window::Paint(QPaintDevice* paint_device)
{
    QPainter painter(paint_device);
    for (int i = 0; i < figures.size(); i++)
    {
        painter.setPen(QPen(figures[i]->GetColor(), figures[i]->GetPenWidth()));
        figures[i]->Draw(painter);
    }
}

