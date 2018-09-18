/*
=======================En-tête=================================
Auteur:		Émile Loiselle
Date:		12 septembre
Programme:	casePiece.h
But:		Permet de manipuler des pièces 3 cases et 2 cases avec des
			opérations de base, comme faire une rotation des pieces,
			afficher les pieces, modifier et obtenir les
			valeurs de différentes cases.
===============================================================
*/

#pragma once
#include <iostream>
#include <assert.h>
#include <iomanip>

using namespace std;

//Structure permettant de manipuler les pieces avec aise
struct casePiece
{
	char valeur;
	bool active;
};

//Objet piece parent
class piece
{
protected:

	char _nom;					//Nom de la pièce
	casePiece _cases[2][2];		//Stocke les informations sur les pièces

public:

	//Initialise avec des valeures spécifiés
	void init(char, char, char, char, char);

	//Setteurs
	void setNom(char nom);
	void setValeur(int, int, char);

	//Getteurs
	char getNom()const;
	char getValeur(int, int)const;
	bool getValide(int, int)const;

	//Rotation d'une piece, se réfère aux fonctions dans les enfants
	virtual void rotate() {};

	//Afficheur
	void print(ostream& os)const;
};
ostream& operator<<(ostream&, const piece&);

//Piecec a 2 cases
class piece2Case : public piece
{
public:
	piece2Case();
	piece2Case(char, char, char);
	~piece2Case();

	virtual void rotate();
};

//Piecec a 3 cases
class piece3Case : public piece
{
public:
	piece3Case();
	piece3Case(char, char, char, char, char);
	~piece3Case();

	virtual void rotate();
};