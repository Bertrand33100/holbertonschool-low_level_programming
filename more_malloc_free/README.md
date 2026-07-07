# C - More malloc, free

## Description

Ce projet fait partie du cursus **Holberton School**.

L'objectif est d'approfondir la gestion de la mémoire dynamique en C en apprenant à :

- allouer de la mémoire avec `malloc()`,
- libérer la mémoire avec `free()`,
- gérer les erreurs d'allocation,
- arrêter proprement un programme avec `exit()`,
- comprendre le fonctionnement de `calloc()` et `realloc()` (sans les utiliser dans ce projet).

---

# Objectifs d'apprentissage

À la fin de ce projet, je dois être capable de :

- Comprendre le rôle de `malloc()` et `free()`.
- Vérifier qu'une allocation mémoire a réussi.
- Utiliser `exit()` pour arrêter un programme en cas d'erreur.
- Expliquer la différence entre `malloc()` et `calloc()`.
- Comprendre l'utilité de `realloc()`.
- Savoir pourquoi il ne faut pas caster le retour de `malloc()` en C.
- Éviter les fuites de mémoire (_memory leaks_).

---

# Fonctions autorisées

- `malloc()`
- `free()`
- `exit()`
- `_putchar()`

---

# Fonctions interdites

- `printf()`
- `puts()`
- `calloc()`
- `realloc()`
- Toutes les autres fonctions de la bibliothèque standard.

---

# Notions importantes

## `malloc()`

`malloc()` permet de réserver de la mémoire sur le **tas (heap)**.

Exemple :

```c
ptr = malloc(taille);
```

Il faut toujours vérifier que `malloc()` ne retourne pas `NULL`.

---

## `free()`

`free()` permet de libérer une zone mémoire précédemment allouée avec `malloc()`.

```c
free(ptr);
```

Chaque appel à `malloc()` doit être accompagné d'un `free()` lorsque la mémoire n'est plus utilisée.

---

## `exit()`

`exit()` permet d'arrêter immédiatement l'exécution du programme.

Exemple :

```c
exit(EXIT_SUCCESS);
```

ou

```c
exit(EXIT_FAILURE);
```

Cette fonction est utilisée lorsqu'une erreur empêche le programme de continuer.

---

## `calloc()`

`calloc()` réserve de la mémoire **et initialise tous les octets à 0**.

Il est équivalent à :

- réserver de la mémoire,
- puis la mettre à zéro.

Dans ce projet, son utilisation est interdite, mais il est important de comprendre son fonctionnement.

---

## `realloc()`

`realloc()` permet de modifier la taille d'une zone mémoire déjà allouée.

Il peut :

- agrandir une allocation,
- réduire une allocation,
- conserver les données déjà présentes lorsque cela est possible.

Son utilisation est également interdite dans ce projet.

---

# Bonnes pratiques

- Toujours vérifier le retour de `malloc()`.
- Libérer toute mémoire allouée avec `free()`.
- Ne jamais utiliser un pointeur après un `free()`.
- Ne jamais appeler `free()` sur une chaîne littérale ou une variable non allouée avec `malloc()`.
- Ne pas caster le résultat de `malloc()` en langage C.

---

# Compétences acquises

À la fin de ce chapitre, je sais :

- gérer la mémoire dynamique ;
- utiliser correctement les pointeurs ;
- éviter les fuites mémoire ;
- gérer les erreurs d'allocation ;
- comprendre le fonctionnement de `calloc()` et `realloc()` ;
- écrire des programmes plus robustes.

---

# Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o programme
```

---

# Auteur

Bertrand Oeung
