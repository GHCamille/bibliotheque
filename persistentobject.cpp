#include "persistentobject.h"
#include <QDebug>

persistentObject::persistentObject(QString className) : attributes(0)
{
    attributes = {};
    table = &className; // QString pointer holds address of QString 'className'
}

persistentObject::~persistentObject()
{

}

void persistentObject::addAttribute(persistentAttribute nouvel_attribut)
{
    qDebug() << "Ici nom de l'attribut :" << nouvel_attribut.name;
    qDebug() << "Ici type de l'attribut :" << nouvel_attribut.type;
    qDebug() << "Ici adresse data dans l'attribut :" << nouvel_attribut.data;
//    qDebug() << "Ici adresse data dans l'attribut :" << *nouvel_attribut.data;

//    //qDebug() << "Ici adresse pointeur :" << attributes; //attributes = adresse de la variable pointée ;
//    //qDebug() << "Ici valeur pointeur :" << *attributes; //attributes = valeur de la variable pointée ;
//    attributes->append(&nouvel_attribut);
////    qDebug() << "Ici :" << nouvel_attribut.name;
////    //qDebug() << "Ici :" << *attributes;
////    attributes << nouvel_attribut;

}


int persistentObject::save()
{
    return 0;
}

//void persistentObject::print(void) // Fonction d'affichage de l'objet
//{
//    persistentObject.attributes *tmp = head;
//    cout << "Sac n° " << handle() << "." << endl;
//    cout << "    Contenu :" << endl;

//    while (tmp != NULL)
//    {
//        cout << "\t";        // Indente la sortie des objets.
//        tmp->ptr->print();   // Affiche la liste objets.
//        tmp = tmp->next;
//    }
//    return;
//}

