# Recursion

## 📖 Description

Ce projet a pour objectif de comprendre la récursion en langage C.

La récursion est une technique qui permet à une fonction de s'appeler elle-même afin de résoudre un problème en le divisant en problèmes plus petits. Chaque appel rapproche la fonction d'un cas d'arrêt (base case) qui met fin à la récursion.

Dans ce projet, toutes les fonctions doivent être écrites **sans utiliser de boucle (`for`, `while`, `do...while`)**. La récursion remplace donc les boucles pour parcourir une chaîne de caractères, effectuer des calculs ou explorer des structures de données.

---

# 🎯 Objectifs d'apprentissage

À la fin de ce projet, je suis capable de comprendre :

- Ce qu'est la récursion.
- Comment une fonction peut s'appeler elle-même.
- Le rôle du cas de base (base case).
- Le fonctionnement de la pile d'appels (Call Stack).
- Comment remplacer certaines boucles par la récursion.
- Les avantages et les limites de la récursion.
- Dans quels cas utiliser la récursion.
- Dans quels cas il vaut mieux éviter la récursion.

---

# 🧠 Qu'est-ce que la récursion ?

Une fonction récursive est une fonction qui s'appelle elle-même.

Elle est toujours composée de deux parties :

1. Un **cas d'arrêt (Base Case)** qui met fin aux appels récursifs.
2. Un **appel récursif** qui rapproche progressivement le problème du cas d'arrêt.

Exemple simple :

```c
void countdown(int n)
{
    if (n == 0)
        return;

    _putchar(n + '0');
    countdown(n - 1);
}
```

---

# ⚙️ Fonctionnement

Lorsqu'une fonction récursive s'appelle elle-même, chaque appel est placé dans la **pile d'appels (Call Stack)**.

Exemple :

```
countdown(3)
│
├── countdown(2)
│     │
│     ├── countdown(1)
│     │     │
│     │     └── countdown(0)
│     │            return
│     │
│     return
│
return
```

La fonction termine uniquement lorsque le cas de base est atteint.

---

# 📌 Cas de base

Le cas de base empêche la récursion de continuer indéfiniment.

Sans cas de base :

```
fonction()
└── fonction()
     └── fonction()
          └── fonction()
               ...
```

Le programme finit par provoquer un **Stack Overflow**.

---

# ✅ Quand utiliser la récursion ?

La récursion est particulièrement utile pour :

- parcourir une chaîne de caractères ;
- parcourir un arbre binaire ;
- parcourir un dossier ;
- calculer une factorielle ;
- calculer une puissance ;
- rechercher dans une structure récursive.

---

# ❌ Quand éviter la récursion ?

Il est préférable d'éviter la récursion lorsque :

- une simple boucle est plus lisible ;
- le nombre d'appels récursifs peut devenir très important ;
- les performances sont importantes ;
- la mémoire de la pile risque d'être dépassée.

---

# 📂 Contraintes du projet

- Ubuntu 20.04 LTS
- gcc
- Compilation :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

- Respect du style Betty
- Pas de variables globales
- Pas de variables statiques
- Maximum 5 fonctions par fichier
- Aucune boucle autorisée
- Aucune fonction de la bibliothèque standard (`printf`, `puts`, etc.)
- Seule la fonction `_putchar` est autorisée
- Tous les prototypes doivent être déclarés dans `main.h`

---

# 📚 Ce que j'ai appris

Au cours de ce projet, j'ai appris à :

- créer une fonction récursive ;
- identifier un cas de base ;
- suivre l'exécution d'une fonction récursive ;
- comprendre la pile d'appels (Call Stack) ;
- remplacer certaines boucles par la récursion ;
- résoudre des problèmes étape par étape grâce aux appels récursifs ;
- comprendre comment les appels s'empilent puis se dépilent.

---

# 🛠️ Commande de compilation

Exemple :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _putchar.c main.c fichier.c -o output
```

---

# 📖 Ressources

- Recursion, Introduction
- What on Earth is Recursion?
- C - Recursion
- C Programming Tutorial #85
- C Programming Tutorial #86
