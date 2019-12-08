﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "persistentobject.h"
#include "dialog_ajouter_livre.h"
#include "ui_dialog_ajouter_livre.h"
#include "bibliotheque.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionNouveau, SIGNAL(triggered()), this, SLOT(creerBibliotheque()));
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
    QString fichier = QFileDialog::getSaveFileName(NULL, "Ouvrir une nouvelle bibliothèque.","/home/camille/Git/bibliotheque/", "Database (*.db)");
//    bib.dbName = fichier;
}

void MainWindow::ouvrirBibliotheque()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir une bibliothèque", "/home/camille/Git/bibliotheque/", "Database (*.db)");
//    bib.dbName = fichier;
    QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"));

    db.setDatabaseName(fichier);
    db.open();

    if(!db.isOpen())
    {
        QMessageBox::warning(this, "Erreur","Impossible d'ouvrir la bbibliothèque.");
    }
    else
    {
        QSqlQuery query("SELECT * FROM livre;");
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
//            bib.liste_livres.append(&livre);
//                    append(&livre);
        }
    }
}

void MainWindow::sauverBibliotheque()
{
    // QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    qDebug() << QString("sauverBibliotheque");
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
    Dialog_ajouter_livre dialog_ajouter_livre;
    dialog_ajouter_livre.setModal(true);
    dialog_ajouter_livre.exec();
}

void MainWindow::retirerLivre()
{
    // delete row in BDD
    qDebug() << QString("retirerLivre");
}

void MainWindow::fermerAppli()
{
    // eventuellement enregistrer les DB ??
    this->close();
}

void MainWindow::documentation()
{
    QMessageBox::information(this, "Documentation", "Documentation à écrire.");
}

void MainWindow::unProbleme()
{
    QMessageBox::information(this, "Help", "Aide à écrire ?");
}
