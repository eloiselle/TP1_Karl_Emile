#include "puzzle.h"

//Initialiser le jeu
void puzzle::init(ifstream &entree, string nomNoMap)
{
	_pieces[0] = new piece3Case('U', ' ', 'P', 'O', '\0');	//instance de la pièce U
	_pieces[1] = new piece3Case('V', 'P', ' ', 'O', '\0');	//instance de la pièce V
	_pieces[2] = new piece3Case('W', ' ', 'O', 'P', '\0');	//instance de la pièce W
	_pieces[3] = new piece2Case('X', 'P', 'P');				//instance de la pièce X
	_pieces[4] = new piece2Case('Y', 'P', 'O');				//instance de la pièce Y
	_pieces[5] = new piece3Case('Z', ' ', '\0', 'O', ' ');	//instance de la pièce Z

	//Initialiser la carte
	_carte.init(entree, nomNoMap);

	_solution.setColonne(_carte.getColonne());
	_solution.setLigne(_carte.getLigne());
}

void puzzle::play()
{
	for (int i = 0; i < 6; i++)
	{
		_succes = solve(i);
	}
}

bool puzzle::solve(int noPiece)
{
	//Chaques lignes
	for (int ligne = 0; ligne < _carte.getLigne(); ligne++)
	{
		//Chaques colonnes
		for (int colonne = 0; colonne < _carte.getColonne(); colonne++)
		{
			//Chaques rotations
			for (int rotation = 0; rotation < 4; rotation++)
			{
				//Si toutes les pièces sont placés
				if (noPiece == 6)
					return true;
				//Si la pièce entre dans l'emplacement
				if (match(noPiece, colonne, ligne))
				{
					placePiece(noPiece, colonne, ligne);

					//On en place une autre
					if (!solve(noPiece + 1))
					{
						retirerPiece(noPiece, colonne, ligne);
					}
				}
				_pieces[noPiece]->rotate();
			}
		}
	}
	return false;
}

//Pour chaque case de la pièce, on la compare à la case de la carte
//pour savoir si elle convient
bool puzzle::match(int noPiece, int colonne, int ligne)
{
	int match = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//Si case valide
			if (_pieces[noPiece]->getValide(i, j))
			{
				//Si ours et banquise
				if (_pieces[noPiece]->getValeur(i, j) == 'O'
					&& _carte.getCase(ligne + i, colonne + j) == 'B')
				{
					match++;
				}

				//Si poisson et eau
				if (_pieces[noPiece]->getValeur(i, j) == 'P'
					&& _carte.getCase(ligne + i, colonne + j) == 'E')
				{
					match++;
				}

				//Si vide
				if (_pieces[noPiece]->getValeur(i, j) == ' ')
					match++;
			}
		}
	}

	//À refaire, trop spécifique
	if ((_pieces[noPiece]->getNom() == 'X' || _pieces[noPiece]->getNom() == 'Y')
		&& match == 2)
		return true;

	else if (match == 3)
		return true;

	return false;
}

void puzzle::placePiece(int noPiece, int colonne, int ligne)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (_pieces[noPiece]->getValide(i, j))

				_solution.setCase(colonne, ligne, _pieces[noPiece]->getValeur(i, j));
}

void puzzle::retirerPiece(int noPiece, int colonne, int ligne)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (_pieces[noPiece]->getValide(i, j))
			{
				_solution.setCase(colonne, ligne, ' ');
			}
}

//Affiche les messages du jeu
void puzzle::print(ostream &os)const
{
	//Affiche la map en console et dans un fichier
	os << endl << "Pour la map suivante : " << endl;
	os << _carte << endl;

	//Si solution trouvée
	if (_succes)
	{
		os << endl << "Voici la solution : " << endl;
		os << _solution << endl;
	}
	//Sinon
	else
		os << endl << "Aucune solution n'a été trouvé.";
}

ostream &operator<<(ostream &os, const puzzle &game)
{
	game.print(os);
	return os;
}