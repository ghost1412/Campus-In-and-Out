#include "admin.h"
#include "ui_admin.h"
#include "account_handler.h"
#include "institute.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_newUser_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void Admin::addNewUser(QString username, QString password, QString role){
    account_handler userdb;
    QSqlQuery qry;
    userdb.isOpen();
    qry.prepare("INSERT INTO login (username, password, role) VALUES (:username, :password, :role)");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);
    qry.bindValue(":role", role);
    qry.exec();
    userdb.close();
    QMessageBox::warning(this, "User Added", "Added Successfully");
    ui->stackedWidget->setCurrentIndex(0);
}

void Admin::on_addUser_clicked()
{
    QString username, password, role;
    username = ui->newUsername->text();
    password = ui->newUserPass->text();
    role = ui->roleSelect->currentText();
    addNewUser(username, password, role);
}

void Admin::on_removeUser_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Admin::on_deleteUser_clicked()
{
    QString username = ui->deleteId->text();
    removeUser(username);
}

void Admin::removeUser(QString username){
    account_handler userdb;
    QSqlQuery query;
    userdb.isOpen();
    query.exec("DELETE FROM login WHERE username =\'"+ username + "\' ");
    QMessageBox::warning(this, "User Deleted", "Deleted Successfully");
    if(username == currentUser){
        logout();
        this->close();
    }
    ui->stackedWidget->setCurrentIndex(0);
}

void Admin::start(QString username){
    currentUser = username;
    ui->currUser->setText(username);
    this->show();
}

void Admin::on_logout_clicked()
{
   logout();
}
void Admin::logout(){
    institute newinstitute;
    newinstitute.start();
    this->close();
}

void Admin::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Admin::on_home_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Admin::changeUserPass(QString username, QString password){
    account_handler userdb;
    QSqlQuery query;
    userdb.isOpen();
    query.exec("UPDATE login SET password =\'"+ password + "\'  WHERE username =\'"+ username + "\' ");
    QMessageBox::warning(this, "Success", "Password Changed Successfully");
    ui->stackedWidget->setCurrentIndex(0);
}


void Admin::on_goTochangePass_clicked()
{
      ui->stackedWidget->setCurrentIndex(3);
}

void Admin::on_changepass_clicked()
{
    QString changeIdPass = ui->changeIdPass->text();
    QString Password = ui->newpass->text();
    QString Confirmpass = ui->confirmpass->text();
    ui->changeIdPass->setText("");
    ui->newpass->setText("");
    ui->confirmpass->setText("");
    if(Password == Confirmpass){
     changeUserPass(changeIdPass, Password);
    }else{
        QMessageBox::warning(this, "Error", "Password not matched");
    }
}

void Admin::on_home_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
