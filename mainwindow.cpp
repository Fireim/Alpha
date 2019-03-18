#include "mainwindow.h"
#include "jeu.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_validerButton_clicked()
{
    Jeu *jeu = new Jeu;
    ui->notif->setText("");
    mot = ui->MotEdit->toPlainText();
    mot = mot.toUpper();
    protection = 0;
    protection2 = 0;
    //jeu->ProtectionMot(mot, &protection2, &drapeau);
    if (protection2 == 1)
    {
        ui->MotEdit->clear();
        ui->notif->setText("Ce mot n'existe pas voyons !");
    }
    else
    {
        jeu->Tour(&joueur, mot, &lettreDispo, &lettreUtilisee, &pointJ1, &pointJ2, &protection);

        if (protection == 1)
        {
            ui->MotEdit->clear();
            ui->notif->setText("Lettre déjà utilisée, veuillez taper un nouveau mot");
        }
        else
        {
            //jeu->Style(&lettreDispo, &lettreDispoFinal);
            if (joueur == 1)
            {
                ui->pointJ1->display(pointJ1);
                ui->lettreDispo->setText(lettreDispo);
                ui->lettreUtilisee->setText(lettreUtilisee);
            }
            else if (joueur == 2)
            {
                ui->pointJ2->display(pointJ2);
                ui->lettreDispo->setText(lettreDispo);
                ui->lettreUtilisee->setText(lettreUtilisee);
            }

            ui->MotEdit->clear();

            jeu->ChangerTour(&joueur);
            ui->notif->setText("");
            if (joueur == 1)
            {
                ui->tourNotif->setText("Au tour du joueur 1");
            }
            else if (joueur == 2)
            {
                ui->tourNotif->setText("Au tour du joueur 2");
            }
        }
    }
    delete jeu;
}
