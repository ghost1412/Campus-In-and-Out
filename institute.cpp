#include "institute.h"
#include "ui_institute.h"
#include "account_handler.h"
#include "person.h"
#include "security.h"
#include "admin.h"
#define PATH_TO_DB "/root/Campus-in-out/userdb"
institute::institute(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::institute)
{
    ui->setupUi(this);
    account_handler userdb;
   // userdb = QSqlDatabase::addDatabase("QSQLITE");
    //userdb.setDatabaseName(PATH_TO_DB);
    QFileInfo checkFile(PATH_TO_DB);
    if(checkFile.isFile())
    {
        if(userdb.isOpen())
        {
            ui->status->setText("[+] Connected to Database");
        }
    }else{
         ui->status->setText("[!] Database not connected");
    }
    userdb.close();
}

institute::~institute()
{
    delete ui;
}

void institute::on_loginb_clicked()
{
    account_handler userdb;
    QString username, password, role = "gaurd";
    username = ui->usernamel->text();
    password = ui->passwordl->text();
    if(!userdb.isOpen()){
             qDebug() << "No connection to db";
             return;
         }
         QSqlQuery qry;
         if(qry.exec("SELECT username, password, role FROM login where username=\'"+ username + "\' AND password=\'"+ password + "\'")){
             if(qry.next())
             {
                 if(qry.value(2) == role ){
                     ui->status->setText("[+] Valid username & password");
                     QString msg = "Username = "+ qry.value(0).toString() + "\n" + "Password = " + qry.value(1).toString() + "\n";
                     QMessageBox::warning(this, "Login was Successful", msg);
                     Security* s = new Security();
                     s->show();
                     this->close();
                 }else{
                     Admin *admin = new Admin();
                     admin->start(username);
                     this->close();
                 }
             }else{
                 ui->status->setText("[-] Wrong Username or Password");
             }
         }
}
void institute::start(){
    institute* Institute = new institute();
    Institute->show();
}
