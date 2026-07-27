# C - Hash Tables

## 📚 Description

Ce projet a pour objectif de comprendre le fonctionnement des **tables de hachage (Hash Tables)** en langage C.

Les tables de hachage sont des structures de données extrêmement rapides permettant de retrouver une information à partir d'une clé.

Elles sont utilisées dans de nombreux logiciels, systèmes d'exploitation, bases de données et langages de programmation.

À la fin de ce projet, vous serez capable de créer votre propre table de hachage et de comprendre le fonctionnement des dictionnaires Python.

---

# 📖 Learning Objectives

À la fin de ce projet, je dois être capable d'expliquer :

- Ce qu'est une fonction de hachage (Hash Function)
- Les caractéristiques d'une bonne fonction de hachage
- Ce qu'est une table de hachage
- Comment fonctionne une table de hachage
- Comment stocker et retrouver des données
- Ce qu'est une collision
- Les différentes méthodes pour gérer les collisions
- Les avantages des Hash Tables
- Les inconvénients des Hash Tables
- Les cas d'utilisation les plus courants

---

# Qu'est-ce qu'une Hash Table ?

Une Hash Table est une structure de données qui permet de stocker des couples :

```
clé  -> valeur
```

Exemple :

```
"nom"      -> "Bertrand"
"ville"    -> "Bordeaux"
"âge"      -> "30"
```

Chaque clé est unique.

Lorsque l'on cherche une valeur, on ne parcourt pas toute la structure.

On calcule directement où elle doit être grâce à une fonction de hachage.

---

# Pourquoi utiliser une Hash Table ?

Sans Hash Table :

Pour retrouver une information dans une liste de 10 000 éléments, il faut parfois parcourir les 10 000 éléments.

Complexité :

```
O(n)
```

Avec une Hash Table :

On calcule directement l'emplacement.

Complexité moyenne :

```
O(1)
```

C'est quasiment instantané.

---

# Qu'est-ce qu'une Hash Function ?

Une Hash Function est une fonction qui transforme une clé en un indice.

Exemple :

```
clé :

"Bertrand"

↓

Hash Function

↓

523945

↓

523945 % taille_du_tableau

↓

217
```

La donnée sera rangée dans la case 217.

---

# Une bonne Hash Function doit :

- être rapide
- toujours produire le même résultat pour une même clé
- répartir les données uniformément
- éviter les collisions

Une mauvaise fonction de hachage concentre toutes les données au même endroit.

---

# Structure d'une Hash Table

Une Hash Table est composée :

```
Hash Table

+---------+
| size    |
| array * |
+---------+
```

Le tableau contient des pointeurs.

```
array

0 -> NULL

1 -> NULL

2 -> node

3 -> NULL

4 -> node

...
```

Chaque case peut pointer vers une liste chaînée.

---

# Les structures utilisées

## Hash Node

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;
```

Chaque nœud contient :

- une clé
- une valeur
- un pointeur vers le prochain nœud

---

## Hash Table

```c
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

Elle contient :

- la taille du tableau
- le tableau de pointeurs

---

# Visualisation

```
array

0
|
NULL

1
|
NULL

2
|
+---------+
| key=A   |
| value=1 |
| next ---+----+
+---------+    |
               |
         +---------+
         | key=K   |
         | value=8 |
         | next=NULL
         +---------+
```

Deux éléments sont dans la même case.

C'est une collision.

---

# Qu'est-ce qu'une Collision ?

Une collision se produit lorsque deux clés différentes donnent le même indice.

Exemple :

```
"chat"

↓

indice 5

----------------

"chien"

↓

indice 5
```

Impossible de mettre deux éléments dans la même case.

Il faut donc gérer cette collision.

---

# Gestion des collisions

Il existe plusieurs méthodes.

Les plus connues sont :

## 1. Chaining (utilisée dans ce projet)

Chaque case contient une liste chaînée.

```
Indice 3

↓

clé1

↓

clé2

↓

clé3

↓

NULL
```

C'est la méthode utilisée dans ce projet.

---

## 2. Open Addressing

Si la case est occupée, on cherche une autre case libre.

Par exemple :

```
Indice 5 occupé

↓

Indice 6

↓

Indice 7

↓

...
```

---

# Fonctionnement général

Insertion

```
clé

↓

Hash Function

↓

indice

↓

Insertion dans la liste chaînée
```

Recherche

```
clé

↓

Hash Function

↓

indice

↓

Parcours de la liste

↓

clé trouvée

↓

valeur
```

Suppression

Même principe.

---

# Complexité

Cas moyen

Insertion :

```
O(1)
```

Recherche :

```
O(1)
```

Suppression :

```
O(1)
```

Pire cas

Toutes les clés tombent dans la même case.

La table devient une liste chaînée.

Complexité :

```
O(n)
```

---

# Avantages

- Très rapide
- Recherche instantanée
- Insertion rapide
- Suppression rapide
- Très utilisée

---

# Inconvénients

- Consomme plus de mémoire
- Les collisions ralentissent les performances
- Une mauvaise Hash Function détruit les performances
- Taille parfois difficile à choisir

---

# Cas d'utilisation

Les Hash Tables sont utilisées partout :

- Dictionnaires Python
- unordered_map en C++
- HashMap en Java
- Cache mémoire
- DNS
- Tables de symboles des compilateurs
- Bases de données
- Gestion des utilisateurs
- Authentification
- Indexation

---

# Les fonctions du projet

## hash_table_create()

Crée une nouvelle Hash Table.

Étapes :

- allouer la Hash Table
- sauvegarder la taille
- allouer le tableau
- initialiser toutes les cases à NULL

Retour :

- pointeur sur la Hash Table
- NULL en cas d'erreur

---

Les prochains fichiers du projet permettront de :

- créer une fonction de hachage
- calculer un indice
- insérer une clé
- modifier une valeur
- rechercher une valeur
- afficher la table
- supprimer la table

---

# Gestion mémoire

Comme toute allocation dynamique :

```
malloc()

↓

utilisation

↓

free()
```

Aucune fuite mémoire ne doit subsister.

Toujours vérifier les erreurs de malloc().

---

# Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hash
```

---

# Vérification Betty

```bash
betty *.c
betty *.h
```

---

# Valgrind

```bash
valgrind --leak-check=full ./hash
```

Permet de détecter :

- Memory leaks
- Invalid read
- Invalid write
- Double free

---

# Ce qu'il faut retenir

✔ Une Hash Table stocke des couples clé/valeur.

✔ Une Hash Function transforme une clé en indice.

✔ Les données sont stockées dans un tableau.

✔ Deux clés peuvent produire le même indice : collision.

✔ Ce projet utilise le Chaining pour gérer les collisions.

✔ Les recherches sont en moyenne en O(1).

✔ Les Hash Tables sont parmi les structures les plus utilisées en informatique.

✔ Les dictionnaires Python sont basés sur le principe des Hash Tables (avec une implémentation plus avancée).
