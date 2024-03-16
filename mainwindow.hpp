#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsView>
#include "view_interface_t.hpp"
#include "paint_field_t.hpp"
#include "model_t.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_button_open_clicked();

    void on_button_save_clicked();

    void on_button_fill_clicked();

    void on_button_color_clicked();

    void on_button_star_clicked();

    void on_button_polygon_clicked();

    void on_button_line_clicked();

    void on_button_balck_color_clicked();

    void on_button_white_color_clicked();

    void on_button_green_color_clicked();

    void on_button_blue_color_clicked();

    void on_button_red_color_clicked();

    void on_button_geometry_clicked();

    void on_button_help_clicked();

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actioncolor_triggered();

    void on_actionpolygon_triggered();

    void on_actionstar_triggered();

    void on_actionline_triggered();

    void on_actionfill_triggered();

    void on_actiongeometry_triggered();

    void on_actiongeneral_information_triggered();

    void on_button_clear_clicked();

    void on_actionclear_triggered();

    void on_actionabout_triggered();

    void on_button_about_clicked();

private:
    Ui::MainWindow *ui;
    paint_field_t* graphics_view;
    model_t* model;
};
#endif // MAINWINDOW_HPP
