# C - Fonctions Variadiques

## Description

Ce projet a pour objectif de découvrir les **fonctions variadiques** en langage C.

Une fonction variadique est une fonction capable de recevoir un **nombre variable d'arguments**. Pour parcourir ces arguments, on utilise les macros fournies par la bibliothèque standard **`<stdarg.h>`**.

---

# Objectifs d'apprentissage

À la fin de ce projet, je dois être capable de comprendre :

- Ce qu'est une fonction variadique.
- Comment déclarer une fonction avec `...`.
- À quoi sert `va_list`.
- Comment utiliser `va_start`.
- Comment récupérer les arguments avec `va_arg`.
- Comment terminer correctement avec `va_end`.
- Pourquoi utiliser le mot-clé `const`.

---

# Bibliothèque utilisée

```c
#include <stdarg.h>
```

Cette bibliothèque fournit les macros nécessaires pour manipuler un nombre variable d'arguments.

---

# Les macros importantes

| Macro      | Rôle                                           |
| ---------- | ---------------------------------------------- |
| `va_list`  | Déclare une liste d'arguments.                 |
| `va_start` | Initialise la lecture des arguments variables. |
| `va_arg`   | Récupère le prochain argument de la liste.     |
| `va_end`   | Termine l'utilisation de la liste d'arguments. |

---

# Notions utilisées

- Fonctions variadiques
- Boucles (`for`)
- Variables
- Fonctions
- Prototypes
- Fichiers d'en-tête (`.h`)
- Bibliothèque `stdarg.h`
- Mot-clé `const`

---

# Fichiers du projet

| Fichier                | Description                                                    |
| ---------------------- | -------------------------------------------------------------- |
| `variadic_functions.h` | Contient les prototypes des fonctions.                         |
| `0-sum_them_all.c`     | Additionne tous les arguments reçus.                           |
| `1-print_numbers.c`    | Affiche une liste de nombres séparés par un séparateur.        |
| `2-print_strings.c`    | Affiche une liste de chaînes de caractères.                    |
| `3-print_all.c`        | Affiche plusieurs types de données (char, int, float, string). |

---

# Exemple

```c
sum_them_all(4, 10, 20, 30, 40);
```

Résultat :

```
100
```

---

# Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o programme
```

---

# Ce que je dois retenir

- Une fonction variadique peut recevoir un nombre inconnu d'arguments.
- Les arguments variables sont indiqués par `...`.
- `stdarg.h` permet de parcourir ces arguments.
- `va_start` démarre la lecture.
- `va_arg` lit chaque argument un par un.
- `va_end` termine la lecture.
- `const` empêche la modification d'une variable.

---

# Auteur

**Bertrand33100**
