#include "persistentobject.h"

persistentObject::persistentObject(QString className)
{
//    QList<persistentAttribute> attributes;
}

void persistentObject::addAttribute(persistentAttribute nouvel_attribut)
{
    attributes->append(nouvel_attribut);
}


int persistentObject::save()
{
    return 0;
}
