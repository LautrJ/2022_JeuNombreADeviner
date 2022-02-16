/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 21/01/2022
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              stdio.h
// Historique du fichier: 24/01/2022 -> Creation du projet sur CodeBlocks et modification du main pour le test
//                        26/01/2022 -> Ajout de code dans la fonction main (fin niveau 2)
/*************************************************/

#include <stdio.h>
#include "../include/JeuNombreADeviner.h"

int main()
{

    printf ("%s\n", "Vous allez jouer pour deviner un nombre secret");

    // Declaration des variables
    int nb; // Nombre a deviner
    int nbMin=0; // Minimum pour le nombre aléatoire
    int nbMax=10; // Maximum pour le nombre aléatoire
    int nbTryMax=4; // Nombre d'essais maximum
    int nbTry=0; // Nombre d'essais faits par le joueur
    int endGame=0; // Resultat de la partie
    char newGame='y'; // Si le joueur veut rejouer
    int nbGame=0; // Nombre de parties jouées
    int nbWin=0; // Nombre de parties gagnées
    int sumTry=0; // Somme du nombre d'essais à chaque partie
    float moyTry=0; // Moyenne du nombre d'essais

    TPlayer player1={"Jean",nbGame,nbWin,sumTry};

while(newGame=='y' || newGame=='Y')
{

    printf("\nVeuillez saisir les limites pour la generation du nombre secret\n");
    scanf("%d%d", &nbMin, &nbMax);

    printf("Veuillez donner le nombre d'essais maximum pour deviner.\n");
    scanf("%d", &nbTryMax);

// Tirer aléatoirement le nombre à deviner
    nb = tirerNombreMystere(nbMin, nbMax);


// Jouer une partie
    printf("\nLa partie commence.\n");

    printf("Vous avez %d essais pour deviner le nombre secret compris entre %d et %d.\n", nbTryMax, nbMin, nbMax);

    endGame = jouerPartie(&player1, nb, nbMin, nbMax, nbTryMax, &nbTry);


// Affichage du résultat de la partie
    if (endGame==0)
    {
        printf("\nSah t'es nul mon reuf\n");
        printf("Meme avec %d essais tu perds.\n", nbTry);
        printf("Le nombre secret etait :%d\n\n",nb);
        sumTry=sumTry+nbTry;
    }
    else if(endGame==1)
    {
        printf("\nBello bito.\n");
        printf("Tu as trouve le nombre secret en %d essais.\n\n", nbTry);
        nbWin=nbWin+1;
        sumTry=sumTry+nbTry;
    }


// Plusieurs partie
    printf("Voulez vous jouer une nouvelle partie ? y/Y n/N\n");
    scanf("%c", &newGame);
    scanf("%c", &newGame);
}

moyTry=(float)sumTry/player1.nbGame;

printf("Vous avez joue un total de %d parties et vous en avez gagne %d\n",player1.nbGame, player1.nbWin);
printf("Nombre d'essais en moyenne par partie :%.2f", moyTry);

    return 0;
}
