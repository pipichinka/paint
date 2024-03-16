#include "param_dialog.hpp"
#include "ui_param_dialog.h"

param_dialog::param_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::param_dialog)
{
    ui->setupUi(this);
}

param_dialog::~param_dialog()
{
    delete ui;
}

void param_dialog::on_width_spin_valueChanged(int arg1)
{
    ui->width_slider->setValue(arg1);
}


void param_dialog::on_width_slider_valueChanged(int value)
{
    ui->width_spin->setValue(value);
}


void param_dialog::on_radius_spin_valueChanged(int arg1)
{
    ui->radius_slider->setValue(arg1);
}


void param_dialog::on_radius_slider_valueChanged(int value)
{
    ui->radius_spin->setValue(value);
}


void param_dialog::on_vertices_spin_valueChanged(int arg1)
{
    ui->vertices_slider->setValue(arg1);
}


void param_dialog::on_vertices_slider_valueChanged(int value)
{
    ui->vertices_spin->setValue(value);
}


void param_dialog::on_angle_spin_valueChanged(int arg1)
{
    ui->angle_slider->setValue(arg1);
}


void param_dialog::on_angle_slider_valueChanged(int value)
{
    ui->angle_spin->setValue(value);
}


int param_dialog::get_angle(){
    return ui->angle_spin->value();
}


int param_dialog::get_radius(){
    return ui->radius_spin->value();
}


int param_dialog::get_widht(){
    return ui->width_spin->value();
}


int param_dialog::get_number_of_vertices(){
    return ui->vertices_spin->value();
}

