/*
Nom:		Karl Boutin
Programme:	main.cpp
Date:		2018-09-09
But:		La map du jeu camouflage qu'on obtient à l'aide d'un fichier
			dans lequel on lit pour obtenir son nombre de ligne,
			son nombre de colonne et obtenir les valeurs de chaques
			cases de la map. La classe permet d'afficher
			la map, d'obtenir des valeurs pour la map ou d'envoyer ses valeurs.
*/

#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<assert.h>

using namespace std;

class Map
{
private:
	char	_nom[25];	//Nom de la carte
	char	_map[4][4];	//Le tableau de la carte
	int		_nbLigne;	//Nombre de ligne lu dans le fichier
	int		_nbColonne;	//Nombre de colonne lu dans le fichier

public:
	void	init(ifstream &in, string nomNoFichier);//Initialiser la map
	void	print(ostream &os)const;				//Afficher la map
	void	read(istream &entree);					//Lire une entree
	void	setNom(string nomNoFichier);			//Obtenir le nom de la map
	void	setCase(int i, int j, char lettreMapTemp);//Donner des valeurs aux cases
	char	getCase(int i, int j)const;				//Obtenir la valeur d'une case
	string	getNom()const;							//Obtenir le nom de la map
	int		getLigne()const;						//Obtenir le nb de ligne
	int		getColonne()const;						//Obtenir le nb de colonne
};
ostream &operator<<(ostream &os, const Map &map);
istream &operator >> (istream &entree, Map &map);