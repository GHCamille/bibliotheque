#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "persistentobject.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //BEGIN SQL
    //Chargement du pilote
    QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"));
    //END SQL

    QString *point_auteur = new QString("J.K Rowling");
    QString *point_titre = new QString("Harry Potter et la Coupe de feu");
    QString *point_isbn = new QString("6271538R5635");
    int int_annee = 2002;
    int *point_annee = &int_annee;

    persistentAttribute auteur(QString("auteur"),QVariant::String, point_auteur);
    persistentAttribute titre(QString("titre"),QVariant::String, point_titre);
    persistentAttribute isbn(QString("isbn"),QVariant::String, point_isbn);
    persistentAttribute annee(QString("annee"),QVariant::Int, point_annee);
    persistentObject livre(QString("livre"));
    
    livre.addAttribute(auteur);
    livre.addAttribute(titre);
    livre.addAttribute(isbn);
    livre.addAttribute(annee);
    
    MainWindow w;
    w.show();

    return app.exec();
}
