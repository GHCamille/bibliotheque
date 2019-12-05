#include "persistentattribute.h"
#include <QDebug>

persistentAttribute::persistentAttribute() // si on fait un attribut sans mettre de paramètres
{
    name=""; 
    type=QVariant::String;
    int p = 0;
    data = &p; // void pointer holds address of int 'p'

    return;
}


persistentAttribute::persistentAttribute(QString nom, QVariant::Type attributType, void *donnee) // si on fait un attribut avec tous les paramètres
{
    name=nom;
    type=attributType;
    data = donnee;
}





