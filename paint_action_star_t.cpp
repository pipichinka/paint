#include "paint_action_star_t.hpp"
#include <cmath>
#include <QPointF>
#include <vector>
#include <QPainter>
paint_action_star_t::paint_action_star_t(int width, int radius, int angle, int number_of_vertices):
    rgb_color(QColor(Qt::black).rgba()), width(width), radius(radius), angle(angle), number_of_vertices(number_of_vertices)
{

}

void paint_action_star_t::set_color(QRgb rgb_color){
    this->rgb_color = rgb_color;
}

void paint_action_star_t::mouse_pressed(int x, int y, QImage *image){
    double alpha = M_PI / (double) number_of_vertices;
    double radius = (double) this->radius;
    QPointF diff(x, y);
    double angle_diff = (M_PI / 180.0) * (double) angle;
    std::vector<QPointF> points;
    for (int i = 0; i < number_of_vertices * 2; ++i){
        double c = cos(alpha * i - angle_diff);
        double s = sin(alpha * i - angle_diff);
        double r;
        if (i % 2){
            r = radius;
        }
        else {
            r = radius / 2.0;
        }
        points.emplace_back(r * c  + diff.x(), r * s  + diff.y());
    }
    QPainter p(image);
    p.setPen(QPen(QColor(rgb_color), width, Qt::PenStyle::SolidLine, Qt::PenCapStyle::RoundCap, Qt::PenJoinStyle::RoundJoin));
    for (int i = 0; i < number_of_vertices * 2; ++i){
        p.drawLine(points[i].x(), points[i].y(), points[(i + 1) % (number_of_vertices * 2)].x(), points[(i + 1) % (number_of_vertices * 2)].y());
    }
}
