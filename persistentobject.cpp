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
    qDebug() << "--- ADD ATTRIBUTE ---" ;
    attributes->append(&nouvel_attribut);
}

int persistentObject::save()
{
    return 0;
}
