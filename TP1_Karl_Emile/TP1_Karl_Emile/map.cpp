#include"map.h"

//Initialiser la map
void Map::init(ifstream &in, string nomNoFichier)
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
void Map::print(ostream &os)const
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
void Map::read(istream &entree)
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
void Map::setNom(string nomNoFichier)
{
	for (int i = 0; i < nomNoFichier.length(); i++)
	{
		_nom[i] = nomNoFichier[i];
	}
}

//Donner les valeurs aux cases de la map
void Map::setCase(int i, int j, char lettreMapTemp)
{
	assert(i >= 0 && j >= 0 && i < _nbLigne && j < _nbColonne);

	_map[i][j] = lettreMapTemp;
}

//Obtenir la valeur d'une case
char Map::getCase(int i, int j)const
{
	assert(i >= 0 && j >= 0 && i < _nbLigne && j < _nbColonne);

	return _map[i][j];
}

//Obtenir le nom de la map
string Map::getNom()const
{
	return _nom;
}

//Obtenir le nombre de ligne de la map
int Map::getLigne()const
{
	return _nbLigne;
}

//Obtenir le nombre de colonne de la map
int Map::getColonne()const
{
	return _nbColonne;
}

ostream &operator<<(ostream &os, const Map &map)
{
	map.print(os);
	return os;
}

istream &operator >> (istream &entree, Map &map)
{
	map.read(entree);
	return entree;
}