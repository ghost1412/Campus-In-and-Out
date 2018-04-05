#include "account_handler.h"
#define PATH_TO_DB "/root/Campus-in-out/userdb"

account_handler::account_handler()
{
    userdb = QSqlDatabase::addDatabase("QSQLITE");
    userdb.setDatabaseName(PATH_TO_DB);
    QFileInfo checkFile(PATH_TO_DB);

}
 bool account_handler::isOpen(){
     if(userdb.open()){
         return 1;
     }else{
         return 0;
     }
 }
void account_handler::close(){
    userdb.close();
}
account_handler::~account_handler(){
    userdb.close();
}
