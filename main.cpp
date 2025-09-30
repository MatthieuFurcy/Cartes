#include <iostream>
#include "c_carte.h"
#include "c_paquetdecartes.h"

using namespace std;

int main() {
    cout << "=== TEST DE LA CLASSE C_CARTE ===" << endl;

    // 1. Constructeur par défaut
    c_carte carte1;
    cout << "Carte1 (default) : " << carte1 << endl;

    // 2. Constructeur avec valeurs
    c_carte carte2(14, c_carte::PIQUE); // As de pique
    cout << "Carte2 : " << carte2 << endl;

    // 3. Copy constructor
    c_carte carte3(carte2);
    cout << "Carte3 (copie de carte2) : " << carte3 << endl;

    // 4. setValeur et setCouleur
    carte1.setValeur(12); // Dame
    carte1.setCouleur(c_carte::COEUR);
    cout << "Carte1 après setValeur/setCouleur : " << carte1 << endl;

    // 5. setCarte combiné
    carte3.setCarte(7, c_carte::CARREAU);
    cout << "Carte3 après setCarte : " << carte3 << endl;

    // 6. Opérateur d'affectation
    c_carte carte4;
    carte4 = carte1;
    cout << "Carte4 après affectation = carte1 : " << carte4 << endl;

    // 7. Getters
    cout << "Carte4 valeur = " << carte4.getValeur()
    << ", couleur = " << carte4.getCouleur() << endl;

    // 8. Test du paquet de cartes
    cout << "\n=== TEST DE LA CLASSE C_PAQUETDECARTES ===" << endl;
    c_paquetDeCartes paquet;
    cout << "5 cartes initiales du paquet :" << endl;
    c_carte temp;
    for (int i = 0; i < 5; ++i) {
        paquet.distribuer(temp);
        cout << temp << endl;
    }

    // Remet le paquet en ordre
    paquet.setTaillePaquet(32);

    // Mélange
    paquet.melangerPaquet();
    cout << "\n5 cartes après mélange :" << endl;
    for (int i = 0; i < 5; ++i) {
        paquet.distribuer(temp);
        cout << temp << endl;
    }

    return 0;
}
