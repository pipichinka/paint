#ifndef LINE_OPTION_DIALOG_HPP
#define LINE_OPTION_DIALOG_HPP

#include <QDialog>

namespace Ui {
class line_option_dialog;
}

class line_option_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit line_option_dialog(QWidget *parent = nullptr, int width = 1);
    int get_width();
    ~line_option_dialog();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::line_option_dialog *ui;
};

#endif // LINE_OPTION_DIALOG_HPP
