#include "ui.h"
#include "ui_ui.h"
#include "institute.h"

UI::UI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UI)
{
    ui->setupUi(this);
}

UI::~UI()
{
    delete ui;
}

void UI::on_loginb_clicked()
{
    institute newinstitute;
    newinstitute.start();
    this->close();
}
