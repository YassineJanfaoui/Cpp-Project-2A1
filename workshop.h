#ifndef WORKSHOP_H
#define WORKSHOP_H
#include <QString>
#include <QDate>


class Workshop
{
public:
    Workshop();
    Workshop(int id, const QString& name, const QString& desc, int maxParticip, int nbrParticip, const QDate& startDate, int duration);
    Workshop(const Workshop& other);

    int getIDWorkshop() const { return IDWorkshop; }
    QString getNameWorkshop() const { return NameWorkshop; }
    QString getDescWorkshop() const { return DescWorkshop; }
    int getMaxParticip() const { return MaxParticip; }
    int getNbrParticip() const { return NbrParticip; }
    QDate getStartDate() const { return StartDate; }
    int getDuration() const { return Duration; }

    void setIDWorkshop(int id) { IDWorkshop = id; }
    void setNameWorkshop(const QString& name) { NameWorkshop = name; }
    void setDescWorkshop(const QString& desc) { DescWorkshop = desc; }
    void setMaxParticip(int maxParticip) { MaxParticip = maxParticip; }
    void setNbrParticip(int nbrParticip) { NbrParticip = nbrParticip; }
    void setStartDate(const QDate& startDate) { StartDate = startDate; }
    void setDuration(int duration) { Duration = duration; }

private:
    int IDWorkshop;
    QString NameWorkshop;
    QString DescWorkshop;
    int MaxParticip;
    int NbrParticip;
    QDate StartDate;
    int Duration;


};

#endif // WORKSHOP_H
