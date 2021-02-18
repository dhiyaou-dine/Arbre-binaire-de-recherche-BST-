#pragma once
#ifndef DEF_BSearch
#define DEF_BSearch
	/////////////////////////////////////////////////////////////////////////
	// --------------------METHODES RELATIVES A BST--------------------------
	/////////////////////////////////////////////////////////////////////////
	// Ici nous etudions des methodes sur des arbres binaire de recherche
class BSearch
{
public:
	//constructeur par defaut
	BSearch();
	//surcharge constructeur
	BSearch(int);
	//constructeur par copie
	BSearch(BSearch const& node);
	//destructeur
	~BSearch();
	//ajout d'un element
	BSearch* insert(BSearch* root, int data);
	//parcourt de l'arbre
	void parcourt(BSearch* root) const;
	//recherche dans l'arbre
	BSearch* cherche(BSearch* root, int data);
	//fonction retournant la valeur minimale dans l'arbre
	//dans le cas d'un arbre binaire de recherche, on va toujours à gauche
	BSearch* valeureMin(BSearch* noeud);
	//suppression de valeur
	BSearch* suppressionValeur(BSearch* root, BSearch* direction);
	//suppression de noeud
	BSearch* suppressionNoeud(BSearch* root, int key);

private:
	int m_data;//donnée sur le noeud
	BSearch* left;// enfant gauche
	BSearch* right;//enfant droit
};

#endif // !BSearch



