#include "connection.h"

connection::connection()
{

}
bool connection::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
     db.setDatabaseName("source_project2A");
     db.setUserName("MounaB");//insert the user name
     db.setPassword("esprit2022");//inseret the password

    if (db.open())
        test=true;





    return  test;
}
