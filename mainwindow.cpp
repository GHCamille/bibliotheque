#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "persistentobject.h"
#include "dialog_ajouter_livre.h"
#include "ui_dialog_ajouter_livre.h"


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
    //Creer une bibliotheque devra revenir a creer une nouvelle BDD
    qDebug() << QString("debut creerBibliotheque");

//    //Chargement du pilote
//    QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"));

//    //On demande à l'utilisateur de rentrer un nom de son choix pour la nouvelle bibliothèque
//    QString dbName_ = QInputDialog::getText(this, "Nouvelle bibliothèque", "Nom de la nouvelle bibliothèque : ", QLineEdit::Normal);
//    QString dbName = dbName_ + ".db";

//    //Si le nom de la db est déjà pris, l'utilisateur doit en changer.
//    if( QFile::exists(dbName))
//    {
//        QMessageBox::warning(this, "Erreur nom","Une bibliothèque de même nom existe déjà. \n Merci de choisir un autre nom.");
//    }
//    else
//    {
//        db.setDatabaseName(dbName);
//        db.open();
//        if(!db.isOpen())
//        {
//            QMessageBox::warning(this, "Erreur","Impossible d'ouvrir la base de données.");
//        }
//        else
//        {
//            QSqlQuery query(db);
//            QString queryString = "CREATE TABLE content (id varchar(30) primary key, nom text, titre text, ISBN text, annee int);";
//            if (!query.exec(queryString))
//            {
//                QMessageBox::warning(this, "Erreur","Impossible de créer la base de données.");
//                qDebug() << query.lastError();
//            }
//        }
//    }
//}

//void MainWindow::ouvrirBibliotheque()
//{
//    QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"));
//    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Bibliothèques (*.db)");
//    qDebug() << QString(fichier);
//    QString dbName = fichier ;
//    db.setDatabaseName(dbName);
//    db.open();
//    QSqlQuery query(fichier);
//    QString queryString = "CREATE TABLE content (id varchar(30) primary key, nom text, titre text, ISBN text, annee int);";

}

void MainWindow::ouvrirBibliotheque()
{
    // QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    qDebug() << QString("ouvrirBibliotheque");
}

void MainWindow::sauverBibliotheque()
{
    // QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    qDebug() << QString("sauverBibliotheque");
}

void MainWindow::sauverBibliothequeSous()
{
    // QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    qDebug() << QString("sauverBibliothequeSous");
}

void MainWindow::ajouterLivre()
{
    // add row in BDD
//    QString auteur;
//    QString titre;
//    QString ISBN;
//    int annee;
//    livre persistentObject(QString auteur, QString titre, QString ISBN, int annee);
    qDebug() << QString("ajouterLivre");
    
    // on définit les attributs persistants du livre (un par colonne de la BDD)
    Dialog_ajouter_livre dialog_ajouter_livre;
    dialog_ajouter_livre.setModal(true);
    dialog_ajouter_livre.exec();
//    persistentAttribute auteur("auteur","TEXT",*);
//    persistentAttribute titre("titre","TEXT",*);
//    persistentAttribute isbn("isbn","TEXT",*);
//    persistentAttribute annee("annee","INT",*);
    
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
