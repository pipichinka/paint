#include "paint_action_line_t.hpp"
#include <QPainter>
#include <QPen>
#include <iostream>

paint_action_line_t::paint_action_line_t(int width): width(width), start_x(0), start_y(0), is_started(false), rgb_color(QColor(Qt::black).rgba())
{}


void paint_action_line_t::set_color(QRgb rgb_color){
    this->rgb_color = rgb_color;
}

paint_action_line_t::~paint_action_line_t(){

}


static void draw_line(int x1, int y1, int x2, int y2, QImage* image, QRgb color){
    std::cout << "draw_line  x1 " << x1 << " y1 " << y1 << " x2 " << x2 << " y2 " << y2 << std::endl;
    const int dx = x2 - x1;
    const int dy = y2 - y1;
    const int adx = std::abs(dx);
    const int ady = std::abs(dy);
    const int diff_x = dx >= 0 ? 1 : -1;
    const int diff_y = dy >= 0 ? 1 : -1;
    int y = y1;
    int x = x1;
    if (adx > ady){
        int error = -adx;
        const int error_inc = 2*ady;
        const int error_dec = 2*adx;
        for (int i = 0; i <= adx; ++i){
            image->setPixel(x, y, color);
            x += diff_x;
            error += error_inc;
            if (error > 0){
                error -= error_dec;
                y += diff_y;
            }
        }
    } else {
        int error = -ady;
        const int error_inc = 2*adx;
        const int error_dec = 2*ady;
        for (int i = 0; i <= ady; ++i){
            image->setPixel(x, y, color);
            y += diff_y;
            error += error_inc;
            if (error > 0){
                error -= error_dec;
                x += diff_x;
            }
        }
    }
}


void paint_action_line_t::mouse_pressed(int x, int y, QImage* image){
    if (!is_started){
        is_started = true;
        start_x = x;
        start_y = y;
        return;
    }
    is_started = false;
    if (width == 1){
        draw_line(start_x, start_y, x, y, image, rgb_color);
        return;
    }
    QPainter p(image);
    p.setPen(QPen(QColor(rgb_color), width));
    p.drawLine(start_x, start_y, x, y);
}



