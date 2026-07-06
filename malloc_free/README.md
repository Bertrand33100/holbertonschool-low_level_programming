# 0x0A - malloc, free

## Description

Ce projet introduit l'allocation dynamique de mémoire en langage C.

Jusqu'à présent, la mémoire utilisée par les variables était automatiquement gérée par le programme. Avec `malloc()`, il devient possible de réserver de la mémoire pendant l'exécution du programme, uniquement lorsque cela est nécessaire.

L'objectif est d'apprendre à utiliser correctement l'allocation dynamique, à libérer la mémoire avec `free()` et à éviter les fuites de mémoire (_memory leaks_).

---

# Objectifs d'apprentissage

À la fin de ce projet, vous serez capable de comprendre :

- La différence entre la mémoire automatique et la mémoire dynamique.
- Le fonctionnement de `malloc()`.
- Le rôle de `free()`.
- Quand utiliser l'allocation dynamique.
- Pourquoi il est important de libérer la mémoire.
- Comment détecter les fuites de mémoire avec **Valgrind**.

---

# Mémoire automatique vs mémoire dynamique

## Mémoire automatique (Stack)

La mémoire automatique est créée automatiquement lorsqu'une fonction est appelée.

Exemple :

```c
int number = 10;
char str[20];
```

Caractéristiques :

- allocation automatique
- libération automatique à la fin de la fonction
- rapide
- taille fixe

Schéma :

```
Fonction appelée

Stack
+------------+
| number     |
| str[20]    |
+------------+

Fin de la fonction

La mémoire disparaît automatiquement.
```

---

## Mémoire dynamique (Heap)

La mémoire dynamique est créée pendant l'exécution grâce à `malloc()`.

Exemple :

```c
char *buffer;

buffer = malloc(100);
```

Caractéristiques :

- créée seulement si nécessaire
- taille choisie pendant l'exécution
- reste en mémoire jusqu'à `free()`
- doit être libérée manuellement

Schéma :

```
Stack                     Heap

buffer -------------> [ mémoire réservée ]
```

---

# malloc()

Prototype :

```c
void *malloc(size_t size);
```

`malloc()` réserve un bloc de mémoire de la taille demandée.

Exemple :

```c
char *str;

str = malloc(20);
```

Si l'allocation réussit :

```
str
 |
 v
+--------------------+
| 20 octets mémoire  |
+--------------------+
```

Si l'allocation échoue :

```c
str == NULL
```

Toujours vérifier le retour de `malloc()` :

```c
if (str == NULL)
    return (NULL);
```

---

# free()

Prototype :

```c
void free(void *ptr);
```

`free()` libère une mémoire précédemment allouée avec `malloc()`.

Exemple :

```c
free(str);
```

Sans `free()`, la mémoire reste occupée même si elle n'est plus utilisée.

---

# Pourquoi utiliser malloc ?

On utilise `malloc()` lorsque :

- la taille n'est pas connue à la compilation ;
- on souhaite créer un tableau de taille variable ;
- on crée des structures dynamiques (listes chaînées, arbres, etc.) ;
- on souhaite économiser la mémoire.

Exemple :

```c
unsigned int size;

char *array = malloc(size);
```

---

# Les Memory Leaks

Une fuite mémoire apparaît lorsqu'un programme réserve de la mémoire mais ne la libère jamais.

Exemple :

```c
char *buffer;

buffer = malloc(100);

/* oubli de free(buffer); */
```

Chaque oubli fait perdre de la mémoire.

---

# Vérifier avec Valgrind

Compilation :

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o program
```

Exécution :

```bash
valgrind ./program
```

Si tout est correct :

```
All heap blocks were freed -- no leaks are possible
```

---

# Fonction create_array()

Prototype :

```c
char *create_array(unsigned int size, char c);
```

Cette fonction :

- crée un tableau de caractères ;
- réserve la mémoire avec `malloc()`;
- remplit chaque case avec le caractère `c`;
- retourne un pointeur vers le tableau.

Si :

- `size == 0` → retourne `NULL`;
- `malloc()` échoue → retourne `NULL`.

---

# Déroulement de create_array()

Exemple :

```c
create_array(5, 'H');
```

Étape 1 :

```
malloc(5)
```

Mémoire :

```
Heap

+---+---+---+---+---+
| ? | ? | ? | ? | ? |
+---+---+---+---+---+
```

Étape 2 :

```
Initialisation
```

```
+---+---+---+---+---+
| H | H | H | H | H |
+---+---+---+---+---+
```

Étape 3 :

Retour du pointeur.

---

# Contraintes du projet

- Ubuntu 20.04 LTS
- GCC
- Compilation :

```bash
-Wall -Wextra -Werror -pedantic -std=gnu89
```

- Style Betty obligatoire.
- Aucune variable globale.
- Maximum 5 fonctions par fichier.
- Fonctions autorisées :

```c
malloc
free
_putchar
```

Fonctions interdites :

- printf
- puts
- calloc
- realloc
- etc.

---

# Bonnes pratiques

Toujours :

- vérifier le retour de `malloc()`;
- libérer la mémoire avec `free()`;
- retourner `NULL` en cas d'échec;
- respecter le prototype demandé;
- éviter les fuites mémoire.

---

# Exemple d'utilisation

```c
char *buffer;

buffer = create_array(98, 'H');

if (buffer == NULL)
    return (1);

/* utilisation */

free(buffer);
```

---

# Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 \
0-main.c 0-create_array.c -o a
```

Exécution :

```bash
./a
```

---

# Ressources

- Documentation `malloc`
- Documentation `free`
- Manuel Linux (`man malloc`, `man free`)
- Valgrind User Manual

---

# Auteur

**Bertrand Oeung**

Holberton School – C Programming
