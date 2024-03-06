#include "equipment.h"
#include "QSqlQuery"
#include "QDebug"
#include "equipment_managment.h"
#include <QObject>
Equipment::Equipment() //initialisation
{
    equipment_id = 0;
    name = "";
    type = "";
    status = "";
    purchase_price = 0;
    purchase_date = QDate::currentDate();

}
Equipment::Equipment(int id, QString n, QString t, QDate d, float price, QString s) {
    this->equipment_id = id; //affectation de id
    this->name = n;
    this->type = t;
    this->purchase_date = d;
    this->purchase_price = price;
    this->status = s;
}


void Equipment::setequipment_id( int id)
{
    equipment_id = id; //Define the id
}

int Equipment::getequipment_id()
{
    return equipment_id; //recuperate id
}

void Equipment::setName(QString Name)
{
    name = Name;
}

QString Equipment::getName()
{
    return name;
}

void Equipment::settype(QString type)
{
    this->type = type;
}

QString Equipment::gettype()
{
    return type;
}

void Equipment::set_purchase_price(float price)
{
    purchase_price = price;
}

float Equipment::getpurchase_price()
{
    return purchase_price;
}

void Equipment::set_status(QString status)
{
    this->status = status;
}

QString Equipment::getstatus()
{
    return status;
}

void Equipment::set_purchase_date(QDate date)
{
    purchase_date = date;
}

QDate Equipment::pruchase_date()
{
    return purchase_date;
}
bool Equipment::ADD_eq () {
    QSqlQuery query; //declarina sql  bch executina les requets sql
    QString res = QString::number(equipment_id); //conversion id en string
    QString purchasePriceString = QString::number(purchase_price);//kifkif
    query.prepare("INSERT INTO equipment (equipment_id, name, type, purchase_date, purchase_price, status) "
                      "VALUES (:equipment_id, :name, :type, :purchase_date, :purchase_price, :status)");

    query.bindValue(":equipment_id", equipment_id);//rbatna les valeurs sql m3a qt
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":purchase_date", purchase_date);
    query.bindValue(":purchase_price", purchase_price);
    query.bindValue(":status", status);


    bool success = query.exec();

    return success; //yerturni  true ki yebde reussi
}
QSqlQueryModel* Equipment::Display_eq()
{
    QSqlQueryModel* model=new QSqlQueryModel(); //bch nestoki result of sql

          model->setQuery("SELECT * FROM EQUIPMENT"); //nselectioniw tt les resultats
          //model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          //model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));

    return model; //nretourniw results
}
bool Equipment::Delete_eq(int ID){
    QSqlQuery query; //declarina objet bch n3mel sql execution
    query.prepare("delete from Equipment where equipment_id=:ID"); //prepari bch nfasakh
    query.bindValue(":ID", ID); //link m3a id


    return query.exec();
}
bool Equipment::update(int equipment_id, QString name, QString type, float purchase_price, QString status, QDate purchase_date) {
    QSqlQuery query; //creation of query

    QString purchase_pprice = QString::number(purchase_price); //convert int to string
    QString id_string = QString::number(equipment_id); //convert id to string
    query.prepare("UPDATE EQUIPMENT SET NAME = :name, TYPE = :type, PURCHASE_PRICE = :purchase_price, STATUS = :status, PURCHASE_DATE = TO_DATE(:purchase_date, 'YYYY-MM_DD') WHERE EQUIPMENT_ID = :equipment_id");
    query.bindValue(":equipment_id",id_string );
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":purchase_price", purchase_pprice);
    query.bindValue(":status", status);
    query.bindValue(":purchase_date", purchase_date.toString("yyyy-MM-dd"));
    return query.exec();
}
