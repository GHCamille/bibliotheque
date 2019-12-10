#include "persistentobject.h"
#include <QDebug>

persistentObject::persistentObject(QString className)
{
    attributes = new QList<persistentAttribute*>();
    table = &className; // QString pointer holds address of QString 'className'
}

persistentObject::~persistentObject()
{

}

void persistentObject::addAttribute(persistentAttribute nouvel_attribut)
{
    attributes->append(&nouvel_attribut);
}

int persistentObject::save()
{
    return 0;
}

QList<persistentAttribute*> persistentObject::getAttributes()
{
    return *attributes;
}

QString persistentObject::getAuteur()
{
    QList<persistentAttribute*> temp = *attributes;
    return *static_cast<QString*>(temp[0]->data);
}

QString persistentObject::getTitre()
{
    QList<persistentAttribute*> temp = *attributes;
    return *static_cast<QString*>(temp[1]->data);
}

QString persistentObject::getISBN()
{
    QList<persistentAttribute*> temp = *attributes;
    return *static_cast<QString*>(temp[2]->data);
}

int persistentObject::getAnnee()
{
    QList<persistentAttribute*> temp = *attributes;
    return *static_cast<int*>(temp[3]->data);
}
