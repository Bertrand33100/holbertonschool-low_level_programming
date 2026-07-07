# Structures et Typedef en C

## Description

Ce projet a pour objectif de découvrir les **structures (`struct`)** et le mot-clé **`typedef`** en langage C.

Les structures permettent de regrouper plusieurs variables de types différents dans une seule entité. Elles sont utilisées pour représenter des objets du monde réel comme une personne, un chien, une voiture, un étudiant ou encore un livre.

Le mot-clé `typedef` permet de créer un alias pour un type existant afin de rendre le code plus simple à lire et à écrire.

---

# Objectifs d'apprentissage

À la fin de ce projet, je suis capable de :

- Comprendre ce qu'est une structure (`struct`).
- Définir une structure.
- Déclarer des variables de type structure.
- Accéder et modifier les membres d'une structure.
- Comprendre dans quels cas utiliser une structure.
- Comprendre le rôle de `typedef`.
- Créer un alias avec `typedef`.
- Organiser les structures dans des fichiers d'en-tête (`.h`).
- Utiliser des _include guards_ pour éviter les inclusions multiples d'un même fichier.

---

# Notions importantes

## Structure (`struct`)

Une structure permet de regrouper plusieurs informations sous un même nom.

Exemple :

Un chien possède :

- un nom ;
- un âge ;
- un propriétaire.

Ces informations sont regroupées dans une seule structure.

---

## `typedef`

Le mot-clé `typedef` permet de créer un alias pour un type existant.

Par exemple, au lieu d'écrire :

```c
struct dog mon_chien;
```

on pourra écrire :

```c
dog_t mon_chien;
```

si un alias `dog_t` a été créé.

L'objectif est de rendre le code plus lisible.

---

# Compétences acquises

Au cours de ce projet, j'ai appris à :

- créer une structure ;
- utiliser une structure dans un programme ;
- manipuler les membres d'une structure ;
- comprendre la différence entre une structure et un pointeur vers une structure ;
- utiliser les opérateurs `.` et `->` ;
- créer un alias avec `typedef` ;
- protéger un fichier d'en-tête avec des _include guards_.

---

# Compilation

Compiler le projet avec :

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o programme
```

---

# Vérification du style Betty

Contrôler le style du code avec :

```bash
betty *.c *.h
```

---

# Contraintes du projet

- Ubuntu 20.04 LTS
- GCC
- Norme C89 (`-std=gnu89`)
- Pas de variables globales
- Maximum de 5 fonctions par fichier
- Fonctions autorisées :
  - `printf`
  - `malloc`
  - `free`
  - `exit`

---

# Ce qu'il faut retenir

- Une **structure** regroupe plusieurs variables liées entre elles.
- Les membres d'une structure peuvent être de types différents.
- Une structure représente une entité (personne, chien, voiture, étudiant, etc.).
- L'opérateur `.` permet d'accéder aux membres d'une structure.
- L'opérateur `->` permet d'accéder aux membres d'une structure via un pointeur.
- `typedef` permet de simplifier l'écriture des types.
- Les fichiers `.h` doivent être protégés avec des _include guards_.

---

# Auteur

**Bertrand Oeung**

Étudiant en développement logiciel à Holberton School.
