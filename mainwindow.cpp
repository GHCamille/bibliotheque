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

    // Setup book list
    QStringList entetes;
    entetes << "Titre" << "Auteur(s)" << "Année" << "ISBN";
    ui->tableWidget->setColumnCount(entetes.count());
    ui->tableWidget->setHorizontalHeaderLabels(entetes);
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->clearContents();
    ui->tableWidget->setUpdatesEnabled(true);
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
    
//    updateBookList();

    QString nom_fichier = bib.dbName;

    {
        QSqlDatabase db = QSqlDatabase::addDatabase(("QSQLITE"),"saveLibConnection");
        db.setDatabaseName(nom_fichier);
        db.open();

        if(!db.isOpen())
        {
            QMessageBox::warning(this, "Erreur","Impossible d'ouvrir la bibliothèque.");
        }
        else
        {
            qDebug() << "NOMBRE DE LIVRES = " << bib.liste_livres.count();
            for (int i=0; i < bib.liste_livres.count(); i++)
            {
                persistentObject livre = *bib.liste_livres.at(i);

//                QString livre_auteur = livre.getAuteur();
//                QString livre_titre = livre.getTitre();
//                QString livre_isbn = livre.getISBN();
//                int livre_annee = livre.getAnnee();

                QString livre_auteur = QString("J.K Rowling");
                QString livre_titre = QString("Harry Potter et le Prisonnier d'Azkaban");
                QString livre_isbn = QString("6271538R5635");
                int livre_annee = 2002;

                QSqlQuery query(db);

//                QString tableName = db.tables().at(0);
//                QSqlRecord record = db.driver()->record(tableName);
//                int nbfields = record.count();
//                qDebug() << "NOMBRE DE COL" << nbfields;
//                qDebug() << "COLONNE 1 " << record.field(0);
//                qDebug() << "COLONNE 2 " << record.field(1);
//                qDebug() << "COLONNE 3 " << record.field(2);
//                qDebug() << "COLONNE 4 " << record.field(3);
//                qDebug() << "COLONNE 5 " << record.field(4);

//                bool result = query.prepare("INSERT INTO livre(id, nom, titre, ISBN, annee) "
//                                            "VALUES (:id, :auteur, :titre, :isbn, :annee)");
//                qDebug() << "PREPARATION DE LA QUERY" << result;

                query.prepare("INSERT INTO livre(id, nom, titre, ISBN, annee) "
                                            "VALUES (:id, :auteur, :titre, :isbn, :annee)");
                query.bindValue(":id", 2);
                query.bindValue(":auteur", "George R. R. Martin");
                query.bindValue(":titre", "A Game of Thrones");
                query.bindValue(":isbn", "FYDFYQVXKFH");
                query.bindValue(":annee", 1996);

//                bool result = query.prepare("INSERT INTO livre(id, auteur, titre, isbn, annee) "
//                                            "VALUES (?,?,?,?,?)");
//                qDebug() << "PREPARATION DE LA QUERY" << result;
//                query.addBindValue(3);
//                query.addBindValue("J.K Rowling");
//                query.addBindValue("J.K Rowling");
//                query.addBindValue("J.K Rowling");
//                query.addBindValue(3452);


                if(!query.exec())
                {
                    qDebug() << query.lastError().text();
                }
                else
                {
                    qDebug( "Inserted!" );
                }
                // SAVE BIBIOTHEQUE
            }
//            if (QFile::exists(nom_fichier))
//            {
//                QFile::remove(nom_fichier);
//            }

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
    updateBookList();
}

void MainWindow::retirerLivre()
{
    // delete row in BDD
    // il va falloir le supprimer de la QList de la bibliotheque
    qDebug() << QString("retirerLivre");
    updateBookList();
}

void MainWindow::fermerAppli()
{
    // eventuellement enregistrer les DB ??
    this->close();
}

void MainWindow::updateBookList()
{

    ui->tableWidget->clearContents();

    QList<persistentObject*> liste_livres_total = bib.liste_livres;
    ui->tableWidget->setRowCount(liste_livres_total.count());

    for (int i=0; i < liste_livres_total.count(); i++)
    {
        persistentObject livre = *liste_livres_total.at(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(livre.getAuteur()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(livre.getTitre()));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(livre.getISBN()));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(livre.getAnnee())));
    }
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setVisible(true);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->setUpdatesEnabled(true);

}

void MainWindow::documentation()
{
    QMessageBox::information(this, "Documentation", "Documentation à écrire.");
}

void MainWindow::unProbleme()
{
    QMessageBox::information(this, "Help", "Aide à écrire ?");
}
