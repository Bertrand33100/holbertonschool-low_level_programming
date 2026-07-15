# C - argc, argv

## Description

Ce projet a pour objectif d'apprendre à utiliser les **arguments passés au programme** depuis le terminal.

Jusqu'à présent, nos programmes étaient exécutés sans recevoir d'informations de l'utilisateur. Grâce à `argc` et `argv`, un programme peut récupérer des données saisies lors de son exécution.

Exemple :

```bash
./programme Bonjour 42
```

Le programme reçoit alors les arguments :

- `Bonjour`
- `42`

---

# Objectifs d'apprentissage

À la fin de ce projet, je dois être capable de comprendre :

- Ce que sont `argc` et `argv`.
- Comment récupérer les arguments passés au programme.
- Les deux prototypes possibles de la fonction `main`.
- La différence entre `argc` et `argv`.
- Comment parcourir les arguments avec une boucle.
- Comment convertir une chaîne de caractères en entier avec `atoi()`.
- Comment éviter les avertissements du compilateur avec `(void)` ou `__attribute__((unused))`.

---

# Les deux prototypes de main

Sans argument :

```c
int main(void);
```

Avec arguments :

```c
int main(int argc, char *argv[]);
```

ou

```c
int main(int argc, char **argv);
```

Les deux dernières écritures sont équivalentes.

---

# argc

`argc` signifie **Argument Count**.

Il contient le **nombre total d'arguments** passés au programme, **nom du programme compris**.

Exemple :

```bash
./hello Bertrand
```

Valeur de `argc` :

```
2
```

---

# argv

`argv` signifie **Argument Vector**.

C'est un tableau contenant tous les arguments sous forme de chaînes de caractères.

Exemple :

```bash
./calc 5 + 8
```

Le programme reçoit :

```text
argv[0] = "./calc"
argv[1] = "5"
argv[2] = "+"
argv[3] = "8"
argv[4] = NULL
```

---

# argc et argv

| Élément          | Description                     |
| ---------------- | ------------------------------- |
| `argc`           | Nombre d'arguments              |
| `argv`           | Tableau contenant les arguments |
| `argv[0]`        | Nom du programme                |
| `argv[1]`        | Premier argument                |
| `argv[argc - 1]` | Dernier argument                |
| `argv[argc]`     | Toujours `NULL`                 |

---

# Fonctions utilisées

- `printf()`
- `atoi()`
- `exit()` (si nécessaire)

---

# Notions utilisées

- Fonction `main`
- Arguments de la ligne de commande
- Tableaux
- Chaînes de caractères
- Boucles
- Conditions
- Conversion de chaînes en nombres
- `(void)` pour les variables inutilisées

---

# Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o programme
```

---

# Ce qu'il faut retenir

- `argc` compte le nombre d'arguments.
- `argv` contient tous les arguments.
- Tous les arguments sont des chaînes de caractères.
- Le nom du programme est toujours stocké dans `argv[0]`.
- Pour obtenir un entier, il faut utiliser `atoi()`.
- Si une variable n'est pas utilisée, on peut écrire :

```c
(void)argc;
(void)argv;
```

pour éviter un avertissement du compilateur.

---

# Exemple

Commande :

```bash
./addition 15 25
```

Le programme reçoit :

```text
argc = 3

argv[0] = "./addition"
argv[1] = "15"
argv[2] = "25"
```

Après conversion avec `atoi()` :

```
15 + 25 = 40
```

---

# Auteur

**Bertrand33100**
