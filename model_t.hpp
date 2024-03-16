#ifndef MODEL_T_HPP
#define MODEL_T_HPP

#include <QImage>
#include "paint_action_interface.hpp"
#include "view_interface_t.hpp"
class model_t
{
public:
    model_t(int width, int height);
    paint_action_interface_t* set_paint_action(paint_action_interface_t* action); //return prev action
    void triger_action(int x, int y);
    void resize(int width, int height);
    int save(QString file_path);
    int open(QString file_path);
    void set_color(QRgb color);
    QRgb get_color();
    void set_view(view_interface_t* listener);
    QImage* get_image();
    void clear();
private:
    void call_listener();

    QImage* image;
    QRgb color;
    paint_action_interface_t* action;
    view_interface_t* listener;
};

#endif // MODEL_T_HPP
