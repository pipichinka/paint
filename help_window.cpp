#include "help_window.hpp"
#include "ui_help_window.h"

help_window::help_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::help_window)
{
    ui->setupUi(this);
}

help_window::~help_window()
{
    delete ui;
}
