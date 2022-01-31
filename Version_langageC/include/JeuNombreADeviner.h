/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.h
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 21/01/2022
// Rôle du fichier: Contient la déclaration des fonctions concernant le jeu
// Nom des composants utilises:
// Historique du fichier: 24/01/2022 -> Creation du projet sur CodeBlocks, déclaration de jouerPartie
//                        27/01/2022 -> Declaration de la structure TJoueur
/*************************************************/

// Nom : TJoueur
// Type : Structure
// Rôle : enregistrer le score du joueur
// Paramètres : Le nom du joueur, le nombre de parties qu'il a joué, le nombre de parties qu'il a gagné et le nombre total de tentatives.

typedef struct
{

    char nom[20];
    int nbGame;
    int nbWin;
    int sumTry;

} TPlayer;

// Nom :tirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre nbMin et nbMAx
// Paramètres d'entrée: nbMin, nbMAx : limites du nombre à deviner
// Valeur de retour : nombre à deviner

int tirerNombreMystere(int nbMin, int nbMax);

// Nom : jouerPartie
// Rôle : Fait jouer une partie à un joueur
// Paramètres d'entrée: le nombre à deviner, les limites min et max du nombre à deviner, le nombre maximal d'essais possibles
// Paramètres de sortie: nombre d'essais utilisés par le joueur
// Valeur de retour : 0 si la partie est perdue, 1 sinon

int jouerPartie(TPlayer *p, int nb, int nbMin, int nbMax, int nbTryMax, int* nbTry);
