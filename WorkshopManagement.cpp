#include "WorkshopManagement.h"
#include "ui_WorkshopManagement.h"
#include "menu.h"


WorkshopManagement::WorkshopManagement(QWidget *parent):
    QMainWindow(parent),
     ui(new Ui::WorkshopManagement)
{
    ui->setupUi(this);
}

WorkshopManagement::~WorkshopManagement()
{
    delete ui;
}



void WorkshopManagement::on_nextStack2_clicked()
{
    ui->stack->setCurrentWidget(ui->editPage);
}

void WorkshopManagement::on_nextStack1_clicked()
{
    ui->stack->setCurrentWidget(ui->addPage);
}

void WorkshopManagement::on_menu_clicked()
{
        menu *newWindow = new menu;
       newWindow->show();
       hide();
}
