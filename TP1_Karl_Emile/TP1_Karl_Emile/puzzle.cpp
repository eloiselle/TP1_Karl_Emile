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

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_solution[i][j] = " ";
		}
	}
}

void puzzle::play()
{
	_succes = solve(0);
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
				if (match(noPiece, ligne, colonne))
				{
					placePiece(noPiece, ligne, colonne);

					//On en place une autre
					if (!solve(noPiece + 1))
					{
						retirerPiece(noPiece, ligne, colonne);
					}
					else
					{
						return true;
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
bool puzzle::match(int noPiece, int ligne, int colonne)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			//Si case valide
			if (_pieces[noPiece]->getValide(i, j))
			{
				//Si vide et
				if (colonne + j >= 4 && ligne + i >= 4)
					return false;

				//Si ours et banquise
				if (_pieces[noPiece]->getValeur(i, j) == 'O'
					&& _carte.getCase(ligne + i, colonne + j) != 'B')
					return false;

				//Si poisson et eau
				if (_pieces[noPiece]->getValeur(i, j) == 'P'
					&& _carte.getCase(ligne + i, colonne + j) != 'E')
					return false;

				//Si une piece est déjà dans l'emplacement
				if (_solution[ligne + i][colonne + j] != " ")
					return false;
			}
		}
	}
	return true;
}

void puzzle::placePiece(int noPiece, int ligne, int colonne)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (_pieces[noPiece]->getValide(i, j))
			{
				_solution[ligne + i][colonne + j].clear();
				_solution[ligne + i][colonne + j].push_back(_pieces[noPiece]->getNom());
				if (_pieces[noPiece]->getValeur(i, j) != ' ')
				{
					_solution[ligne + i][colonne + j].push_back(_pieces[noPiece]->getValeur(i, j));
				}
			}
}

void puzzle::retirerPiece(int noPiece, int ligne, int colonne)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (_pieces[noPiece]->getValide(i, j))
			{
				_solution[ligne + i][colonne + j] = " ";
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

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				os << _solution[i][j];
				if (j < 3)
				{
					os << ",";
				}
			}
			os << endl;
		}
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