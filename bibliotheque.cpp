#include "bibliotheque.h"

bibliotheque::bibliotheque()
{
    dbName = "";
    liste_livres = QList<persistentObject*>();
}


bibliotheque::bibliotheque(QString nom, QList<persistentObject*> liste)
{
    dbName = nom;
    liste_livres = liste;
}
