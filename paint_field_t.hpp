#ifndef PAINT_FIELD_T_HPP
#define PAINT_FIELD_T_HPP

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "model_t.hpp"
#include "view_interface_t.hpp"
class paint_field_t: public QGraphicsView, public view_interface_t
{
    Q_OBJECT
public:
    paint_field_t(QWidget* parent, model_t* model);
    virtual void on_model_change();
protected:
    virtual void mousePressEvent(QMouseEvent *event);
private:
    model_t* model;
    QGraphicsScene* scene;
    QGraphicsItem* item_on_scene;
    int current_width;
    int current_height;
};

#endif // PAINT_FIELD_T_HPP
