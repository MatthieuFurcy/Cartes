#ifndef C_CARTE_H
#define C_CARTE_H

#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------
// Classe représentant une carte à jouer
// -----------------------------------------------------------------------------
class c_carte
{
public:

    // -------------------------------------------------------------------------
    // Enumération des couleurs possibles d'une carte
    // -------------------------------------------------------------------------
    enum e_couleur
    {
        CARREAU,  // ♦
        COEUR,    // ♥
        TREFLE,   // ♣
        PIQUE     // ♠
    };

    // -------------------------------------------------------------------------
    // Constructeurs
    // -------------------------------------------------------------------------
    c_carte();                              // Constructeur par défaut (0 de carreau)
    c_carte(short valeur, e_couleur couleur); // Constructeur avec valeur et couleur
    c_carte(const c_carte& other);          // Constructeur par copie

    // -------------------------------------------------------------------------
    // Setters / Mutateurs
    // -------------------------------------------------------------------------
    bool setCarte(short valeur, e_couleur couleur); // Définit valeur et couleur
    bool setValeur(short valeur);                   // Définit uniquement la valeur
    bool setCouleur(e_couleur couleur);            // Définit uniquement la couleur

    // -------------------------------------------------------------------------
    // Getters / Accesseurs
    // -------------------------------------------------------------------------
    short getValeur() const;        // Retourne la valeur de la carte
    e_couleur getCouleur() const;   // Retourne la couleur de la carte

    // -------------------------------------------------------------------------
    // Opérateur d'affectation
    // -------------------------------------------------------------------------
    c_carte& operator=(const c_carte& other); // Copie les valeurs d'une autre carte

    // -------------------------------------------------------------------------
    // Surcharge de l'opérateur << pour l'affichage
    // -------------------------------------------------------------------------
    friend ostream& operator<<(ostream& os, const c_carte& carte);

private:
    short m_valeur;       // Valeur de la carte (2 à 14, 11=Valet, 12=Dame, 13=Roi, 14=As)
    e_couleur m_couleur;  // Couleur de la carte (CARREAU, COEUR, TREFLE, PIQUE)
};

#endif // C_CARTE_H