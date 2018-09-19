#include"map.h"

//Initialiser la map
void map::init(ifstream &in, string nomNoFichier)
{
	char	garbage;		//Variable temporaire pour stocker la virgule

	assert(in.is_open());

	setNom(nomNoFichier);

	in >> _nbLigne;		//Lire nb ligne et nb colonne dans le fichier
	in >> garbage;		//Pour lire la virgule dans le fichier
	in >> _nbColonne;

	read(in);			//Lire les valeurs de la map
}

//Afficher la map
void map::print(ostream &os)const
{
	int	j;//Colonne a ecrire

	for (int i = 0; i < _nbLigne; i++)
	{
		for (j = 0; j < _nbColonne; j++)
		{
			os << _map[i][j] << " ";
		}
		os << endl;
	}
}

//Lire une entree
void map::read(istream &entree)
{
	for (int i = 0; i < _nbLigne; i++)	//Lire la map dans le fichier
	{
		for (int j = 0; j < _nbColonne; j++)
		{
			entree >> _map[i][j];
		}
	}
}

//Attribuer un nom a la map
void map::setNom(string nomNoFichier)
{
	for (int i = 0; i < nomNoFichier.length(); i++)
	{
		_nom[i] = nomNoFichier[i];
	}
}

void map::setLigne(int ligne)
{
	_nbLigne = ligne;
}

void map::setColonne(int colonne)
{
	_nbColonne = colonne;
}

//Donner les valeurs aux cases de la map
void map::setCase(int i, int j, char lettreMapTemp)
{
	assert(i >= 0 && j >= 0 && i <= _nbLigne && j <= _nbColonne);

	_map[i][j] = lettreMapTemp;
}

//Obtenir la valeur d'une case
char map::getCase(int i, int j)const
{
	assert(i >= 0 && j >= 0 && i <= _nbLigne && j <= _nbColonne);

	return _map[i][j];
}

//Obtenir le nom de la map
string map::getNom()const
{
	return _nom;
}

//Obtenir le nombre de ligne de la map
int map::getLigne()const
{
	return _nbLigne;
}

//Obtenir le nombre de colonne de la map
int map::getColonne()const
{
	return _nbColonne;
}

ostream &operator<<(ostream &os, const map &map)
{
	map.print(os);
	return os;
}

istream &operator >> (istream &entree, map &map)
{
	map.read(entree);
	return entree;
}