#include<iostream>
using namespace std;
#include "BSearch.h"
//implémentation des methodes 

BSearch::BSearch(): m_data(0), left(NULL), right(NULL)
{
}

BSearch::BSearch(int data): m_data(data)
{
	left = right = NULL;
}
// Définition du constructeur par copie.
// la presence de pointeur dans nos attributs, exige une redefinition du constructeur par copie
BSearch::BSearch(BSearch const& node): m_data(node.m_data), left(0), right(0)
{
	left = new BSearch(*node.left);
	right = new BSearch(*node.right);
}
//definition de la desstructeur: existance de pointeur dans notre classe
BSearch::~BSearch()
{
	delete left;
	delete right;
}

BSearch* BSearch::insert(BSearch* root, int data)
{
	// si l'arbre est null
	if (!root)
	{
		return new BSearch(data);
	}
	// la racine est plus petit que la valeur
	if (root->m_data < data)
	{
		//on insert à droite de la racine
		root->right = insert(root->right,data);
	}
	//sinon on rajoute à droite
	else
	{
		root->left = insert(root->left, data);
	}
	return root;
}

void BSearch::parcourt(BSearch* root) const
{
	//si on a pas d'arbre
	if (!root)
		return;
	//sinon
	{
		parcourt(root->left);
		cout << root->m_data << endl;
		parcourt(root->right);
	}
	
}

BSearch* BSearch::cherche(BSearch* root, int data)
{
	//si l'arbre est vide ou a un seul noeud
	if (root == NULL || root->m_data == data)
		return root;
	//sinon
	if (root->m_data < data)
	{
		return cherche(root->right, data);
	}
	else
	{
		return cherche(root->left, data);
	}
}

BSearch* BSearch::valeureMin(BSearch* noeud)
{
	BSearch* courant = noeud;
	//tant que le noeud courant  existe et que sa feuille gauche n'est pas nul on va à gauche
	//car sur un BST la petite valeur est sur la partie gauche
	while (courant && courant->left != 0)
	{
		courant = courant->left;
	}
	return courant;
}

BSearch* BSearch::suppressionValeur(BSearch* root, BSearch* direction)
{
	BSearch* tmp = direction;
	delete(root);
	return tmp;
}

BSearch* BSearch::suppressionNoeud(BSearch* root, int key)
{
	// Cas où la valeur de la racine est nulle ou pas de racine
	if (root == NULL)
		return root;
	//valeur à supprimer inf à la racine
	if (key < root->m_data)
	{
		root->left = suppressionNoeud(root->left, key);
	}
	//valeur a supprimer supperieur à la racine
	else if (key > root->m_data)
	{
		root->right = suppressionNoeud(root->right, key);
	}
	else
	{
		// la racine possede une feuille
		if (root->left == NULL)
		{
			//suppressionValeur(root, root->right);
			BSearch* tmp = root->right;
			delete(root);
			return tmp;
		}
		else if (root->right == NULL)
		{
			//suppressionValeur(root, root->left);
			BSearch* tmp = root->left;
			delete(root);
			return tmp;
		}
		else
		{
			//la racine a deux feuille
			//on cherche le min et on le remplace sur le noeud precedant
			//puis on supprime la feuille
			BSearch* tmp = valeureMin(root->right);
			root->m_data = tmp->m_data;
			root->right = suppressionNoeud(root->right, tmp->m_data);
		}
	
	}
	return root;
}
