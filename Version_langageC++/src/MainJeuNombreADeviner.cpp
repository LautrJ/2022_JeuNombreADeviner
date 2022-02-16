/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud, Jean Lautraite
// Date de cr�ation : 21/01/2022
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio.h
// Historique du fichier: 24/01/2022 -> Creation du projet sur CodeBlocks et modification du main pour le test
//                        26/01/2022 -> Ajout de code dans la fonction main (fin niveau 2)
//                        09/02/2022 -> Passage du code en C++
//                        14/02/2022 -> Suite du passage en C++
/*************************************************/

#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
#include "../include/JeuNombreADeviner.h"

int main()
{

    cout << "Vous allez jouer pour deviner un nombre secret";

    // Declaration des variables
    int nb; // Nombre a deviner
    int nbMin=0; // Minimum pour le nombre al�atoire
    int nbMax=10; // Maximum pour le nombre al�atoire
    int nbTryMax=4; // Nombre d'essais maximum
    int nbTry=0; // Nombre d'essais faits par le joueur
    int endGame=0; // Resultat de la partie
    char newGame='y'; // Si le joueur veut rejouer
    int nbGame=0; // Nombre de parties jou�es
    int nbWin=0; // Nombre de parties gagn�es
    int sumTry=0; // Somme du nombre d'essais � chaque partie
    float moyTry=0; // Moyenne du nombre d'essais

    TPlayer player1={"Jean",nbGame,nbWin,sumTry};

while(newGame=='y' || newGame=='Y')
{

    cout << "\nVeuillez saisir les limites pour la generation du nombre secret" << endl;
    cout << "Min: "; cin >> nbMin;
    cout << "Max: "; cin >> nbMax;

    cout << "Veuillez donner le nombre d'essais maximum pour deviner." << endl;
    cin >> nbTryMax;

// Tirer al�atoirement le nombre � deviner
    nb = tirerNombreMystere(nbMin, nbMax);


// Jouer une partie
    cout << endl << "La partie commence." << endl;

    cout << "Vous avez " << nbTryMax << " essais pour deviner le nombre secret compris entre " << nbMin << " et " << nbMax << "." << endl;

    endGame = jouerPartie(player1, nbTry, nb, nbMin, nbMax, nbTryMax);


// Affichage du r�sultat de la partie
    if (endGame==0)
    {
        cout << endl << "Sah t'es nul mon reuf" << endl;
        cout << "Meme avec " << nbTry << " essais tu perds." << endl;
        cout << "Le nombre secret etait : " << nb << endl << endl;
        sumTry=sumTry+nbTry;
    }
    else if(endGame==1)
    {
        cout << "\nBello bito." << endl;
        cout << "Tu as trouve le nombre secret en " << nbTry << " essais." << endl << endl;
        sumTry=sumTry+nbTry;
    }


// Plusieurs partie
    cout << "Voulez vous jouer une nouvelle partie ? y/Y n/N" << endl;
    cin >> newGame;
}

moyTry=(float)sumTry/player1.nbGame;

cout << "Vous avez joue un total de " << player1.nbGame << " parties et vous en avez gagne " << player1.nbWin << endl;
cout << "Nombre d'essais en moyenne par partie :";
cout << setprecision(2) << moyTry << endl;

return 0;
}
