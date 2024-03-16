#ifndef PAINT_ACTION_LINE_T_HPP
#define PAINT_ACTION_LINE_T_HPP

#include "paint_action_interface.hpp"

class paint_action_line_t: public paint_action_interface_t
{
public:
    paint_action_line_t(int width);
    virtual void mouse_pressed(int x, int y, QImage* image);
    virtual void set_color(QRgb rgb_color);
    virtual ~paint_action_line_t();
private:
    int width;
    int start_x;
    int start_y;
    bool is_started;
    QRgb rgb_color;
};

#endif // PAINT_ACTION_LINE_T_HPP
