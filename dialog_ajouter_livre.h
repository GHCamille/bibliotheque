#ifndef DIALOG_AJOUTER_LIVRE_H
#define DIALOG_AJOUTER_LIVRE_H

#include "persistentobject.h"
#include <QDialog>

namespace Ui {
class Dialog_ajouter_livre;
}

class Dialog_ajouter_livre : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ajouter_livre(QWidget *parent = 0);
    ~Dialog_ajouter_livre();

public slots:
    void infos_nouveau_livre();

private:
    Ui::Dialog_ajouter_livre *ui;
};

#endif // DIALOG_AJOUTER_LIVRE_H
