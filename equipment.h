#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Equipment
{
public:
    //constructor
    Equipment();
    Equipment(int,QString,QString,QDate,float,QString);
    //getter and setter
    void setequipment_id(int);
    int getequipment_id();
    void setName(QString) ;
    QString getName();
    void settype(QString) ;
    QString gettype();
    void set_purchase_price(float) ;
    float getpurchase_price();
    void set_status(QString) ;
    QString getstatus();
    void set_purchase_date(QDate) ;
    QDate pruchase_date() ;
    bool ADD_eq(); //fct to add
    QSqlQueryModel* Display_eq(); //display min database
    bool Delete_eq(int); //fct delete return bool
    bool update(int, QString,QString,float,QString,QDate);

private:
    int equipment_id;
    QString name,type,status;
    int purchase_price;
    QDate purchase_date;
};

#endif // EQUIPMENT_H

