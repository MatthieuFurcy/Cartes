<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TP Cartes – Session 2026</title>
    <style>
        body { font-family: Arial, sans-serif; line-height: 1.6; margin: 20px; }
        h1, h2, h3 { color: #2c3e50; }
        code { background-color: #f4f4f4; padding: 2px 4px; border-radius: 4px; }
        pre { background-color: #f4f4f4; padding: 10px; border-radius: 4px; overflow-x: auto; }
        ul { margin-top: 0; }
    </style>
</head>
<body>

<h1>TP Cartes – Session 2026</h1>

<p>Ce projet est un <strong>TP de programmation orientée objet en C++</strong> qui implémente un jeu de cartes et un paquet de cartes. Il permet de manipuler des cartes individuellement ou en paquet, de les mélanger et de les distribuer.</p>

<h2>Fonctionnalités</h2>
<ul>
    <li>Création de cartes individuelles avec <strong>valeur</strong> (2–14) et <strong>couleur</strong> (Carreau, Coeur, Trèfle, Pique).</li>
    <li>Création de paquets de cartes (32 ou 52 cartes).</li>
    <li>Tri automatique du paquet en ordre croissant.</li>
    <li>Mélange aléatoire des cartes avec l’algorithme de <strong>Fisher-Yates</strong>.</li>
    <li>Distribution de cartes depuis le paquet.</li>
    <li>Surcharge de l’opérateur <code>&lt;&lt;</code> pour afficher facilement les cartes.</li>
    <li>Gestion des valeurs et couleurs invalides.</li>
</ul>

<h2>Structure du projet</h2>
<pre>
cartes/
│
├─ c_carte.h            # Déclaration de la classe c_carte
├─ c_carte.cpp          # Implémentation de la classe c_carte
├─ c_paquetdecartes.h   # Déclaration de la classe c_paquetDeCartes
├─ c_paquetdecartes.cpp # Implémentation de la classe c_paquetDeCartes
├─ main.cpp             # Programme de test des classes
└─ README.md            # Ce fichier
</pre>

<h2>Compilation et exécution</h2>
<p>Pour compiler le projet sur un système Windows ou Linux avec <code>g++</code> :</p>
<pre>
g++ cartes/c_carte.cpp cartes/c_paquetdecartes.cpp main.cpp -o programme.exe
</pre>
<p>Puis pour exécuter :</p>
<pre>
./programme.exe   # Linux/macOS
programme.exe     # Windows
</pre>

<h2>Exemples d'utilisation</h2>
<pre>
c_carte carte1(14, c_carte::PIQUE); // As de pique
c_paquetDeCartes paquet;             // Paquet de 32 cartes
paquet.melangerPaquet();             // Mélange du paquet

c_carte carteDistribuee;
paquet.distribuer(carteDistribuee);  // Distribution de la première carte
cout &lt;&lt; carteDistribuee &lt;&lt; endl;     // Affiche la carte
</pre>

<h2>Auteurs</h2>
<p><strong>Matthieu Furcy</strong> – TP Cartes – Session 2026</p>

</body>
</html>
