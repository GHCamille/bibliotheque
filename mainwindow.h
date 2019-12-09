#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "persistentobject.h"
#include "bibliotheque.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QInputDialog>
#include <QDebug>
#include <QtSql>
#include <QFile>
#include <iostream>
#include <QFileDialog>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bibliotheque bib;


public slots:
    void creerBibliotheque();
    void ouvrirBibliotheque();
    void sauverBibliotheque();
    void sauverBibliothequeSous();
    void ajouterLivre();
    void retirerLivre();
    void fermerAppli();
    void documentation();
    void unProbleme();

signals:
    void setName_w(QString name);

};

#endif // MAINWINDOW_H
