#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class WorkshopManagement; }
QT_END_NAMESPACE

class WorkshopManagement : public QMainWindow
{
    Q_OBJECT

public:
    WorkshopManagement(QWidget *parent = nullptr);
    ~WorkshopManagement();

private slots:

    void on_nextStack2_clicked();

    void on_nextStack1_clicked();

    void on_menu_clicked();

private:
    Ui::WorkshopManagement *ui;
};
#endif // MAINWINDOW_H
