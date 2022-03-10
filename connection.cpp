#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_projet2A");
db.setUserName("Aziz");//inserer nom de l'utilisateur
db.setPassword("aziz");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
