/*
Nom:		Karl Boutin et Émile Loiselle
Programme:	main.cpp
Date:		2018-09-09
But:		Le jeu camouflage dans lequel on manipule une map
			et des pièces afin de trouver la solution du casse-tête
			à l'aide d'un algorithme.
*/

#include"puzzle.h"

using namespace std;

//Méthodes
string ouvrirFichiers(ifstream &entree, ofstream &sortie);

int main()
{
	setlocale(LC_CTYPE, "fra");

	puzzle		game;		//Une partie du jeu camouflage

	ifstream	entree;		//Fichier dans lequel on lit la map
	ofstream	sortie;		//Fichier dans lequel on ecrie la solution
	string		nomNoMap;	//Nom fichier de la carte

	//Ouvrir le fichier s'il existe
	nomNoMap = ouvrirFichiers(entree, sortie);

	//Initialiser le jeu
	game.init(entree, nomNoMap);

	//Résoudre la solution
	game.play();

	//Afficher le résultat du jeu
	cout << game;
	sortie << game;

	//Fermer les fichiers
	entree.close();
	sortie.close();

	system("pause");

	return 0;
}

//Ouvrir les fichiers et vérifier si le fichier de lecture existe
string ouvrirFichiers(ifstream &entree, ofstream &sortie)
{
	string fichierEntree;

	//Boucle tant que le fichier n'est pas bon
	while (true)
	{
		cout << "Entrer la map a solutionner <Ex : Expert27> : ";
		getline(cin, fichierEntree);

		entree.open("map" + fichierEntree + ".txt");

		//Si le fichier s'est ouvert, on sort de la boucle
		if (entree.good())
			break;

		cout << endl << "Le fichier map" << fichierEntree;
		cout << ".txt n'existe pas!" << endl << endl;
	}

	//Ouvrir fichier sortie
	sortie.open("solution" + fichierEntree + ".txt");

	return fichierEntree;
}