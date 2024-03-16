#ifndef PAINT_ACTION_INTERFACE_HPP
#define PAINT_ACTION_INTERFACE_HPP
#include <QMouseEvent>
#include <QImage>
class paint_action_interface_t
{
public:
    virtual void mouse_pressed(int x, int y, QImage* image) = 0;
    virtual void set_color(QRgb rgb_color) = 0;
    virtual ~paint_action_interface_t() = default;
};


#endif // PAINT_ACTION_INTERFACE_HPP
