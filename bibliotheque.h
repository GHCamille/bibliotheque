#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include "persistentobject.h"

class bibliotheque
{
public:
    bibliotheque();
    bibliotheque(QString nom, QList<persistentObject*> liste);
    QString dbName;
    QList <persistentObject*> liste_livres;
};

#endif // BIBLIOTHEQUE_H
