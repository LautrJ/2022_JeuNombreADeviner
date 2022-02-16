/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.h
// Version : 1.0
// Nom du programmeur: MP Pinaud, Jean Lautraite
// Date de cr�ation : 21/01/2022
// R�le du fichier: Contient la d�claration des fonctions concernant le jeu
// Nom des composants utilises:
// Historique du fichier: 24/01/2022 -> Creation du projet sur CodeBlocks, d�claration de jouerPartie
//                        27/01/2022 -> Declaration de la structure TJoueur
//                        09/02/2022 -> Passage du code en C++
//                        14/02/2022 -> Suite du passage en C++
/*************************************************/

// Nom : TJoueur
// Type : Structure
// R�le : enregistrer le score du joueur
// Param�tres : Le nom du joueur, le nombre de parties qu'il a jou�, le nombre de parties qu'il a gagn� et le nombre total de tentatives.

typedef struct
{
    char nom[20];
    int nbGame;
    int nbWin;
    int sumTry;

} TPlayer;

// Nom : TGame
// Type : Structure
// R�le : enregistrer toutes les informations de chaque partie
// Param�tres : Le joueur, les limites du nombre a deviner, le nombre d'essais max, le nombre de tentatives utilis�es par le joueur, l'�tat de la partie

/* typedef struct
{
    struct TPlayer;
} */

// Nom :tirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre nbMin et nbMAx
// Param�tres d'entr�e: nbMin, nbMAx : limites du nombre � deviner
// Valeur de retour : nombre � deviner

int tirerNombreMystere(int const nbMin=1, int const nbMax=10);

// Nom : jouerPartie
// R�le : Fait jouer une partie � un joueur
// Param�tres d'entr�e: le nombre � deviner, les limites min et max du nombre � deviner, le nombre maximal d'essais possibles
// Param�tres de sortie: nombre d'essais utilis�s par le joueur
// Valeur de retour : 0 si la partie est perdue, 1 sinon

int jouerPartie(TPlayer & p, int &nbTry, const int nb, const int nbMin=1, const int nbMax=10, const int nbTryMax=4);
