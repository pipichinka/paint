#include "paint_action_fill_t.hpp"
#include <QColor>
#include <vector>
#include <iostream>
paint_action_fill_t::paint_action_fill_t(): rgb_color(QColor(Qt::black).rgba())
{

}

void paint_action_fill_t::set_color(QRgb rgb_color){
    this->rgb_color = rgb_color;
}


struct span{
    int x;
    int y;
    span(int x, int y): x(x), y(y){}
    ~span() = default;
};


void scan_for_span(int start_x, int end_x, int y,  std::vector<span>& stack, QRgb* line, QRgb color){
    bool span_found = false;
    for (; start_x < end_x; ++start_x){
        if (line[start_x] == color){
            if (!span_found){
                stack.emplace_back(start_x, y);
                span_found = true;
            }
        }
        else{
            span_found = false;
        }
    }
}


void paint_action_fill_t::mouse_pressed(int x, int y, QImage *image){
    const QRgb region_color = image->pixel(x, y);
    const QRgb color = rgb_color;
    if (region_color == color){
        return;
    }
    const int width = image->width();
    const int height = image->height();
    std::cout << "fill x " << x << " y " << y << " color " << rgb_color << " init_color " << region_color << std::endl;
    std::vector<span> stack;
    stack.emplace_back(x, y);
    while (!stack.empty()){
        span current_span = stack.back();
        stack.pop_back();
        QRgb* current_line = reinterpret_cast<QRgb*>(image->scanLine(current_span.y));
        //std::cout << "color current line pos x " << x << " " << current_line[x] << std::endl;
        int scan_x = current_span.x;
        while (current_line[scan_x] == region_color && scan_x < width){
            current_line[scan_x] = color;
            ++scan_x;
        }
        int end_index = scan_x;
        scan_x = current_span.x - 1;
        while (current_line[scan_x] == region_color && scan_x >= 0){
            current_line[scan_x] = color;
            --scan_x;
        }
        if (current_span.y > 1){
            QRgb* up_line = reinterpret_cast<QRgb*>(image->scanLine(current_span.y - 1));
            scan_for_span(scan_x + 1, end_index, current_span.y - 1, stack, up_line, region_color);

        }
        if (current_span.y < height - 1){
            QRgb* down_line = reinterpret_cast<QRgb*>(image->scanLine(current_span.y + 1));
            scan_for_span(scan_x + 1, end_index, current_span.y + 1, stack, down_line, region_color);
        }

    }
}
