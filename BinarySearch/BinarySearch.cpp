// BinarySearch.cpp  

#include <iostream>
using namespace std;
#include "BSearch.h"

// test suppression
int main()
{
    /* 
            50
        /     \
        30     70
        / \ / \
    20 40 60 80 */
    BSearch b, *root = NULL;
    root = b.insert(root, 50);
    root->insert(root, 30);
    root->insert(root, 20);
    root->insert(root, 40);
    root->insert(root, 70);
    root->insert(root, 60);
    root->insert(root, 80);

    cout << "traversé dans l'ordre"<<endl; 
    root->parcourt(root);

    cout << "suppression de 20"<<endl;
    root->suppressionNoeud(root, 20);
    cout << "traversé dans l'ordre de l'arbre modifié"<<endl;
    root->parcourt(root);
    //après la suppression de 30 il faut une gestion d'exception pour faire le parcourt
    //l'interuption est dû au destructeur utilisé avec l'utilisation de pointeur dans la class
    //avec le destructeur par defaut tout marche bien
    cout << "\nDelete 30\n";
    root->suppressionNoeud(root, 30);
    root->parcourt(root);

    return 0;
}

/*
// test inertion et parcourt
int main()
{
    BSearch b, * root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    b.parcourt(root);
    cout << "Je chercche une valeur: " << endl;
   // b.cherche(root,30);
    return 0;
}
*/