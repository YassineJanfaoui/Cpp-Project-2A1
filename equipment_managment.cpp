#include "equipment_managment.h"
#include "ui_equipment_managment.h"
#include "menu.h"
#include "equipment.h"
#include "QMessageBox"
#include "QComboBox"

equipment_managment::equipment_managment(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::equipment_managment)
{
    ui->setupUi(this); //
    ui->display_eq->setModel(E.Display_eq());//star jey input controller
    ui->edit_id_eq->setValidator(new QIntValidator(1, 999999999, this));//tebloki matekteblkch
    ui->edit_price_eq->setValidator(new QIntValidator(1, 999999999, this));//tebloki matekteblkch
    ui->dateEdit_eq->setDate(QDate::currentDate());
    const QString namePattern = "^[A-Za-z ]{1,250}$"; //cntrl de s aisie name
        QValidator *nameValidator = new QRegularExpressionValidator(QRegularExpression(namePattern), this);
        ui->edit_name_eq->setValidator(nameValidator);

}

equipment_managment::~equipment_managment()
{
    delete ui; //delete the ui(interface) when equipment is closed
}


void equipment_managment::on_menu_clicked()
{
    menu *newWindow = new menu; //create new instance of menu window
    newWindow->show(); //display menu windiw
    hide(); //tkhabi menu window
}

void equipment_managment::on_pushButton_8_clicked()
{
        int id = ui->edit_id_eq->text().toInt(); //access to lineedit of the interface
        QString name = ui->edit_name_eq->text(); //declarina
        QString type = ui->edit_type_eq->currentText();
        QDate date = ui->dateEdit_eq->date();
        float price = ui->edit_price_eq->text().toFloat();
        QString status = ui->edit_status_eq->currentText();

        Equipment newEquipment(id, name, type, date, price, status);

        bool test=newEquipment.ADD_eq();
        if (test){
            ui->display_eq->setModel(E.Display_eq()); //to refresh
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("insertion successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("insertion failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }



void equipment_managment::on_display_eq_doubleClicked(const QModelIndex &index)
{
    if (index.isValid())
    {
        int row = index.row();
        QVariant id = ui->display_eq->model()->data(ui->display_eq->model()->index(row, 0));
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirm Deletion", "Are you sure you want to delete this equipment?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            if (E.Delete_eq(id.toInt()))
            {
                ui->display_eq->model()->removeRow(row);
                ui->display_eq->setModel(E.Display_eq());
            }
            else
            {
                QMessageBox::critical(this, "Error", "Failed to delete from the database.");
            }
        }
    }

}

void equipment_managment::on_display_eq_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        // Get the selected row
        int row = index.row();

        // Get data from the model for the selected row
        QString equipmentId = index.sibling(row, 0).data().toString();
        QString name = index.sibling(row, 1).data().toString();
        QString type = index.sibling(row, 2).data().toString();
        float purchasePrice = index.sibling(row, 3).data().toFloat();
        QString status = index.sibling(row, 4).data().toString();
        QDate purchaseDate = index.sibling(row, 5).data().toDate();

        // Display the data in appropriate UI elements
        ui->edit_id_eq->setText(equipmentId);
        ui->edit_name_eq->setText(name);
        int typeIndex = ui->edit_type_eq->findText(type);
                if (typeIndex != -1) {
                    ui->edit_type_eq->setCurrentIndex(typeIndex);
                }
        ui->edit_price_eq->setText(QString::number(purchasePrice));
        int statusIndex = ui->edit_type_eq->findText(status);
                if (statusIndex != -1) {
                    ui->edit_type_eq->setCurrentIndex(statusIndex);
        ui->dateEdit_eq->setDate(purchaseDate);
    }

}
}

void equipment_managment::on_pushButton_5_clicked()
{
    ui->edit_id_eq->clear();
    ui->edit_name_eq->clear();
    ui->edit_type_eq->clear();
    ui->dateEdit_eq->setDate(QDate::currentDate());
    ui->edit_price_eq->clear();
    ui->edit_status_eq->clear();
}

void equipment_managment::on_pushButton_9_clicked()
{
        int id = ui->edit_id_eq->text().toInt();
        QString name = ui->edit_name_eq->text();
        QString type = ui->edit_type_eq->currentText();
        QDate date = ui->dateEdit_eq->date();
        float price = ui->edit_price_eq->text().toFloat();
        QString status = ui->edit_status_eq->currentText();

        Equipment newEquipment(id, name, type, date, price, status);

        bool test=newEquipment.update(id,name,type,price,status,date);
        if (test){
            ui->display_eq->setModel(E.Display_eq()); //to refresh
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("update done.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }
