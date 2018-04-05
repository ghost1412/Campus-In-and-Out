#include "database_handler.h"
#include "account_handler.h"
database_handler::database_handler():vehicleNo("Nan"),vehicle_color("Nan")
{

}
QString database_handler::getName(){
    return name;
}

void database_handler::setName(QString sname){
    name = sname;
}

void database_handler::setVehicleColor(QString scolor){
    vehicle_color = scolor[0];
}

QString database_handler::getVehicleColor(){
    return vehicle_color;
}

void database_handler::setDate(QString sdate){
    date = sdate;
}

QString database_handler::getDate(){
    return date;
}

void database_handler::setNoPeople(int snoPeople){
    noPeople = snoPeople;
}

int database_handler::getNoPeople(){
    return noPeople;
}

void database_handler::setTime(QString stime){
    time = stime;
}

QString database_handler::getTime(){
    return time;
}

int database_handler::getDueVehicle(){
    return dueVehicle;
}

void database_handler::setDueVehicle(int sdue){
    dueVehicle = sdue;
}

int database_handler::getGateNo(){
    return gateNo;
}

void database_handler::setGateNo(int sgateNo){
    gateNo = sgateNo;
}

void database_handler::setIdNo(QString sId){
    idNo = sId;
}

QString database_handler::getIdNo(){
    return idNo;
}

void database_handler::setInside(bool sinside){
    inside = sinside;
}

bool database_handler::getInside(){
    return inside;
}

void database_handler::saveEntries(database_handler database){
    account_handler userdb;
    QSqlQuery qry;
    userdb.isOpen();
    qry.prepare("INSERT INTO persondb (Name, Id, MobileNo, Date, Time, gateNo, purpose, inside, dueVehicle, noPeople, vehicleno, vehiclecolor) VALUES (:Name, :Id, :MobileNo, :Date, :Time, :gateNo, :purpose, :inside, :dueVehicle, :noPeople, :vehicleno, :vehiclecolor)");
    qry.bindValue(":Name", database.getName());
    qry.bindValue(":Id", database.getIdNo());
    qry.bindValue(":MobileNo", database.getMobileNo());
    qry.bindValue(":Date", database.getDate());
    qry.bindValue(":Time", database.getTime());
    qry.bindValue(":gateNo", database.gateNo);
    qry.bindValue(":purpose", database.getPurpose());
    qry.bindValue(":inside", database.getInside());
    qry.bindValue(":dueVehicle", database.getDueVehicle());
    qry.bindValue(":noPeople", database.getNoPeople());
    qry.bindValue(":vehicleno", database.getVehicleNo());
    qry.bindValue(":vehiclecolor", database.getVehicleColor());
    qry.exec();
    userdb.close();
}
void database_handler::deleteEntries(){}
QString database_handler::getPurpose(){
    return purpose;
}

void database_handler::setPurpose(QString sPurpose){
    purpose = sPurpose;
}

bool database_handler::isVehcileReg(QString vehicle_no){
    account_handler userdb;
    QSqlQuery qry;
    userdb.isOpen();
    if(qry.exec("SELECT vehicle_no FROM registeredVehicle where vehicle_no=\'"+ vehicle_no + "\'")){
        if(qry.next())
        {
            return true;
        }else{
            return false;
        }
    }
    userdb.close();
}
void database_handler::setVehicleNo(QString svehicleNo){
    vehicleNo = svehicleNo;
}

QString database_handler::getVehicleNo(){
    return vehicleNo;
}

void database_handler::setMobileNo(int smobileNo){
    mobileNo = smobileNo;
}

int database_handler::getMobileNo(){
    return mobileNo;
}
