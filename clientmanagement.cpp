#include "clientmanagement.h"
#include "ui_clientmanagement.h"
#include "client.h"
#include "connection.h"
#include "menu.h"

ClientManagement::ClientManagement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientManagement)
{
    ui->setupUi(this);
}

ClientManagement::~ClientManagement()
{
    delete ui;
}



void ClientManagement::on_pushButton_10_clicked()
{
    menu *newWindow = new menu;
   newWindow->show();
   hide();
}
