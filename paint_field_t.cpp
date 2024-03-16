#include "paint_field_t.hpp"
#include <iostream>
#include <QMouseEvent>
#include <QScrollBar>
paint_field_t::paint_field_t(QWidget* parent, model_t* model): QGraphicsView(parent), model(model), scene(new QGraphicsScene), item_on_scene(nullptr),
    current_width(model->get_image()->width()), current_height(model->get_image()->height())
{
    model->set_view(this);
    this->setScene(scene);
    scene->setSceneRect(0, 0, current_width, current_height);
    this->setMaximumSize(current_width + 2, current_height + 2);
    QPixmap pic = QPixmap::fromImage(*model->get_image());
    item_on_scene = reinterpret_cast<QGraphicsItem*>(scene->addPixmap(pic));
}


void paint_field_t::mousePressEvent(QMouseEvent *event){
    std::cout << event->pos().x() << "  " << event->pos().y() << std::endl;
    int pos_x = event->x() + this->horizontalScrollBar()->value();
    int pos_y = event->y() + this->verticalScrollBar()->value();
    this->horizontalScrollBar()->value();
    if (model != nullptr){
        model->triger_action(pos_x, pos_y);
    }
    QGraphicsView::mousePressEvent(event);
}


void paint_field_t::on_model_change(){
    int width = model->get_image()->width();
    int height = model->get_image()->height();
    if (current_height != height || current_width != width){
        current_width = width;
        current_height = height;
        scene->setSceneRect(0,0, current_width, current_height);
        this->setMaximumSize(current_width + 2, current_height + 2);
    }
    scene->removeItem(item_on_scene);
    QPixmap pic = QPixmap::fromImage(*model->get_image());
    item_on_scene = reinterpret_cast<QGraphicsItem*>(scene->addPixmap(pic));
}
