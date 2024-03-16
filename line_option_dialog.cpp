#include "line_option_dialog.hpp"
#include "ui_line_option_dialog.h"


line_option_dialog::line_option_dialog(QWidget *parent, int width) :
    QDialog(parent),
    ui(new Ui::line_option_dialog)
{
    ui->setupUi(this);
    ui->spinBox->setValue(width);
    ui->horizontalSlider->setValue(width);
}


line_option_dialog::~line_option_dialog()
{
    delete ui;
}


int line_option_dialog::get_width(){
    return ui->spinBox->value();
}

void line_option_dialog::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}


void line_option_dialog::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}

