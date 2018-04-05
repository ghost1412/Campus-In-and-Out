#ifndef INSTITUTE_MEMBER_H
#define INSTITUTE_MEMBER_H
#include <QDialog>
#include <QTableView>
#include <QtWidgets>
#include <person.h>

class Institute_Member:public Person
{
private:
    QString instituteId;
public:
    int validTimeFrom, validTimeTo;
public:
    Institute_Member();
    QString getId();
    void setId(QString);
    bool isValidTime(int);
};

#endif // INSTITUTE_MEMBER_H
