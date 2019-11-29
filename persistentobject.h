#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include "persistentattribute.h"

class persistentObject
{
public:
    persistentObject(QString className);
    void addAttribute(persistentAttribute nouvel_attribut);
    int save();

private:
    QList<persistentAttribute*> *attributes;
    QString *table;
    int id;
};

#endif // PERSISTENTOBJECT_H
