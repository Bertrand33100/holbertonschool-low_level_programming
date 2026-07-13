# README — Function Pointers (Pointeurs de fonctions)

## Description

Ce projet a pour objectif de découvrir les **pointeurs de fonctions** en langage C.

Un pointeur de fonction est une variable qui contient **l'adresse d'une fonction**. Il permet d'appeler une fonction de manière indirecte et de choisir dynamiquement quelle fonction exécuter pendant l'exécution du programme.

Les pointeurs de fonctions sont notamment utilisés pour créer des **callbacks**, des **menus**, des **tables de dispatch** et pour rendre le code plus modulaire et réutilisable.

---

# Objectifs d'apprentissage

À la fin de ce projet, je dois être capable de :

- Comprendre ce qu'est un pointeur de fonction.
- Déclarer un pointeur de fonction.
- Initialiser un pointeur de fonction avec l'adresse d'une fonction.
- Appeler une fonction à travers un pointeur.
- Expliquer ce que contient un pointeur de fonction.
- Expliquer où pointe un pointeur de fonction dans la mémoire.
- Comprendre les avantages des pointeurs de fonctions.

---

# Syntaxe

## Déclaration d'une fonction

```c
int add(int a, int b);
```

## Déclaration d'un pointeur vers cette fonction

```c
int (*ptr)(int, int);
```

## Affectation

```c
ptr = add;
```

ou

```c
ptr = &add;
```

## Appel de la fonction

```c
ptr(2, 3);
```

ou

```c
(*ptr)(2, 3);
```

Les deux écritures sont équivalentes.

---

# Fonctionnement

Une fonction possède une adresse en mémoire.

Le pointeur de fonction stocke uniquement cette adresse.

Lorsque le programme exécute :

```c
ptr(2, 3);
```

il se rend à l'adresse contenue dans `ptr` et exécute la fonction correspondante.

---

# Organisation de la mémoire

Les fonctions sont stockées dans la partie **Text (Code)** de la mémoire du programme.

```
+---------------------------+
| Text (Code)               |
| main()                    |
| add()                     |
| sub()                     |
+---------------------------+

+---------------------------+
| Data                      |
+---------------------------+

+---------------------------+
| Heap                      |
+---------------------------+

+---------------------------+
| Stack                     |
+---------------------------+
```

Le pointeur de fonction pointe donc vers le début du code exécutable d'une fonction.

---

# Pourquoi utiliser un pointeur de fonction ?

Les pointeurs de fonctions permettent de :

- choisir une fonction pendant l'exécution ;
- éviter la duplication de code ;
- écrire des fonctions génériques ;
- implémenter des callbacks ;
- créer des menus interactifs ;
- construire des tableaux de fonctions.

---

# Exercices du projet

## 0. What's my name

Afficher un nom en utilisant une fonction passée en paramètre.

Concept étudié :

- passer une fonction en argument ;
- appeler une fonction grâce à un pointeur.

---

## 1. If you spend too much time thinking about a thing...

Appliquer une fonction à chaque élément d'un tableau.

Concept étudié :

- parcourir un tableau ;
- utiliser un callback.

---

## 2. To hell with circumstances...

Rechercher un élément dans un tableau grâce à une fonction de comparaison.

Concept étudié :

- fonction de comparaison ;
- retour d'indice ;
- utilisation de pointeurs de fonctions.

---

## 3. A goal is not always meant to be reached...

Créer une calculatrice utilisant des pointeurs de fonctions pour sélectionner l'opération demandée.

Concept étudié :

- tableau de structures ;
- pointeurs de fonctions ;
- sélection dynamique d'une fonction.

---

# Compilation

Les programmes doivent être compilés avec :

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89
```

---

# Contraintes du projet

- Ubuntu 20.04 LTS
- Style Betty obligatoire
- Pas de variables globales
- Maximum 5 fonctions par fichier
- Fonctions autorisées :
  - `malloc`
  - `free`
  - `exit`
  - `_putchar`

---

# Fichiers du projet

| Fichier               | Description                                             |
| --------------------- | ------------------------------------------------------- |
| `function_pointers.h` | Prototypes des fonctions                                |
| `0-print_name.c`      | Affiche un nom avec un pointeur de fonction             |
| `1-array_iterator.c`  | Applique une fonction à chaque élément d'un tableau     |
| `2-int_index.c`       | Recherche un entier grâce à une fonction de comparaison |
| `3-main.c`            | Programme principal de la calculatrice                  |
| `3-op_functions.c`    | Fonctions de calcul                                     |
| `3-get_op_func.c`     | Sélection de l'opération à effectuer                    |
| `3-calc.h`            | Header de la calculatrice                               |

---

# À retenir

- Une fonction possède une adresse en mémoire.
- Un pointeur de fonction stocke cette adresse.
- Le nom d'une fonction représente déjà son adresse (`add == &add`).
- Un pointeur de fonction permet d'appeler différentes fonctions avec le même code.
- Avant d'utiliser un pointeur de fonction, il faut toujours vérifier qu'il n'est pas `NULL`.

Les pointeurs de fonctions constituent un outil essentiel du langage C pour écrire des programmes plus flexibles, plus modulaires et plus réutilisables.
