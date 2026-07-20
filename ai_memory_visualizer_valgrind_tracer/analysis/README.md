# AI Memory Visualizer & Memory Analysis

## Introduction

Ce projet a pour objectif de comprendre le fonctionnement de la mémoire en C. Il ne s'agit pas seulement d'utiliser des pointeurs ou `malloc()`, mais de comprendre ce qui se passe réellement dans la mémoire pendant l'exécution d'un programme.

L'objectif est de développer une méthode de raisonnement permettant d'expliquer précisément pourquoi un programme fonctionne, provoque une fuite mémoire ou se termine par un crash.

---

# Objectifs d'apprentissage

À la fin de ce projet, je dois être capable de :

- Comprendre la différence entre la **Stack** et le **Heap**.
- Identifier où sont stockées les variables.
- Comprendre la durée de vie (_lifetime_) des objets en mémoire.
- Comprendre le fonctionnement des pointeurs.
- Identifier les situations d'aliasing (plusieurs pointeurs vers la même mémoire).
- Déterminer quel pointeur est responsable de la libération de la mémoire.
- Détecter les fuites mémoire (_Memory Leaks_).
- Comprendre les erreurs **Invalid Read**, **Invalid Write**, **Use After Free** et **Double Free**.
- Lire et interpréter les messages de Valgrind.
- Expliquer précisément la cause d'un **Segmentation Fault**.

---

# Concepts importants

## Stack

La Stack contient :

- les variables locales ;
- les paramètres des fonctions ;
- les appels de fonctions (Stack Frames).

La mémoire est créée automatiquement lorsqu'une fonction commence et détruite automatiquement lorsqu'elle se termine.

---

## Heap

Le Heap contient la mémoire allouée dynamiquement avec :

- `malloc()`
- `calloc()`
- `realloc()`

Cette mémoire reste allouée jusqu'à l'appel de :

```c
free(ptr);
```

---

## Les pointeurs

Un pointeur ne contient pas une valeur.

Il contient l'adresse d'une variable ou d'une zone mémoire.

Exemple :

```c
int age = 25;
int *p = &age;
```

Le pointeur `p` contient l'adresse de `age`.

---

## Lifetime

Le _lifetime_ représente la durée de vie d'une donnée.

Une variable locale existe uniquement pendant l'exécution de sa fonction.

Une mémoire allouée avec `malloc()` existe jusqu'à ce que `free()` soit appelé.

---

## Aliasing

L'aliasing se produit lorsque plusieurs pointeurs pointent vers la même zone mémoire.

Exemple :

```c
int *a = malloc(sizeof(int));
int *b = a;
```

Les deux pointeurs désignent la même adresse.

---

## Ownership

Une allocation mémoire doit être libérée une seule fois.

Le programme doit toujours savoir quel pointeur est responsable du `free()`.

---

# Erreurs mémoire

## Memory Leak

Une zone mémoire est allouée mais jamais libérée.

Conséquence :

- perte de mémoire ;
- Valgrind affiche **Definitely Lost**.

---

## Use After Free

Le programme continue d'utiliser une mémoire après son `free()`.

Cela provoque un comportement indéfini.

---

## Dangling Pointer

Le pointeur existe encore mais pointe vers une mémoire qui n'est plus valide.

Bonne pratique :

```c
free(ptr);
ptr = NULL;
```

---

## Invalid Read

Lecture d'une zone mémoire invalide.

---

## Invalid Write

Écriture dans une zone mémoire invalide.

---

## Double Free

La même mémoire est libérée deux fois.

Cette erreur peut provoquer un crash du programme.

---

## Segmentation Fault

Le programme tente d'accéder à une mémoire interdite ou inexistante.

Il faut être capable d'expliquer précisément la chaîne suivante :

```
Code
↓
État de la mémoire
↓
Erreur mémoire
↓
Crash
```

---

# Valgrind

Valgrind permet de détecter les erreurs mémoire.

Les messages les plus fréquents sont :

- Invalid Read
- Invalid Write
- Definitely Lost
- Use After Free
- Double Free

Il permet de retrouver la ligne responsable de l'erreur.

---

# Déroulement du projet

Pour chaque programme :

1. Compiler avec le Makefile.
2. Exécuter le programme normalement.
3. Identifier les changements de mémoire.
4. Construire une carte mémoire (Stack / Heap).
5. Utiliser une IA pour générer une première analyse.
6. Vérifier et corriger les erreurs éventuelles de l'IA.
7. Rédiger une analyse complète dans `analysis/memory_maps.md`.

---

# Questions à se poser

Pour chaque programme, répondre aux questions suivantes :

- Où est stockée chaque variable ?
- Est-elle dans la Stack ou le Heap ?
- Quand est-elle créée ?
- Quand disparaît-elle ?
- Quels pointeurs pointent vers cette mémoire ?
- Existe-t-il un aliasing ?
- Qui est responsable du `free()` ?
- Y a-t-il une fuite mémoire ?
- Y a-t-il un accès mémoire invalide ?
- Que signalera Valgrind ?
- Si le programme plante, quelle est la cause exacte ?

---

# Outils utilisés

- Langage C
- GCC
- Makefile
- Valgrind
- Git
- GitHub
- Intelligence Artificielle (comme outil d'analyse uniquement)

---

# Conclusion

Ce projet permet de construire une compréhension solide de la gestion de la mémoire en C. Il apprend à raisonner sur l'état de la mémoire à chaque étape de l'exécution d'un programme, à interpréter les diagnostics de Valgrind et à expliquer de manière précise les causes des erreurs mémoire plutôt que de simplement constater qu'un programme échoue.
