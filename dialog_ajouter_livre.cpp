#include "dialog_ajouter_livre.h"
#include "ui_dialog_ajouter_livre.h"
#include "persistentattribute.h"

Dialog_ajouter_livre::Dialog_ajouter_livre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ajouter_livre)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonBox, SIGNAL(clicked()), this, SLOT(infos_nouveau_livre()));
}

Dialog_ajouter_livre::~Dialog_ajouter_livre()
{
    delete ui;
}

void Dialog_ajouter_livre::infos_nouveau_livre()
{
    QString auteur = ui->lineEdit->text();
    QString titre = ui->lineEdit_2->text();
    QString isbn = ui->lineEdit_3->text();
    QString string_annee = ui->lineEdit_4->text();
    int annee = string_annee.toInt();
    //QList<persistentAttribute *> livre =
}
