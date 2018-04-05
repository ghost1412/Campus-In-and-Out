#include "security.h"
#include "ui_security.h"
#include <QStackedWidget>
#include <student.h>
#include <QDateTime>
#include "account_handler.h"
#include "worker.h"
#include "database_handler.h"
#include "faculty.h"
#define PATH_TO_DB "/root/Campus-in-out/userdb"

Security::Security(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Security)
{
    ui->setupUi(this);
}

Security::~Security()
{
    delete ui;
}


void Security::on_addEntry_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
bool Security::checkSplPermi(QString id){
    account_handler userdb;
    QSqlQuery qry;
    userdb.isOpen();
    if(qry.exec("SELECT ID FROM special_permission where ID=\'"+ id + "\'")){
        if(qry.next())
        {
            userdb.close();
            return 1;
        }
        else{
            userdb.close();
            return 0;
        }
    }
    userdb.close();
    return 0;
}
void Security::addPersonEntry(database_handler database){
    database.setVehicleColor(ui->vehicleColorc->text());
    database.setName(ui->namec->text());
    database.setNoPeople(ui->noPeoplec->text().toInt());
    database.setGateNo(ui->gateNoc->text().toInt());
    database.setMobileNo(ui->mobileNoc->text().toInt());
    database.setIdNo(ui->idNoc->text());
    database.setTime(ui->timec->text());
    database.setVehicleNo(ui->vehiclenoc->text());
    database.setPurpose(ui->puposec->text());
    database.setDate("g");
    account_handler userdb;
    QSqlQuery qry;
    userdb.isOpen();
    if(qry.exec("SELECT inside FROM persondb where Id=\'"+ database.getIdNo() + "\'")){
        if(qry.first() == 1)
        {
            QMessageBox::warning(this, "Caution", "Person Already Inside");
            ui->stackedWidget->setCurrentIndex(1);
        }
        else{

            database.setInside(true);
            database.saveEntries(database);
            ui->stackedWidget->setCurrentIndex(1);
        }
    }
    userdb.close();

}

void Security::on_idcheck_clicked()
{
    QString Id;
    Id = ui->idNoc->text();
    checkId(Id);

}
void Security::isVehiclePhy(QString vehicle_no){
    database_handler db;
        if(db.isVehcileReg(vehicle_no))
        {
            ui->vehicleColorc->setText("G");
        }
        else{
            ui->vehicleColorc->setText("R");
        }
}

void Security::on_saveEntry_clicked()
{
    database_handler database;
    addPersonEntry(database);
}
bool Security::isVehicle(QString vehicle_no){
    if(vehicle_no != "Nan"){
        return 1;
    }else{
        return 0;
    }
}

void Security::on_addExitb_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Security::checkId(QString Id){
    QString vehicle_no = ui->vehiclenoc->text();
    if(isVehicle(vehicle_no)){
        ui->vehicleColorc->setText("");
        isVehiclePhy(vehicle_no);
    }
    if(Id[0]=='s'||Id[0]=='S'){
        Student student;
        int current_time = ui->timec->text().toInt();
        if(student.isValidTime(current_time)==1||checkSplPermi(Id)==1){
            ui->stackedWidget->setCurrentIndex(3);
        }else{

            QMessageBox::warning(this, "Caution", "Time Not Valid");
        }
    }else
    if(Id[0]=='w'||Id[0]=='W'){
        worker w;
        ui->stackedWidget->setCurrentIndex(3);
    }else
    if(Id[0]=='F'||Id[0]=='f'){
        Faculty w;
        ui->stackedWidget->setCurrentIndex(3);
    }
    else{
        Person person;
        if(isVehicle(vehicle_no)){
             ui->vehicleColorc->setText("R");
        }
        ui->stackedWidget->setCurrentIndex(3);
    }
}
void Security::start(){
    this->show();
}
