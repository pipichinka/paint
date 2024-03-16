#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <qfiledialog.h>
#include <QDebug>
#include <iostream>
#include "paint_field_t.hpp"
#include "paint_action_line_t.hpp"
#include <QColorDialog>
#include "geometry.hpp"
#include "line_option_dialog.hpp"
#include "paint_action_fill_t.hpp"
#include "param_dialog.hpp"
#include "paint_action_polygon_t.hpp"
#include "paint_action_star_t.hpp"
#include <QErrorMessage>
#include <QMessageBox>
#include <QIcon>
#include "help_window.hpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new model_t(640, 420))
{
    ui->setupUi(this);
    graphics_view = new paint_field_t(ui->centralwidget, model);
    graphics_view->setObjectName(QString::fromUtf8("graphicsView"));
    QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
    sizePolicy3.setHeightForWidth(graphics_view->sizePolicy().hasHeightForWidth());
    graphics_view->setSizePolicy(sizePolicy3);
    graphics_view->setMouseTracking(true);
    graphics_view->setTabletTracking(false);
    graphics_view->setLayoutDirection(Qt::LeftToRight);
    graphics_view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    graphics_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    graphics_view->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    graphics_view->setInteractive(false);
    graphics_view->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

    ui->verticalLayout->addWidget(graphics_view);

    model->set_paint_action(new paint_action_line_t(1));
    ui->actionfill->setChecked(false);
    ui->actionline->setChecked(true);
    ui->actionpolygon->setChecked(false);
    ui->actionstar->setChecked(false);

    ui->button_fill->setChecked(false);
    ui->button_line->setChecked(true);
    ui->button_polygon->setChecked(false);
    ui->button_star->setChecked(false);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete graphics_view;
    delete model;
}


void MainWindow::on_button_open_clicked()
{
    QString file = QFileDialog::getOpenFileName(
                                this,
                                "Select one file to open",
                                "/home",
                                "Images (*.png *.bmp *.jpg *.jpeg *.gif)");

    if (file.size() == 0){
        return;
    }
    if (model->open(file)){
        QErrorMessage error(this);
        error.showMessage("can't open file" + file);
    }
}


void MainWindow::on_button_save_clicked()
{
    QString file = QFileDialog::getSaveFileName(this, "select file to save", "/home", "Images(*.png *.jpg *.jpeg *.bmp)");
    if (file.size() == 0){
        return;
    }
    if (model->save(file)){
        QErrorMessage error(this);
        error.showMessage("can't save image to this file" + file);
    }

}


void MainWindow::on_button_fill_clicked()
{
    ui->actionfill->setChecked(true);
    ui->actionline->setChecked(false);
    ui->actionpolygon->setChecked(false);
    ui->actionstar->setChecked(false);

    ui->button_fill->setChecked(true);
    ui->button_line->setChecked(false);
    ui->button_polygon->setChecked(false);
    ui->button_star->setChecked(false);
    auto old = model->set_paint_action(new paint_action_fill_t());
    delete old;
}


void MainWindow::on_button_color_clicked()
{
    std::cout << model->get_color() << std::endl;
    QColor color = QColorDialog::getColor(model->get_color(), this, "", QColorDialog::ColorDialogOption::ShowAlphaChannel);
    if (color.isValid()){
        model->set_color(color.rgba());
        std::cout << color.rgba() << std::endl;
    }
}


void MainWindow::on_button_star_clicked()
{
    param_dialog dialog(this);
    int res = dialog.exec();
    if (res != QDialog::Accepted){
        ui->button_star->setChecked(false);
        return;
    }
    auto old = model->set_paint_action(new paint_action_star_t(dialog.get_widht(),
                                                                  dialog.get_radius(),
                                                                  dialog.get_angle(),
                                                                  dialog.get_number_of_vertices()));
    delete old;
    ui->actionfill->setChecked(false);
    ui->actionline->setChecked(false);
    ui->actionpolygon->setChecked(false);
    ui->actionstar->setChecked(true);

    ui->button_fill->setChecked(false);
    ui->button_line->setChecked(false);
    ui->button_polygon->setChecked(false);
    ui->button_star->setChecked(true);
}


void MainWindow::on_button_polygon_clicked()
{
    param_dialog dialog(this);
    int res = dialog.exec();
    if (res != QDialog::Accepted){
        ui->button_polygon->setChecked(false);
        return;
    }
    auto old = model->set_paint_action(new paint_action_polygon_t(dialog.get_widht(),
                                                                  dialog.get_radius(),
                                                                  dialog.get_angle(),
                                                                  dialog.get_number_of_vertices()));
    delete old;
    ui->actionfill->setChecked(false);
    ui->actionline->setChecked(false);
    ui->actionpolygon->setChecked(true);
    ui->actionstar->setChecked(false);

    ui->button_fill->setChecked(false);
    ui->button_line->setChecked(false);
    ui->button_polygon->setChecked(true);
    ui->button_star->setChecked(false);
}


void MainWindow::on_button_line_clicked()
{
    line_option_dialog dialog(this, 1);
    int res = dialog.exec();
    if (res != QDialog::Accepted){
        ui->button_line->setChecked(false);
        return;
    }
    auto old = model->set_paint_action(new paint_action_line_t(dialog.get_width()));
    delete old;
    ui->actionfill->setChecked(false);
    ui->actionline->setChecked(true);
    ui->actionpolygon->setChecked(false);
    ui->actionstar->setChecked(false);

    ui->button_fill->setChecked(false);
    ui->button_line->setChecked(true);
    ui->button_polygon->setChecked(false);
    ui->button_star->setChecked(false);
}


void MainWindow::on_button_balck_color_clicked()
{
    model->set_color(QColor(Qt::black).rgba());
}


