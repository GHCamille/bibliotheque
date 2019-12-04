#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
