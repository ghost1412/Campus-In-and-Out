#include "Ui.h"
#include "ui_institute.h"
#include "login.h"
#include "ui_entries.h"
#include <QStackedWidget>
Ui::Ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::institute)
{
    ui->setupUi(this);
}

Ui::~Ui()
{
    delete ui;
}

void Ui::on_loginb_clicked()
{
    MainWindow *loginWindow = new MainWindow();
    loginWindow->show();
    this->close();
}

