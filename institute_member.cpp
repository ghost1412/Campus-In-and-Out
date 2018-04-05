#include "institute_member.h"
#include "person.h"

Institute_Member::Institute_Member()
{

}
QString Institute_Member::getId(){
    return instituteId;
}
void Institute_Member::setId(QString Iid){
    instituteId = Iid;
}
bool Institute_Member::isValidTime(int time){
    if(time>validTimeFrom && time<validTimeTo){
        return 1;
    }else
        return 0;
}
