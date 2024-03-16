#ifndef HELP_DIALOG_HPP
#define HELP_DIALOG_HPP

#include <QDialog>

namespace Ui {
class help_dialog;
}

class help_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit help_dialog(QWidget *parent = nullptr);
    ~help_dialog();

private:
    Ui::help_dialog *ui;
};

#endif // HELP_DIALOG_HPP
