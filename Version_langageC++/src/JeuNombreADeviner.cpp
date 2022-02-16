/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud, Jean Lautraite
// Date de création : 21/01/2022
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio
//                              ctime, cstdlib
// Historique du fichier: 24/01/2022 -> Creation du projet sur CodeBlocks, ajout du code de la fonction jouerPartie
//                        26/01/2022 -> Codage et commentaires de la fonction jouerPartie
//                        09/02/2022 -> Passage du code en C++
//                        14/02/2022 -> Suite du passage en C++
/*************************************************/
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#include "../include/JeuNombreAdeviner.h"



// Nom :tirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre nbMin et nbMAx
// Paramètres d'entrée: nbMin, nbMAx : limites du nombre à deviner
// Valeur de retour : nombre à deviner

int tirerNombreMystere(const int nbMin, const int nbMax)
{
    int nb = 0; // Nombre aleatoire

    // Initialisation du générateur aléatoire avec l'heure
    // pour obtenir une série de nombres differents à chaque execution
    srand((int)time(NULL));

    nb = rand()%(nbMax - nbMin+1) + nbMin; // compris entre nbMin et nbMax inclus

    return nb;
}


// Nom :jouerPartie
// Rôle : Fait jouer une partie à un joueur
// Paramètres d'entrée: le nombre à deviner, les limites min et max du nombre à deviner, le nombre maximal d'essais possibles
// Paramètres de sortie: nombre d'essais utilisés par le joueur
// Paramètre d'entrée/sortie: Le joueur
// Valeur de retour: 0 si la partie est perdue, 1 sinon

int jouerPartie(TPlayer & p, int & nbTry, const int nb, const int nbMin, const int nbMax, const int nbTryMax)
{
    int endGame=0;
    int guess=0;
    int i=1;

    while(guess!=nb && i<=nbTryMax)
    {
        cout << "\nEssai numero " << i << " :\n";
        cin >> guess;
        nbTry = i;
        if(guess<nb)
        {
            cout << "Plus grand\n";
        }
        else if(guess>nb)
        {
            cout << "Plus bas\n";
        }
        else if(guess==nb)
        {
            endGame=1;
            (p).nbWin=(p).nbWin+1;
        }
        i=i+1;
    }

    (p).nbGame=(p).nbGame+1;

    return endGame;
}
