#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H
#include <QDialog>
#include <QTableView>
#include <QtWidgets>


class database_handler
{
private:
    QString date, time, idNo, purpose, vehicleNo,name, vehicle_color;
    int noPeople, dueVehicle, gateNo, mobileNo;
    bool inside;
public:
    database_handler();
    QString getName();
    void setName(QString);
    void setVehicleColor(QString);
    QString getVehicleColor();
    void setDate(QString);
    QString getDate();
    void setNoPeople(int);
    int getNoPeople();
    void setTime(QString);
    QString getTime();
    int getDueVehicle();
    void setDueVehicle(int);
    int getGateNo();
    void setGateNo(int);
    void setIdNo(QString);
    QString getIdNo();
    void setInside(bool);
    bool getInside();
    void saveEntries(database_handler database);
    void deleteEntries();
    QString getPurpose();
    void setPurpose(QString);
    bool isVehcileReg(QString);
    void setVehicleNo(QString);
    QString getVehicleNo();
    void setMobileNo(int);
    int getMobileNo();
};

#endif // DATABASE_HANDLER_H
