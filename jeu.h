#ifndef JEU_H
#define JEU_H
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QFile>

class Jeu
{
public:
    Jeu();
    void Tour(int *pJoueur, QString &mot, QString *pLettreDispo, QString *pLettreUtilisee, int *pPointJ1, int *pPointJ2, int *pProtection);
    void ChangerTour(int *pJoueur);
    void ProtectionMot(QString &mot, int *pProtection2, int *pDrapeau);
    //void Style(QString *pLettreDispo, QString *pLettreDispoFinal);
};

#endif // JEU_H
