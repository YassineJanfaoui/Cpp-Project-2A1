#include "client.h"

Client::Client()
{

}
Client::Client(int id, const QString& name, const QString& gender, const QString& phoneNumber, const QDate& membershipDate, const QString& email)
    : id(id), name(name), gender(gender), phoneNumber(phoneNumber), membershipDate(membershipDate), email(email)
{
}

Client::Client(const Client& other)
    : id(other.id), name(other.name), gender(other.gender), phoneNumber(other.phoneNumber), membershipDate(other.membershipDate), email(other.email)
{
}
