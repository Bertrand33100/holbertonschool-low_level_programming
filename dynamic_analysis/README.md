# Dynamic Analysis

## Objectif

Ce chapitre m'a permis d'apprendre à analyser un programme C **pendant son exécution** sans modifier son code source. L'objectif est de comprendre le comportement réel du programme en mémoire, d'observer les variables à différents moments de l'exécution et de retrouver des valeurs internes à l'aide d'un débogueur.

---

# Compétences acquises

À la fin de ce chapitre, je suis capable de :

- Utiliser **GDB (GNU Debugger)** depuis le terminal.
- Déboguer un programme C sans ajouter de `printf`.
- Exécuter un programme pas à pas.
- Poser des points d'arrêt (breakpoints).
- Observer les variables locales, globales et les arguments de fonctions.
- Comprendre la pile d'appels (Call Stack).
- Contrôler l'exécution d'un programme.
- Extraire des valeurs uniquement grâce à l'analyse dynamique.
- Utiliser le débogueur intégré de **Visual Studio Code**.

---

# Concepts étudiés

## Analyse statique

L'analyse statique consiste à lire et comprendre le code **sans exécuter le programme**.

Exemples :

- lecture du code source ;
- compréhension des fonctions ;
- recherche d'erreurs logiques.

---

## Analyse dynamique

L'analyse dynamique consiste à **observer le programme pendant son exécution**.

Elle permet de voir :

- les valeurs des variables ;
- les appels de fonctions ;
- l'évolution de la mémoire ;
- le chemin réellement emprunté par le programme.

---

# GDB

GDB est le débogueur standard des programmes C sous Linux.

Il permet notamment de :

- lancer un programme ;
- arrêter l'exécution à un endroit précis ;
- avancer ligne par ligne ;
- entrer dans une fonction ;
- sortir d'une fonction ;
- afficher les variables ;
- afficher les registres ;
- examiner la mémoire.

---

# Commandes GDB importantes

| Commande           | Description                                              |
| ------------------ | -------------------------------------------------------- |
| `run`              | Lance le programme                                       |
| `break`            | Place un point d'arrêt                                   |
| `continue`         | Reprend l'exécution                                      |
| `next`             | Exécute la ligne suivante sans entrer dans les fonctions |
| `step`             | Entre dans la fonction appelée                           |
| `finish`           | Termine la fonction courante                             |
| `print`            | Affiche une variable                                     |
| `print/x`          | Affiche une variable en hexadécimal                      |
| `list`             | Affiche le code source                                   |
| `info breakpoints` | Liste les points d'arrêt                                 |
| `delete`           | Supprime un ou plusieurs points d'arrêt                  |
| `quit`             | Quitte GDB                                               |

---

# Visual Studio Code

Le débogueur de VS Code repose sur GDB mais fournit une interface graphique plus simple.

Fonctionnalités utilisées :

- Breakpoints
- Variables
- Watch
- Call Stack
- Step Over
- Step Into
- Step Out
- Continue

---

# Ce que j'ai appris

Au cours de ce chapitre, j'ai appris à :

- suivre le déroulement d'un programme C ;
- identifier le moment exact où une variable change de valeur ;
- récupérer des valeurs internes sans modifier le code ;
- comprendre l'impact des structures de contrôle (`if`, `for`, `while`) sur l'exécution ;
- observer les paramètres transmis entre les fonctions ;
- vérifier les valeurs retournées par une fonction ;
- utiliser les représentations hexadécimales lors du débogage.

---

# Difficultés rencontrées

- Comprendre le fonctionnement des breakpoints dans une boucle.
- Savoir quand utiliser `next` ou `continue`.
- Reprendre un programme déjà lancé avec `run`.
- Comprendre pourquoi certaines variables ne sont visibles que dans leur portée (scope).
- Éviter de rester bloqué sur un breakpoint situé dans une boucle.

---

# Bonnes pratiques

- Ne jamais modifier le programme uniquement pour afficher des variables.
- Utiliser les breakpoints pour arrêter l'exécution au bon moment.
- Vérifier que l'on se trouve dans la bonne fonction avant d'afficher une variable.
- Supprimer les breakpoints inutiles pour simplifier le débogage.
- Utiliser `print/x` pour afficher les valeurs en hexadécimal lorsque nécessaire.

---

# Ce que je retiens

L'analyse dynamique est un outil essentiel pour comprendre le comportement réel d'un programme. Contrairement à la simple lecture du code, elle permet de suivre l'exécution étape par étape, de vérifier les valeurs calculées et de localiser précisément les erreurs ou les comportements inattendus. La maîtrise de GDB et du débogueur de Visual Studio Code constitue une compétence indispensable pour développer, tester et maintenir des programmes en langage C.

---

# Outils utilisés

- Ubuntu / WSL
- GCC
- GDB
- Visual Studio Code
- Terminal Linux

---

# Ressources

- Documentation officielle de GDB
- Manuel GNU Debugger
- Documentation Visual Studio Code – C/C++ Debugging
- Documentation GCC
