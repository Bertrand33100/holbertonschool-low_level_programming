# Doubly Linked Lists

## Objectif

Ce projet a pour objectif d'apprendre à manipuler les **listes doublement chaînées** en langage C.

À la fin de ce chapitre, je dois être capable de :

- Comprendre le fonctionnement d'une liste doublement chaînée.
- Créer des nœuds.
- Parcourir une liste dans les deux sens.
- Ajouter des nœuds à différents endroits.
- Supprimer des nœuds.
- Libérer la mémoire correctement.
- Éviter les fuites mémoire (memory leaks).

---

# Qu'est-ce qu'une liste doublement chaînée ?

Une liste doublement chaînée est une structure de données composée de plusieurs nœuds reliés entre eux.

Chaque nœud contient :

- une valeur (`n`)
- un pointeur vers le nœud précédent (`prev`)
- un pointeur vers le nœud suivant (`next`)

Schéma :

```
NULL <- [10] <-> [20] <-> [30] -> NULL
```

Le premier nœud possède :

```
prev = NULL
```

Le dernier possède :

```
next = NULL
```

---

# Structure d'un nœud

```c
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

### Signification

| Élément | Rôle                      |
| ------- | ------------------------- |
| n       | valeur stockée            |
| prev    | adresse du nœud précédent |
| next    | adresse du nœud suivant   |

---

# Pourquoi utiliser une liste doublement chaînée ?

## Avantages

- insertion rapide
- suppression rapide
- parcours dans les deux directions
- taille dynamique
- pas besoin de déplacer les éléments

## Inconvénients

- consomme plus de mémoire
- plus complexe qu'une liste simplement chaînée
- deux pointeurs à maintenir

---

# Différence avec une liste simplement chaînée

Liste simple :

```
10 -> 20 -> 30 -> NULL
```

Liste double :

```
NULL <- 10 <-> 20 <-> 30 -> NULL
```

La différence principale :

Une liste double connaît son voisin de gauche et son voisin de droite.

---

# Le pointeur head

Le début de la liste est toujours représenté par :

```c
dlistint_t *head;
```

Exemple :

```
head
 |
 v
[5] <-> [8] <-> [12]
```

---

# Parcourir une liste

Le parcours consiste à visiter chaque nœud.

Principe :

```
head

↓

premier

↓

deuxième

↓

troisième

↓

NULL
```

À chaque étape :

- utiliser le nœud courant
- passer au suivant grâce à `next`

---

# Parcours inverse

Grâce au pointeur `prev`, il est également possible de revenir en arrière.

```
NULL <- 5 <-> 8 <-> 12

                    ^
                    |
                 dernier
```

Puis :

```
12

↓

8

↓

5
```

---

# Ajouter un nœud

On peut insérer un nœud :

- au début
- à la fin
- au milieu
- à une position donnée

Il faut toujours mettre à jour les pointeurs `prev` et `next`.

---

# Supprimer un nœud

Lors de la suppression :

1. reconnecter les voisins
2. appeler `free()`
3. éviter de perdre l'adresse du reste de la liste

---

# Allocation mémoire

Création d'un nœud :

```
malloc()
```

Libération :

```
free()
```

Toujours vérifier :

```
malloc() == NULL
```

---

# Les pointeurs

Une liste double repose entièrement sur les pointeurs.

Exemple :

```
+---------+
| n = 12  |
| prev ---+----> précédent
| next ---+----> suivant
+---------+
```

---

# Les fonctions du projet

## print_dlistint()

Affiche tous les éléments.

Retourne :

- le nombre de nœuds

---

## dlistint_len()

Compte le nombre de nœuds.

Ne fait aucun affichage.

---

## add_dnodeint()

Ajoute un nœud au début.

Le nouveau nœud devient le nouveau `head`.

---

## add_dnodeint_end()

Ajoute un nœud à la fin.

---

## free_dlistint()

Libère entièrement la mémoire de la liste.

---

## get_dnodeint_at_index()

Retourne le nœud situé à un indice donné.

---

## sum_dlistint()

Additionne toutes les valeurs de la liste.

---

## insert_dnodeint_at_index()

Insère un nœud à une position précise.

---

## delete_dnodeint_at_index()

Supprime le nœud situé à un indice précis.

---

# Les erreurs les plus fréquentes

- oublier de vérifier `malloc()`
- oublier de mettre `prev`
- oublier de mettre `next`
- perdre l'adresse du premier nœud
- oublier un `free()`
- déréférencer un pointeur `NULL`
- modifier un pointeur avant d'avoir sauvegardé le suivant

---

# Bonnes pratiques

- Initialiser les pointeurs à `NULL`.
- Vérifier les retours de `malloc()`.
- Toujours tester les cas particuliers :
  - liste vide ;
  - un seul élément ;
  - insertion au début ;
  - insertion à la fin ;
  - suppression du premier ;
  - suppression du dernier.

- Compiler avec :

```
gcc -Wall -Wextra -Werror -pedantic -std=gnu89
```

- Tester avec Valgrind pour détecter les fuites mémoire.

---

# Complexité

| Opération                         | Complexité |
| --------------------------------- | ---------- |
| Accès à un indice                 | O(n)       |
| Parcours                          | O(n)       |
| Ajout en tête                     | O(1)       |
| Ajout en fin (sans pointeur tail) | O(n)       |
| Suppression d'un nœud connu       | O(1)       |

---

# À retenir

- Une liste double possède deux pointeurs (`prev` et `next`).
- Le premier nœud a `prev = NULL`.
- Le dernier nœud a `next = NULL`.
- On peut parcourir la liste dans les deux sens.
- Toute allocation avec `malloc()` doit être libérée avec `free()`.
- Les mises à jour des pointeurs doivent être faites avec soin pour conserver l'intégrité de la liste.

---

# Ressources utiles

- Documentation C : https://en.cppreference.com/w/c
- Manuel Linux :
  - `man malloc`
  - `man free`

- Documentation GNU C Library : https://www.gnu.org/software/libc/manual/
