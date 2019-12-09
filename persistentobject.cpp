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
    QString auteur;
    QList<persistentAttribute*> temp = *attributes;
    QVariant type_auteur = temp[0]->type;

    if (type_auteur == QVariant::String)
       {
           QString *donneeString = static_cast<QString*>(temp[0]->data); // cast from void* to QString*
           qDebug() << "INSIDE valeur pointeur attribut : " << *donneeString;
           auteur = *donneeString;
       }
    return auteur;
}

QString persistentObject::getTitre()
{
    QString titre;
    QList<persistentAttribute*> temp = *attributes;
    QVariant type_titre = temp[0]->type;

    if (type_titre == QVariant::String)
       {
           QString *donneeString = static_cast<QString*>(temp[1]->data); // cast from void* to QString*
           qDebug() << "INSIDE valeur pointeur attribut : " << *donneeString;
           titre = *donneeString;
       }
    return titre;
}

QString persistentObject::getISBN()
{
    QString ISBN;
    QList<persistentAttribute*> temp = *attributes;
    QVariant type_ISBN = temp[0]->type;

    if (type_ISBN == QVariant::String)
       {
           QString *donneeString = static_cast<QString*>(temp[2]->data); // cast from void* to QString*
           qDebug() << "INSIDE valeur pointeur attribut : " << *donneeString;
           ISBN = *donneeString;
       }
    return ISBN;
}

int persistentObject::getAnnee()
{
    int annee;
    QList<persistentAttribute*> temp = *attributes;
    QVariant type_annee = temp[0]->type;

    if (type_annee == QVariant::Int)
       {
           int* donneeInt = static_cast<int*>(temp[3]->data); // cast from void* to QString*
           qDebug() << "BLABLABLASTATIC : " << static_cast<int*>(temp[3]->data);
           qDebug() << "INSIDE valeur pointeur attribut : " << *donneeInt;
           annee = *donneeInt;
       }
    return annee;
}
