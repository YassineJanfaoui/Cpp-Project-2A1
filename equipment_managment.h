#ifndef EQUIPMENT_MANAGMENT_H
#define EQUIPMENT_MANAGMENT_H

#include <QMainWindow>
#include "equipment.h"

QT_BEGIN_NAMESPACE
namespace Ui { class equipment_managment; }
QT_END_NAMESPACE

class equipment_managment : public QMainWindow
{
    Q_OBJECT

public:
    equipment_managment(QWidget *parent = nullptr); //constructor of class
    ~equipment_managment(); //destructor of class

private slots:
    void on_menu_clicked(); //slot n3aytoulha ki nenzlou 3al boutons

    void on_pushButton_8_clicked();

    void on_display_eq_doubleClicked(const QModelIndex &index);

    void on_display_eq_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::equipment_managment *ui;
    Equipment E;
};
#endif // EQUIPMENT_MANAGMENT_H
