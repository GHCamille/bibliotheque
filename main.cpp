#include "mainwindow.h"
#include "livre.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //BEGIN SQL
    //Chargement du pilote
    QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"));
    //END SQL
//    QVariant text;
//    qDebug() << "typeName for first :" << auteur.typeName();
//    qDebug() << "Type : " << auteur.type();



    const char *point_auteur("J.K Rowling");
    persistentAttribute auteur(QString("auteur"),QVariant::String, &point_auteur);
    const char *point_titre("Harry Potter et la Coupe de feu");
    persistentAttribute titre(QString("titre"),QVariant::String, &point_titre);
    const char *point_isbn("6271538R5635");
    persistentAttribute isbn(QString("isbn"),QVariant::String, &point_isbn);
    int point_annee = 2002;
    persistentAttribute annee(QString("annee"),QVariant::Int, &point_annee);

    persistentObject livre(QString("livre"));
    // JUSQUE LÀ ON EST BONS

    //livre.*attributes = QList<attributes*> list({&auteur, &titre, &isbn, &annee});
    
    MainWindow w;
    w.show();

    return app.exec();
}
