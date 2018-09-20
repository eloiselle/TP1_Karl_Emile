/*
Nom:		Karl Boutin
Programme:	puzzle.h
Date:		2018-09-15
But:		Classe permetant de jouer une partie du jeu camouflage.
			Elle initialise le jeu pour ensuite trouver une solution
			à la carte choisie.
*/

#pragma once
#include"casePiece.h"
#include"map.h"

class puzzle
{
private:
	map			_carte;				//La carte du jeu
	string		_solution[4][4];	//La solution de la carte
	piece		*_pieces[6];		//Contient les pièces du jeu
	bool		_succes;			//Détermine si une solution a été trouvé

public:
	//Initialiser le jeu
	void	init(ifstream &entree, string nomNoMap);

	void	play();					//Joue une partie de "Camouflage"
	bool	solve(int);				//Résoud une carte de "Camouflage"
	bool	match(int, int, int);	//Compare une pièce à une case

	//Place ou enlève une pièce dans la solution
	void	placePiece(int, int, int);
	void	retirerPiece(int, int, int);

	//Affiche les messages du jeu
	void	print(ostream &os)const;
};
ostream &operator<<(ostream &os, const puzzle &game);