void MainWindow::on_button_white_color_clicked()
{
    model->set_color(QColor(Qt::white).rgba());
}


void MainWindow::on_button_green_color_clicked()
{
    model->set_color(QColor(Qt::green).rgba());
}


void MainWindow::on_button_blue_color_clicked()
{
    model->set_color(QColor(Qt::blue).rgba());
}


void MainWindow::on_button_red_color_clicked()
{
    model->set_color(QColor(Qt::red).rgba());
}


void MainWindow::on_button_geometry_clicked()
{
    ::geometry dialog(this, model->get_image()->width(), model->get_image()->height());
    int res = dialog.exec();
    if (res == QDialog::Accepted){
        model->resize(dialog.get_width(), dialog.get_height());
    }
}


void MainWindow::on_button_help_clicked()
{
    help_window w(this);
    w.show();
    QEventLoop loop;                                                                                  // creates event loop

    connect(&w, SIGNAL(destroyed()), &loop, SLOT(quit()));                  // connects destroyed signal of settings window to quit loop

    loop.exec();
}


void MainWindow::on_actionopen_triggered()
{
    QString file = QFileDialog::getOpenFileName(
                                this,
                                "Select one file to open",
                                "/home",
                                "Images (*.png *.bmp *.jpg *.jpeg *.gif)");

    if (file.size() == 0){
        return;
    }
    if (model->open(file)){
        QErrorMessage error(this);
        error.showMessage("can't open file" + file);
    }
}


void MainWindow::on_actionsave_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "select file to save", "/home", "Images(*.png *.jpg *.jpeg *.bmp)");
    if (file.size() == 0){
        return;
    }
    if (model->save(file)){
        QErrorMessage error(this);
        error.showMessage("can't save image to this file" + file);
    }
}


void MainWindow::on_actioncolor_triggered()
{
    QColor color = QColorDialog::getColor(model->get_color(), this, "", QColorDialog::ColorDialogOption::ShowAlphaChannel);
    model->set_color(color.rgba());
    std::cout << color.rgba() << std::endl;
}


void MainWindow::on_actionpolygon_triggered()
{
    param_dialog dialog(this);
    int res = dialog.exec();
    if (res != QDialog::Accepted){
        ui->actionpolygon->setChecked(false);
        return;
    }
    auto old = model->set_paint_action(new paint_action_polygon_t(dialog.get_widht(),
                                                                  dialog.get_radius(),
                                                                  dialog.get_angle(),
                                                                  dialog.get_number_of_vertices()));
    delete old;
    ui->actionfill->setChecked(false);
    ui->actionline->setChecked(false);
    ui->actionpolygon->setChecked(true);
    ui->actionstar->setChecked(false);

    ui->button_fill->setChecked(false);
    ui->button_line->setChecked(false);
    ui->button_polygon->setChecked(true);
    ui->button_star->setChecked(false);
}


void MainWindow::on_actionstar_triggered()
{
    param_dialog dialog(this);
    int res = dialog.exec();
    if (res != QDialog::Accepted){
        ui->actionstar->setChecked(false);
        return;
    }
    auto old = model->set_paint_action(new paint_action_star_t(dialog.get_widht(),
                                                                  dialog.get_radius(),
                                                                  dialog.get_angle(),
                                                                  dialog.get_number_of_vertices()));
    delete old;
    ui->actionfill->setChecked(false);
    ui->actionline->setChecked(false);
    ui->actionpolygon->setChecked(false);
    ui->actionstar->setChecked(true);

    ui->button_fill->setChecked(false);
    ui->button_line->setChecked(false);
    ui->button_polygon->setChecked(false);
    ui->button_star->setChecked(true);
}


void MainWindow::on_actionline_triggered()
{
    line_option_dialog dialog(this, 1);
    int res = dialog.exec();
    if (res != QDialog::Accepted){
        ui->actionline->setChecked(false);
        return;
    }
    auto old = model->set_paint_action(new paint_action_line_t(dialog.get_width()));
    delete old;
    ui->actionfill->setChecked(false);
    ui->actionline->setChecked(true);
    ui->actionpolygon->setChecked(false);
    ui->actionstar->setChecked(false);

    ui->button_fill->setChecked(false);
    ui->button_line->setChecked(true);
    ui->button_polygon->setChecked(false);
    ui->button_star->setChecked(false);

}


void MainWindow::on_actionfill_triggered()
{
    ui->actionfill->setChecked(true);
    ui->actionline->setChecked(false);
    ui->actionpolygon->setChecked(false);
    ui->actionstar->setChecked(false);

    ui->button_fill->setChecked(true);
    ui->button_line->setChecked(false);
    ui->button_polygon->setChecked(false);
    ui->button_star->setChecked(false);
    auto old = model->set_paint_action(new paint_action_fill_t());
    delete old;
}


void MainWindow::on_actiongeometry_triggered()
{
    ::geometry dialog(this, model->get_image()->width(), model->get_image()->height());
    int res = dialog.exec();
    if (res == QDialog::Accepted){
        model->resize(dialog.get_width(), dialog.get_height());
    }
}


void MainWindow::on_actiongeneral_information_triggered()
{
    on_button_help_clicked();
}


void MainWindow::on_button_clear_clicked()
{
    model->clear();
}


void MainWindow::on_actionclear_triggered()
{
    model->clear();
}


void MainWindow::on_actionabout_triggered()
{
    QMessageBox about(QMessageBox::Icon::Information, "about inforation",
                      "Program paint was made by Michail Sirotkin student of Novosibirk State University FIT faculty group 21203",
                      QMessageBox::StandardButton::NoButton, this);
    about.exec();
}


void MainWindow::on_button_about_clicked()
{
    on_actionabout_triggered();
}

