#include "mainwindow.h"
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
    QString nom_fichier = QFileDialog::getSaveFileName(NULL, "Ouvrir une nouvelle bibliothèque.","/home/camille/Git/bibliotheque/", "Database (*.db)");
    bib.dbName = nom_fichier;
}

void MainWindow::ouvrirBibliotheque()
{
    QString nom_fichier = QFileDialog::getOpenFileName(this, "Ouvrir une bibliothèque", "/home/camille/Git/bibliotheque/", "Database (*.db)");
    bib.dbName = nom_fichier;
    QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"));
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
            bib.liste_livres.append(&livre);
        }
    }
}

void MainWindow::sauverBibliotheque()
{
    // QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    qDebug() << QString("sauverBibliotheque");
    updateBookList();
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
    qDebug() << QString("AM IN UPDATE MAGGLE");

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(1);

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

    QVariant type_auteur = livre.getAttributes()[0]->type;
    QString machin = "";

    if (type_auteur == QVariant::String)
       {
           QString *donneeString = static_cast<QString*>(livre.getAttributes()[0]->data); // cast from void* to QString*
           qDebug() << "INSIDE valeur pointeur attribut : " << *donneeString;
           machin = *donneeString;
       }


    QVariant type_titre = livre.getAttributes()[1]->type;
    QString truc = "";

    if (type_titre == QVariant::String)
       {
           QString *donneeString = static_cast<QString*>(livre.getAttributes()[1]->data); // cast from void* to QString*
           qDebug() << "INSIDE valeur pointeur attribut : " << *donneeString;
           truc = *donneeString;
       }

    QVariant type_isbn = livre.getAttributes()[1]->type;
    QString chose = 0;

    if (type_titre == QVariant::String)
       {
           QString *donneeString = static_cast<QString*>(livre.getAttributes()[2]->data); // cast from void* to QString*
           qDebug() << "INSIDE valeur pointeur attribut : " << *donneeString;
           chose = *donneeString;
       }
    if (type_titre == QVariant::Int)
       {
           int *donneeInt = static_cast<int*>(livre.getAttributes()[3]->data); // cast from void* to int*
           qDebug() << "INSIDE valeur pointeur attribut : " << *donneeInt;
           chose = *donneeInt;
       }


    //QString auteur_test = livre.getAttributes()[0]->data;

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(machin));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(truc));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(chose));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem("moi aussi"));

    qDebug() << QString("JE SORS PRENDS LA CLEF");

//    QList<Book> books = library.getBooks();
//    ui->tableWidget->setRowCount(books.count());

//    for (int i=0; i < books.count(); i++)
//    {
//        Book book = books.at(i);
//        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(*book.getTitle()));
//        ui->tableWidget->setItem(i, 1, new QTableWidgetItem((*book.getAuthors()).join(", ")));
//        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(*book.getPublicationYear())));
//        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(*book.getISBN()));
//    }
}

void MainWindow::documentation()
{
    QMessageBox::information(this, "Documentation", "Documentation à écrire.");
}

void MainWindow::unProbleme()
{
    QMessageBox::information(this, "Help", "Aide à écrire ?");
}
