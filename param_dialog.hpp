#ifndef PARAM_DIALOG_HPP
#define PARAM_DIALOG_HPP

#include <QDialog>

namespace Ui {
class param_dialog;
}

class param_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit param_dialog(QWidget *parent = nullptr);
    int get_widht();
    int get_radius();
    int get_number_of_vertices();
    int get_angle();
    ~param_dialog();

private slots:
    void on_width_spin_valueChanged(int arg1);

    void on_width_slider_valueChanged(int value);

    void on_radius_spin_valueChanged(int arg1);

    void on_radius_slider_valueChanged(int value);

    void on_vertices_spin_valueChanged(int arg1);

    void on_vertices_slider_valueChanged(int value);

    void on_angle_spin_valueChanged(int arg1);

    void on_angle_slider_valueChanged(int value);

private:
    Ui::param_dialog *ui;
};

#endif // PARAM_DIALOG_HPP
