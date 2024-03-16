#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <QDialog>

namespace Ui {
class geometry;
}

class geometry : public QDialog
{
    Q_OBJECT

public:
    explicit geometry(QWidget *parent = nullptr, int width = 640, int height = 480);
    int get_width();
    int get_height();
    ~geometry();

private:
    Ui::geometry *ui;
};

#endif // GEOMETRY_HPP
