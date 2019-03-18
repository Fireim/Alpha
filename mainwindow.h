#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_validerButton_clicked();

private:
    Ui::MainWindow *ui;

    QString mot = "";
    QString lettreDispo = "A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z";
    QString lettreUtilisee = "";
    //QString lettreDispoFinal = "A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z";
    //QString lettreUtiliseeFinal = "";

    int joueur = 1;
    int pointJ1 = 0;
    int pointJ2 = 0;
    int protection = 0;
    int protection2 = 0;
    int drapeau = 0;
};

#endif // MAINWINDOW_H
