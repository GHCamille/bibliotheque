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

public slots:
    void setNameBib(QString name_bib);

};

#endif // BIBLIOTHEQUE_H
