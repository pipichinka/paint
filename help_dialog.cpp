#include "help_dialog.hpp"
#include "ui_help_dialog.h"

help_dialog::help_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_dialog)
{
    ui->setupUi(this);
}

help_dialog::~help_dialog()
{
    delete ui;
}
