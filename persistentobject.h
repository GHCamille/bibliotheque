#ifndef PERSISTENTOBJECT_H
#define PERSISTENTOBJECT_H

#include <QList>
#include "persistentattribute.h"

class persistentObject
{
public:
    persistentObject(QString className); // Le constructeur
    ~persistentObject(void);       // Le destructeur.
    void addAttribute(persistentAttribute nouvel_attribut);
    //void print(void); // Fonction d'affichage de l'objet
    int save();

private:
    QList<persistentAttribute*> *attributes;
    QString *table;
    int id;
};

#endif // PERSISTENTOBJECT_H
