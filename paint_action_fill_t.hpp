#ifndef PAINT_ACTION_FILL_T_HPP
#define PAINT_ACTION_FILL_T_HPP

#include "paint_action_interface.hpp"
class paint_action_fill_t: public paint_action_interface_t
{
public:
    virtual void mouse_pressed(int x, int y, QImage* image);
    virtual void set_color(QRgb rgb_color);
    paint_action_fill_t();
    virtual ~paint_action_fill_t() = default;
private:
    QRgb rgb_color;
};

#endif // PAINT_ACTION_FILL_T_HPP
