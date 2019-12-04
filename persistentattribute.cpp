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
    qDebug() << "adresse pointeur auteur : " << donnee;
    qDebug() << "valeur pointeur auteur : " << *donnee;
//    if (type == QVariant::String)
//    {
//        QString *point_donnee = new QString(*donnee);
//        data=point_donnee;
//    }
//    if (type == QVariant::Int)
//    {
//        int int_annee = 2002;
//        int *point_annee = &int_annee;
//        data=point_annee;
//    }



//    data=&donnee;
                 // void * = A pointer to void is a "generic" pointer type.
                 // A void * can be converted to any other pointer type without an explicit cast.
                 // You cannot dereference a void * or do pointer arithmetic with it; you must
                 // convert it to a pointer to a complete data type first.
}





