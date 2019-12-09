﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "persistentobject.h"
#include "dialog_ajouter_livre.h"
#include "ui_dialog_ajouter_livre.h"
#include "bibliotheque.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    // il faut créér la bibliotheque (= espace de stockage des livres)
    bib()
{
    ui->setupUi(this);

    // On fait les connexions IHM->fonctions :
    QObject::connect(ui->actionNouveau, SIGNAL(triggered()), this, SLOT(creerBibliotheque())); // mettre creer bibliotheque dans classe bibliotheque OU ALORS faire que creer bibliotheque déclenche une fonction de la classe bibliotheque qui est en fait un signal que l'on connecte au à un slot qui def le nom de la bibliotheque dans le main
    QObject::connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(ouvrirBibliotheque()));
    QObject::connect(ui->actionSauvegarder, SIGNAL(triggered()), this, SLOT(sauverBibliotheque()));
    QObject::connect(ui->actionSauvegarder_sous, SIGNAL(triggered()), this, SLOT(sauverBibliothequeSous()));
    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(fermerAppli()));
    QObject::connect(ui->actionAjouter_un_livre, SIGNAL(triggered()), this, SLOT(ajouterLivre()));
    QObject::connect(ui->actionRetirer_un_livre, SIGNAL(triggered()), this, SLOT(retirerLivre()));
    QObject::connect(ui->actionDocumentation, SIGNAL(triggered()), this, SLOT(documentation()));
    QObject::connect(ui->actionUn_probl_me, SIGNAL(triggered()), this, SLOT(unProbleme()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::creerBibliotheque()
{
    QString nom_fichier = QFileDialog::getSaveFileName(NULL, "Ouvrir une nouvelle bibliothèque.","C:/Users/Utilisateur/Documents/Cours/Qt_Projet", "Database (*.db)");
    bib.dbName = nom_fichier;
}

void MainWindow::ouvrirBibliotheque()
{
    QString nom_fichier = QFileDialog::getOpenFileName(this, "Ouvrir une bibliothèque", "C:/Users/Utilisateur/Documents/Cours/Qt_Projet", "Database (*.db)");
    qDebug() << "Le nom du fichier : " << nom_fichier;
    bib.dbName = nom_fichier;
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"),"openLibConnection");
        db.setDatabaseName(nom_fichier);
        db.open();

        if(!db.isOpen())
        {
            QMessageBox::warning(this, "Erreur","Impossible d'ouvrir la bbibliothèque.");
        }
        else
        {
            QSqlQuery query("SELECT * FROM livre;", db);
            while (query.next())
            {
                QString db_auteur = query.value(1).toString();
                QString db_titre = query.value(2).toString();
                QString db_isbn = query.value(3).toString();
                int int_annee = query.value(4).toInt();

                QString *point_auteur = new QString(db_auteur);
                QString *point_titre = new QString(db_titre);
                QString *point_isbn = new QString(db_isbn);
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
                bib.liste_livres.append(&livre);
            }
            db.close();
        }
    }
    QSqlDatabase::removeDatabase("openLibConnection");
    updateBookList();
}

void MainWindow::sauverBibliotheque()
{
    qDebug() << QString("sauverBibliotheque");
    
    updateBookList();

    QString nom_fichier = bib.dbName;

    {
        QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"),"saveLibConnection");
        db.open();
        db.setDatabaseName(nom_fichier);

        if(!db.isOpen())
        {
            QMessageBox::warning(this, "Erreur","Impossible d'ouvrir la bibliothèque.");
        }
        else
        {
            for (persistentObject *livre: bib.liste_livres)
            {
                qDebug() << "Piou";
//                           for (persistentAttribute attrib: livre.attributes)
//               {
//                  qDebug() << "Hello " << attrib.data;
//               }
            }
        }
        db.close();
    }
    QSqlDatabase::removeDatabase("saveLibConnection");
    qDebug() << "Connection closed";

}

void MainWindow::sauverBibliothequeSous()
{
    // QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Database (*.db)");
    qDebug() << QString("sauverBibliothequeSous");
}

void MainWindow::ajouterLivre()
{
    // add row in BDD
    // on définit les attributs persistants du livre (un par colonne de la BDD)
    // il va falloir ajouter le livre à la QList de la bibliotheque walala
    Dialog_ajouter_livre dialog_ajouter_livre;
    dialog_ajouter_livre.setModal(true);
    dialog_ajouter_livre.exec();
}

void MainWindow::retirerLivre()
{
    // delete row in BDD
    // il va falloir le supprimer de la QList de la bibliotheque
    qDebug() << QString("retirerLivre");
}

void MainWindow::fermerAppli()
{
    // eventuellement enregistrer les DB ??
    this->close();
}

void MainWindow::updateBookList()
{

    qDebug() << QString("JE rentre dans update");

    ui->tableWidget->clearContents();

    QList<persistentObject*> liste_livres_total = bib.liste_livres;

    ui->tableWidget->setRowCount(liste_livres_total.count());

   // qDebug() << "Biblio : " << bib;
    qDebug() << "Liste de livre : " << liste_livres_total;
    qDebug() << "NOMBRE DE LIVRE DANS LA BIBLIO : " << liste_livres_total.count();

    for (int i=0; i < liste_livres_total.count(); i++)
    {
        persistentObject livre = *liste_livres_total.at(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(livre.getAuteur()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(livre.getTitre()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(livre.getISBN()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(livre.getAnnee())));
    }

//    QString *point_auteur = new QString("J.K Rowling");
//    QString *point_titre = new QString("Harry Potter et la Coupe de feu");
//    QString *point_isbn = new QString("6271538R5635");
//    int int_annee = 2002;
//    int *point_annee = &int_annee;

//    persistentAttribute auteur(QString("auteur"),QVariant::String, point_auteur);
//    persistentAttribute titre(QString("titre"),QVariant::String, point_titre);
//    persistentAttribute isbn(QString("isbn"),QVariant::String, point_isbn);
//    persistentAttribute annee(QString("annee"),QVariant::Int, point_annee);
//    persistentObject livre(QString("livre"));

//    livre.addAttribute(auteur);
//    livre.addAttribute(titre);
//    livre.addAttribute(isbn);
//    livre.addAttribute(annee);

//    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(livre.getAuteur()));
//    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(livre.getTitre()));
//    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(livre.getISBN()));
//    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(livre.getAnnee())));

    qDebug() << QString("JE SORS PRENDS LA CLEF");
}

void MainWindow::documentation()
{
    QMessageBox::information(this, "Documentation", "Documentation à écrire.");
}

void MainWindow::unProbleme()
{
    QMessageBox::information(this, "Help", "Aide à écrire ?");
}
