#include "geometry.hpp"
#include "ui_geometry.h"
#include <QErrorMessage>


geometry::geometry(QWidget *parent, int width, int height) :
    QDialog(parent),
    ui(new Ui::geometry)
{
    ui->setupUi(this);
    ui->edit_height->setValue(height);
    ui->edit_width->setValue(width);
}


int geometry::get_width(){
    return ui->edit_width->value();
}


int geometry::get_height(){
    return ui->edit_height->value();
}


geometry::~geometry()
{
    delete ui;
}

