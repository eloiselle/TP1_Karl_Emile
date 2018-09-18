#include "puzzle.h"

//Initialiser le jeu
void Puzzle::init(ifstream &entree, string nomNoMap)
{
	_pieces[0] = new piece3Case('U', ' ', 'P', 'O', '\0');	//instance de la pièce U
	_pieces[1] = new piece3Case('V', 'P', ' ', 'O', '\0');	//instance de la pièce V
	_pieces[2] = new piece3Case('W', ' ', 'O', 'P', '\0');	//instance de la pièce W
	_pieces[3] = new piece2Case('X', 'P', 'P');				//instance de la pièce X
	_pieces[4] = new piece2Case('Y', 'P', 'O');				//instance de la pièce Y
	_pieces[5] = new piece3Case('Z', ' ', '\0', 'O', ' ');	//instance de la pièce Z

	//Initialiser la carte
	_carte.init(entree, nomNoMap);
}

//Affiche les messages du jeu
void Puzzle::print(ostream &os)const
{
	//Affiche la map en console et dans un fichier
	os << endl << "Pour la map suivante : " << endl;
	os << _carte << endl;

	os << endl << "Voici la solution : " << endl;
	os << _solution << endl;
}

ostream &operator<<(ostream &os, const Puzzle &game)
{
	game.print(os);
	return os;
}