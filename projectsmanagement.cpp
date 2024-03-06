#include "projectsmanagement.h"
#include "ui_projectsmanagement.h"
#include "project.h"
#include "connection.h"

ProjectsManagement::ProjectsManagement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProjectsManagement)
{
    ui->setupUi(this);
}

ProjectsManagement::~ProjectsManagement()
{
    delete ui;
}

