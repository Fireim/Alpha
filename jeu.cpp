#include "jeu.h"

Jeu::Jeu()
{
}

void Jeu::Tour(int *pJoueur, QString &mot, QString *pLettreDispo, QString *pLettreUtilisee, int *pPointJ1, int *pPointJ2, int *pProtection)
{
    QString lettreDispo2 = *pLettreDispo;
    QString lettreUtilisee2 = *pLettreUtilisee;
    int nbCarMot = QString::number(mot.size()).toInt();
    int nbCarDispo = QString::number(lettreDispo2.size()).toInt();
    int nbCarUtilisee = QString::number(lettreUtilisee2.size()).toInt();

    for (int i = 0; i < nbCarUtilisee; i++)
    {
        if (mot[0] == lettreUtilisee2[i])
        {
            *pProtection = 1;
        }
    }

    if (*pProtection == 0)
    {
        for (int i = 0; i < nbCarDispo; i++)
        {
            if (mot[0] == lettreDispo2[i])
            {
                lettreUtilisee2 += lettreDispo2[i];
                lettreUtilisee2 += "|";
                lettreDispo2.remove(i, 2);
            }
        }

        *pLettreDispo = lettreDispo2;
        *pLettreUtilisee = lettreUtilisee2;

        if (*pJoueur == 1)
        {
            *pPointJ1 += nbCarMot;
        }
        else if (*pJoueur == 2)
        {
            *pPointJ2 += nbCarMot;
        }
    }
}

void Jeu::ChangerTour(int *pJoueur)
{
    if (*pJoueur == 1)
    {
        *pJoueur = 2;
    }
    else if (*pJoueur == 2)
    {
        *pJoueur = 1;
    }
}

void Jeu::ProtectionMot(QString &mot, int *pProtection2, int *pDrapeau)
{
    QString nomFichier = "dico.txt";
    QFile fichier(nomFichier);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);
    QStringList dico2;
    QString ligne;
    int verif = 0;
    *pDrapeau = 1;

    if (*pDrapeau == 0)
    {
        *pDrapeau = 1;
        while (!flux.atEnd())
        {
            dico2 += flux.readLine();
        }
    }

    //while (! flux.atEnd())
    //{
        ligne = flux.readLine();
        if (mot == ligne)
            verif = 1;
        else
            verif = 0;
    //}

    //qDebug() << dico2;
    qDebug() << verif;
    if (verif == 1)
        *pProtection2 = 0;
    else
        *pProtection2 = 1;
}

/*void Jeu::Style(QString *pLettreDispo, QString *pLettreDispoFinal)
{
    QString lettreDispoFinal2 = *pLettreDispo;
    int nbCarDispo = QString::number(lettreDispoFinal2.size()).toInt();
    int n = 0;

    for (int i = 0; i < nbCarDispo; i++)
    {
        lettreDispoFinal2.insert(n, "|");
        n+=2;
    }

    lettreDispoFinal2.remove(0,1);
    *pLettreDispoFinal = lettreDispoFinal2;
}*/
