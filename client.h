#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>


class Client
{
public:
    Client();
    Client(int id, const QString& name, const QString& gender, const QString& phoneNumber, const QDate& membershipDate, const QString& email);
    Client(const Client& other);

    int getID() const { return id; }
    QString getName() const { return name; }
    QString getGender() const { return gender; }
    QString getPhoneNumber() const { return phoneNumber; }
    QDate getMembershipDate() const { return membershipDate; }
    QString getEmail() const { return email; }

    void setID(int id) { this->id = id; }
    void setName(const QString& name) { this->name = name; }
    void setGender(const QString& gender) { this->gender = gender; }
    void setPhoneNumber(const QString& phoneNumber) { this->phoneNumber = phoneNumber; }
    void setMembershipDate(const QDate& membershipDate) { this->membershipDate = membershipDate; }
    void setEmail(const QString& email) { this->email = email; }

private:
    int id;
    QString name;
    QString gender;
    QString phoneNumber;
    QDate membershipDate;
    QString email;
};

#endif // CLIENT_H
