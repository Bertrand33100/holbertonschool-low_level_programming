# C - More functions, more nested loops

## Objectifs

- Créer des fonctions
- Utiliser des paramètres
- Utiliser `if`, `else`, `else if`
- Utiliser des boucles `for`
- Imbriquer des boucles
- Dessiner des formes avec `_putchar`

---

## Structure d'une fonction

```c
void print_square(int size);
```

- `void` → ne retourne rien
- `print_square` → nom de la fonction
- `int size` → paramètre

---

## Boucle `for`

```c
for (i = 0; i < 5; i++)
```

Lecture :

- Commencer à 0
- Continuer tant que `i < 5`
- Ajouter 1 à chaque tour (`i++`)

---

## Conditions

```c
if (...)
```

→ Si la condition est vraie.

```c
else
```

→ Sinon.

```c
else if (...)
```

→ Sinon, tester une autre condition.

---

## Opérateurs

| Opérateur | Signification |
|-----------|---------------|
| `=` | Affectation |
| `==` | Égal à |
| `!=` | Différent de |
| `<` | Inférieur à |
| `>` | Supérieur à |
| `<=` | Inférieur ou égal |
| `>=` | Supérieur ou égal |
| `&&` | ET |
| `||` | OU |
| `++` | Ajouter 1 |
| `%` | Modulo (reste d'une division) |

Exemple :

```c
7 % 3 == 1
6 % 3 == 0
```

---

## `_putchar`

Affiche un seul caractère.

```c
_putchar('A');
_putchar('\n');
```

---

## Boucles imbriquées

Une boucle dans une autre.

```text
Boucle lignes
    ↓
Boucle colonnes
```

Utilisées pour :

- Carré
- Triangle
- Diagonale

---

## Dessins

### Ligne

```
_____
```

→ 1 boucle

---

### Diagonale

```
\
 \
  \
```

→ Boucle lignes + boucle espaces

---

### Carré

```
####
####
####
####
```

→ Boucle lignes + boucle `#`

---

### Triangle

```
   #
  ##
 ###
####
```

→ Boucle lignes + boucle espaces + boucle `#`

---

## Modulo `%`

Permet de savoir si un nombre est divisible.

```c
i % 3 == 0
```

→ divisible par 3

```c
i % 5 == 0
```

→ divisible par 5

---

## FizzBuzz

Ordre des tests :

```text
Divisible par 3 ET 5 ?
    ↓
FizzBuzz

Sinon divisible par 3 ?
    ↓
Fizz

Sinon divisible par 5 ?
    ↓
Buzz

Sinon
    ↓
Afficher le nombre
```

---

## Erreurs fréquentes

- Confondre `=` et `==`
- Oublier `\n`
- Oublier les accolades `{ }`
- Mauvaise condition de boucle (`<` / `<=`)
- Tester `Fizz` avant `FizzBuzz`

---

## Fonctions du projet

- `print_numbers()`
- `print_most_numbers()`
- `more_numbers()`
- `print_line()`
- `print_diagonal()`
- `print_square()`
- `print_triangle()`

---

## À retenir

- Une fonction = une tâche.
- Une boucle = répéter une action.
- Une boucle imbriquée = lignes + colonnes.
- `if` = prendre une décision.
- `%` = tester la divisibilité.
- Toujours réfléchir à l'algorithme avant d'écrire le code.
