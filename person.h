#ifndef PERSON_H
#define PERSON_H
#include <QDialog>
#include <QTableView>
#include <QtWidgets>


class Person
{
private:
    QString id, Name;
    int mobileNo;
    bool inside;
public:
    Person();
    QString getId();
    QString getName();
    int getmobileNo();
    void setId(QString);
    void setName(QString);
    void setmobileNo(int);
    bool isInside();
    void setInside(bool);
};

#endif // PERSON_H
