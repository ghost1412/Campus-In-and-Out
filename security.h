#ifndef SECURITY_H
#define SECURITY_H
#include "institute_member.h"
#include "database_handler.h"
#include <QWidget>

namespace Ui {
class Security;
}

class Security : public QWidget,Institute_Member
{
    Q_OBJECT

public:
    explicit Security(QWidget *parent = 0);
    ~Security();
    void start();
private slots:
    void on_addEntry_clicked();
    bool checkSplPermi(QString);
    void on_idcheck_clicked();
    void isVehiclePhy(QString);
    void on_saveEntry_clicked();
    void checkId(QString Id);
    void on_addExitb_clicked();

private:
    Ui::Security *ui;
    void addPersonEntry(database_handler);
    void addPersonExit(database_handler);
    bool isVehicle(QString);
};

#endif // SECURITY_H
