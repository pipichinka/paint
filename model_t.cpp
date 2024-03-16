#include "model_t.hpp"
#include <QPainter>
#include <iostream>
model_t::model_t(int width, int height): image(new QImage(width, height, QImage::Format::Format_ARGB32)), color(QColor(Qt::black).rgb()), action(nullptr), listener(nullptr)
{
    image->fill(Qt::white);
}


void model_t::set_view(view_interface_t* listener){
    this->listener = listener;
}


paint_action_interface_t* model_t::set_paint_action(paint_action_interface_t *action){
    auto res = this->action;
    this->action = action;
    action->set_color(color);
    return res;
}


void model_t::set_color(QRgb color){
    this->color = color;
    action->set_color(color);
}


int model_t::open(QString file_path){
    std::cout << file_path.toStdString() <<std::endl ;
    QImage* i = new QImage(file_path);
    if (i->isNull()){
        return 1; // todo open error
    }
    delete image;
    image = i;
    call_listener();
    return 0;
}


int model_t::save(QString file_path){
    std::cout << file_path.toStdString() <<std::endl ;
    if (image->save(file_path)){
        return 1;
    }
    return 0;
}


QImage* model_t::get_image(){
    return image;
}

QRgb model_t::get_color(){
    return color;
}


void model_t::call_listener(){
    if (listener != nullptr){
        listener->on_model_change();
    }
}


void model_t::resize(int width, int height){
    QImage* i = new QImage(width, height, QImage::Format::Format_ARGB32);
    i->fill(Qt::white);
    QPainter p(i);
    QRectF rect(0, 0, std::min(image->width(), width), std::min(image->height(), height));
    p.drawImage(rect, *image, rect);
    delete image;
    image = i;
    call_listener();
}


void model_t::clear(){
    image->fill(Qt::white);
    call_listener();
}


void model_t::triger_action(int x, int y){
    if (action != nullptr){
        action->mouse_pressed(x, y, image);
        call_listener();
    }
}


