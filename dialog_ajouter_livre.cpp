#include "dialog_ajouter_livre.h"
#include "ui_dialog_ajouter_livre.h"
#include "persistentobject.h"
#include <QDebug>

Dialog_ajouter_livre::Dialog_ajouter_livre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ajouter_livre)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(infos_nouveau_livre()));
}

Dialog_ajouter_livre::~Dialog_ajouter_livre()
{
    delete ui;
}

void Dialog_ajouter_livre::infos_nouveau_livre()
{
    QString user_input_auteur = ui->lineEdit->text();
    QString user_input_titre = ui->lineEdit_2->text();
    QString user_input_isbn = ui->lineEdit_3->text();
    QString user_input_string_annee = ui->lineEdit_4->text();
    int user_input_int_annee = user_input_string_annee.toInt();

    QString *point_auteur = new QString(user_input_auteur);
    QString *point_titre = new QString(user_input_titre);
    QString *point_isbn = new QString(user_input_isbn);
    int *point_annee = &user_input_int_annee;

    persistentAttribute auteur(QString("auteur"),QVariant::String, point_auteur);
    persistentAttribute titre(QString("titre"),QVariant::String, point_titre);
    persistentAttribute isbn(QString("isbn"),QVariant::String, point_isbn);
    persistentAttribute annee(QString("annee"),QVariant::Int, point_annee);

    persistentObject livre(QString("livre"));
    livre.addAttribute(auteur);
    livre.addAttribute(titre);
    livre.addAttribute(isbn);
    livre.addAttribute(annee);

    // [PLOT TWIST] les livres sont une donnée persistante, mais la bibliothèque aussi en fait



    // void * = A pointer to void is a "generic" pointer type.
    // A void * can be converted to any other pointer type without an explicit cast.
    // You cannot dereference a void * or do pointer arithmetic with it; you must
    // convert it to a pointer to a complete data type first.
}
