#ifndef PAINT_ACTION_STAR_T_HPP
#define PAINT_ACTION_STAR_T_HPP


#include "paint_action_interface.hpp"
#include <QColor>
#include <QImage>
class paint_action_star_t: public paint_action_interface_t
{
public:
    virtual void mouse_pressed(int x, int y, QImage* image);
    virtual void set_color(QRgb rgb_color);
    paint_action_star_t(int width, int radius, int angle, int number_of_vertices);
    virtual ~paint_action_star_t() = default;
private:
    QRgb rgb_color;
    int width;
    int radius;
    int angle;
    int number_of_vertices;
};

#endif // PAINT_ACTION_STAR_T_HPP
