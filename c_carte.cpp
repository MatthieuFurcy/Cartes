#include "c_carte.h"
#include <string>

using namespace std;

// -----------------------------
// Constructeurs
// -----------------------------

// Constructeur par défaut : initialise une carte neutre (0 de carreau)
c_carte::c_carte() : m_valeur(0), m_couleur(CARREAU) {}

// Constructeur avec paramètres : initialise la carte avec une valeur et une couleur
c_carte::c_carte(short valeur, c_carte::e_couleur couleur) {
    setCarte(valeur, couleur); // utilise le setter combiné
}

// Constructeur par copie : copie les valeurs d'une autre carte
c_carte::c_carte(const c_carte& other)
: m_valeur(other.m_valeur), m_couleur(other.m_couleur) {}

// -----------------------------
// Setters (mutateurs)
// -----------------------------

// Définit la carte complète : valeur + couleur
bool c_carte::setCarte(short valeur, c_carte::e_couleur couleur) {
    return setValeur(valeur) && setCouleur(couleur);
}

// Définit uniquement la valeur de la carte (2 à 14)
bool c_carte::setValeur(short valeur) {
    if (valeur < 2 || valeur > 14) {
        return false; // valeur invalide
    }
    m_valeur = valeur;
    return true;
}

// Définit uniquement la couleur de la carte
bool c_carte::setCouleur(c_carte::e_couleur couleur) {
    // Vérifie que la couleur est valide (entre CARREAU et PIQUE)
    if (static_cast<int>(couleur) < static_cast<int>(CARREAU) ||
    static_cast<int>(couleur) > static_cast<int>(PIQUE)) {
        return false; // couleur invalide
    }

    m_couleur = couleur;
    return true;
}


// -----------------------------
// Getters (accès aux valeurs)
// -----------------------------

// Retourne la valeur numérique de la carte (2 à 14)
short c_carte::getValeur() const {
    return m_valeur;
}

// Retourne la couleur de la carte (CARREAU, COEUR, TREFLE, PIQUE)
c_carte::e_couleur c_carte::getCouleur() const {
    return m_couleur;
}

// -----------------------------
// Opérateur d'affectation
// -----------------------------

// Copie les valeurs d'une autre carte
c_carte& c_carte::operator=(const c_carte& other) {
    if (this != &other) { // éviter l'auto-affectation
        m_valeur = other.m_valeur;
        m_couleur = other.m_couleur;
    }
    return *this;
}

// -----------------------------
// Surcharge de l'opérateur <<
// -----------------------------

// Permet d'afficher une carte directement avec cout << carte;
ostream& operator<<(ostream& os, const c_carte& carte) {
    string valeur_str;

    // Convertit la valeur en texte si c'est une figure ou l'As
    switch (carte.m_valeur) {
    case 11: valeur_str = "Valet"; break;
    case 12: valeur_str = "Dame"; break;
    case 13: valeur_str = "Roi"; break;
    case 14: valeur_str = "As"; break;
    default: valeur_str = to_string(carte.m_valeur); break;
    }

    string couleur_str;

    // Convertit la couleur en texte
    switch (carte.m_couleur) {
    case c_carte::CARREAU: couleur_str = "carreau"; break;
    case c_carte::COEUR:   couleur_str = "coeur";   break;
    case c_carte::TREFLE:  couleur_str = "trefle";  break;
    case c_carte::PIQUE:   couleur_str = "pique";   break;
    default: couleur_str = "inconnue"; break;
    }

    os << valeur_str << " de " << couleur_str;
    return os;
}