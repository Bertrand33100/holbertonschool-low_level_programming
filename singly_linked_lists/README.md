# README – Les listes simplement chaînées (Singly Linked Lists)

## Objectif

Dans ce chapitre, j'ai découvert les **listes simplement chaînées** en langage C. Cette structure de données permet de stocker plusieurs éléments en mémoire sans qu'ils soient placés les uns à côté des autres, contrairement aux tableaux.

Chaque élément de la liste est appelé un **nœud** (_node_). Chaque nœud contient une valeur et un pointeur vers le nœud suivant.

---

# Structure d'un nœud

Une liste simplement chaînée est définie grâce à une structure.

```c
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
```

Chaque champ a un rôle précis :

- `str` : la chaîne de caractères stockée.
- `len` : la longueur de la chaîne.
- `next` : l'adresse du nœud suivant.

---

# Fonctionnement

Une liste est composée d'une suite de nœuds reliés entre eux grâce au pointeur `next`.

Exemple :

```
+-----------+      +-----------+      +-----------+
| "Hello"   | ---> | "World"   | ---> | NULL      |
+-----------+      +-----------+      +-----------+
```

Le dernier nœud pointe vers `NULL`, ce qui indique la fin de la liste.

---

# Parcourir une liste

Pour parcourir une liste, on utilise une boucle :

```c
while (h != NULL)
{
	/* traitement */
	h = h->next;
}
```

À chaque tour de boucle :

1. on traite le nœud courant ;
2. on passe au suivant grâce à `next`.

---

# Première fonction réalisée

## `print_list`

Prototype :

```c
size_t print_list(const list_t *h);
```

Cette fonction permet de :

- parcourir toute la liste ;
- afficher chaque élément ;
- afficher `(nil)` si la chaîne vaut `NULL` ;
- compter le nombre de nœuds ;
- retourner ce nombre.

---

# Notions importantes

J'ai appris :

- ce qu'est une liste simplement chaînée ;
- la différence entre un tableau et une liste ;
- comment créer une structure (`struct`) ;
- comment utiliser un pointeur vers une structure ;
- comment parcourir une liste avec une boucle `while` ;
- comment accéder aux membres d'une structure avec `->` ;
- comment détecter la fin d'une liste avec `NULL` ;
- comment compter les éléments d'une liste.

---

# Tableau vs Liste chaînée

| Tableau                 | Liste chaînée                        |
| ----------------------- | ------------------------------------ |
| Taille fixe             | Taille dynamique                     |
| Mémoire contiguë        | Mémoire non contiguë                 |
| Accès direct par indice | Parcours obligatoire depuis le début |
| Insertion coûteuse      | Insertion plus simple                |
| Suppression coûteuse    | Suppression plus simple              |

---

# Avantages des listes chaînées

- Taille dynamique.
- Insertion rapide.
- Suppression rapide.
- Pas besoin de connaître la taille à l'avance.

---

# Inconvénients

- Utilisent davantage de mémoire (à cause des pointeurs).
- Impossible d'accéder directement au 5ᵉ ou au 10ᵉ élément.
- Il faut parcourir la liste depuis le début.

---

# Ce que je dois retenir

- Une liste est composée de plusieurs nœuds.
- Chaque nœud possède un pointeur vers le suivant.
- `NULL` indique la fin de la liste.
- `->` permet d'accéder aux membres d'une structure pointée.
- Une boucle `while` est utilisée pour parcourir la liste.
- Une fonction peut retourner le nombre de nœuds parcourus.
- Les listes sont plus flexibles que les tableaux lorsque les données changent souvent.

---

# Conclusion

Ce chapitre m'a appris à manipuler une nouvelle structure de données essentielle en C : la liste simplement chaînée. J'ai compris comment créer un nœud, parcourir une liste, afficher son contenu et compter ses éléments. Ces notions constituent une base importante pour les prochains exercices, qui porteront sur l'ajout, la suppression et la gestion dynamique des nœuds avec l'allocation mémoire.
