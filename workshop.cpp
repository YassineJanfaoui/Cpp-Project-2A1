#include "workshop.h"

Workshop::Workshop()
{

}
Workshop::Workshop(int id, const QString& name, const QString& desc, int maxParticip, int nbrParticip, const QDate& startDate, int duration)
    : IDWorkshop(id), NameWorkshop(name), DescWorkshop(desc), MaxParticip(maxParticip), NbrParticip(nbrParticip), StartDate(startDate), Duration(duration)
{

}

Workshop::Workshop(const Workshop& other)
    : IDWorkshop(other.IDWorkshop), NameWorkshop(other.NameWorkshop), DescWorkshop(other.DescWorkshop),
      MaxParticip(other.MaxParticip), NbrParticip(other.NbrParticip), StartDate(other.StartDate), Duration(other.Duration)
{

}
