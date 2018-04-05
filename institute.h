#ifndef INSTITUTE_H
#define INSTITUTE_H

#include <QWidget>

namespace Ui {
class institute;
}

class institute : public QWidget
{
    Q_OBJECT

public:
    explicit institute(QWidget *parent = 0);
    ~institute();
    void start();
private slots:
    void on_loginb_clicked();

private:
    Ui::institute *ui;
};

#endif // INSTITUTE_H
