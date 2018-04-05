#include "person.h"

Person::Person()
{
inside = 0;
}
QString Person::getId(){
    return id;
}
QString Person::getName(){
    return Name;
}
int Person::getmobileNo(){
    return mobileNo;
}
void Person::setId(QString PId){
    id = PId;
}
void Person::setName(QString Pname){
    Name = Pname;
}
void Person::setmobileNo(int Pno){
    mobileNo = Pno;
}
bool Person::isInside(){
    return inside;
}
void Person::setInside(bool Pin){
    inside = Pin;
}

