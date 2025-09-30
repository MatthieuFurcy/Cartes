#include "c_paquetdecartes.h"
#include <cstdlib> // pour srand, rand
#include <ctime>   // pour time

using namespace std;

// -----------------------------------------------------------------------------
// Constructeurs
// -----------------------------------------------------------------------------

// Constructeur par défaut : crée un paquet de 32 cartes
c_paquetDeCartes::c_paquetDeCartes() : m_taillePaquet(32), m_cartesDistribuees(0)
{
    rangerPaquet(); // met le paquet en ordre
}

// Constructeur avec taille personnalisée (32 ou 52)
c_paquetDeCartes::c_paquetDeCartes(short taille) : m_taillePaquet(32), m_cartesDistribuees(0)
{
    rangerPaquet();
    if (taille == 52) {
        m_taillePaquet = 52;
        rangerPaquet(); // remet le paquet en ordre selon la nouvelle taille
    }
}

// -----------------------------------------------------------------------------
// Setters
// -----------------------------------------------------------------------------

// Définit la taille du paquet (32 ou 52) et réinitialise le paquet
bool c_paquetDeCartes::setTaillePaquet(short taille)
{
    if (taille != 32 && taille != 52) {
        return false; // taille invalide
    }
    m_taillePaquet = taille;
    rangerPaquet();
    return true;
}

// -----------------------------------------------------------------------------
// Méthodes principales
// -----------------------------------------------------------------------------

// Range le paquet en ordre croissant (valeurs et couleurs)
void c_paquetDeCartes::rangerPaquet()
{
    m_cartesDistribuees = 0; // réinitialise le compteur de cartes distribuées
    int index = 0;

    // Détermine la plage de valeurs selon la taille du paquet
    short debutValeur = (m_taillePaquet == 32) ? 7 : 2;
    short nbValeurs = (m_taillePaquet == 32) ? 8 : 13;

    // Boucle sur chaque couleur
    for (int couleur = 0; couleur < 4; ++couleur) {
        // Boucle sur chaque valeur pour cette couleur
        for (short valeur = debutValeur; valeur < debutValeur + nbValeurs; ++valeur) {
            m_paquetCartes[index].setCarte(valeur, static_cast<c_carte::e_couleur>(couleur));
            ++index;
        }
    }
}

// Mélange le paquet aléatoirement (Fisher-Yates)
void c_paquetDeCartes::melangerPaquet()
{
    srand(static_cast<unsigned>(time(nullptr))); // initialisation du générateur aléatoire

    // Parcourt le paquet depuis la fin pour mélanger
    for (int i = m_taillePaquet - 1; i > 0; --i) {
        int j = rand() % (i + 1); // indice aléatoire
        swap(m_paquetCartes[i], m_paquetCartes[j]); // échange des cartes
    }
}

// Distribue une carte du paquet
void c_paquetDeCartes::distribuer(c_carte& carte)
{
    if (m_cartesDistribuees < m_taillePaquet) {
        carte = m_paquetCartes[m_cartesDistribuees++]; // distribue et incrémente le compteur
    }
}

// -----------------------------------------------------------------------------
// Getters
// -----------------------------------------------------------------------------

// Retourne la taille actuelle du paquet
short c_paquetDeCartes::getTaillePaquet() const {
    return m_taillePaquet;
}

// Retourne combien de cartes ont été distribuées
short c_paquetDeCartes::getCartesDistribuees() const {
    return m_cartesDistribuees;
}
