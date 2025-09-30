#ifndef C_PAQUETDECARTES_H
#define C_PAQUETDECARTES_H

#include "c_carte.h"

// -----------------------------------------------------------------------------
// Classe représentant un paquet de cartes
// -----------------------------------------------------------------------------
class c_paquetDeCartes
{
public:
    // -------------------------------------------------------------------------
    // Constructeurs
    // -------------------------------------------------------------------------
    c_paquetDeCartes();          // Paquet par défaut de 32 cartes
    c_paquetDeCartes(short taille); // Paquet de 32 ou 52 cartes selon le paramètre

    // -------------------------------------------------------------------------
    // Méthodes principales
    // -------------------------------------------------------------------------
    bool setTaillePaquet(short t);    // Définit la taille du paquet et réinitialise l'ordre
    void rangerPaquet();              // Range le paquet en ordre croissant
    void melangerPaquet();            // Mélange le paquet aléatoirement
    void distribuer(c_carte& carte);  // Distribue une carte du paquet

    // -------------------------------------------------------------------------
    // Getters
    // -------------------------------------------------------------------------
    short getTaillePaquet() const;       // Retourne la taille actuelle du paquet
    short getCartesDistribuees() const;  // Retourne le nombre de cartes distribuées

private:
    c_carte m_paquetCartes[52];   // Tableau des cartes (maximum 52)
    short m_taillePaquet;         // Taille du paquet (32 ou 52)
    short m_cartesDistribuees;    // Compteur de cartes déjà distribuées
};

#endif // C_PAQUETDECARTES_H