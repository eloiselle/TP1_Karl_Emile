/*
Nom:		Karl Boutin
Programme:	puzzle.h
Date:		2018-09-15
But:		Classe permetant de jouer une partie du jeu camouflage.
			Elle initialise le jeu pour ensuite trouver une solution
			a la carte choisie.
*/

#pragma once
#include"casePiece.h"
#include"map.h"

class puzzle
{
private:
	map			_carte;			//La carte du jeu
	string		_solution[4][4];		//La solution de la carte
	piece		*_pieces[6];	//Contient les pièces du jeu
	bool		_succes;		//Détermine si une solution a été trouvé

public:
	void	init(ifstream &entree, string nomNoMap);	//Initialiser le jeu
	void	play(ostream&);										//Joue une partie de camouflage
	bool	solve(int, ostream&);									//Résoud une carte de camouflage
	bool	match(int, int, int);						//Compare une pièce à une case
	void	placePiece(int, int, int);
	void	retirerPiece(int, int, int);
	void	print(ostream &os)const;					//Affiche les messages du jeu
};
ostream &operator<<(ostream &os, const puzzle &game);