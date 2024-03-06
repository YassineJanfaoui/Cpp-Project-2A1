#ifndef CLIENTMANAGEMENT_H
#define CLIENTMANAGEMENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientManagement; }
QT_END_NAMESPACE

class ClientManagement : public QMainWindow
{
    Q_OBJECT

public:
    ClientManagement(QWidget *parent = nullptr);
    ~ClientManagement();

private slots:
    void on_pushButton_10_clicked();

private:
    Ui::ClientManagement *ui;
};
#endif // CLIENTMANAGEMENT_H
