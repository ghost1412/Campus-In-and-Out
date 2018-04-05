#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H
#include <QDebug>
#include <QtSql/QSql>
#include <QFileInfo>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/qsqldatabase.h>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QSqlQuery>
#include <QMessageBox>


class account_handler
{
private:
    QSqlDatabase userdb;
public:
    account_handler();
    bool isOpen();
    void close();
    ~account_handler();
};

#endif // ACCOUNT_HANDLER_H
