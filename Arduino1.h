#ifndef ARDUINO1_H
#define ARDUINO1_H
#include<QDateTime>

class arduino1{
public:
    arduino1 (QString date1){this->date_ajout=date1;};
bool ajouter();
QString date_ajout;
};
#endif // ARDUINO1_H
