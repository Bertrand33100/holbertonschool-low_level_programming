# Analyse Valgrind

## Introduction

Valgrind est un outil d'analyse mémoire qui permet de détecter les erreurs liées à l'utilisation de la mémoire pendant l'exécution d'un programme. Il identifie notamment les fuites mémoire, les accès mémoire invalides, l'utilisation de mémoire après sa libération et d'autres erreurs de gestion de la mémoire.

Pour chaque programme de ce projet, j'ai comparé les résultats de Valgrind avec mes schémas mémoire afin de comprendre précisément l'origine de chaque erreur.

---

# 1. aliasing_example.c

## Erreurs détectées par Valgrind

Valgrind signale :

- **Invalid Read**
- **Invalid Write**

## Objet mémoire concerné

Le tableau dynamique alloué avec `malloc()` et référencé par les pointeurs `a` et `b`.

## Cause de l'erreur

Le programme crée deux pointeurs qui référencent la même zone mémoire :

```c
b = a;
```

La mémoire est ensuite libérée :

```c
free(a);
```

Cependant, le pointeur `b` continue de contenir l'adresse de cette mémoire.

Le programme tente ensuite de lire puis d'écrire dans cette zone :

```c
b[2];
b[2] = 999;
```

La durée de vie de cette mémoire est terminée depuis l'appel à `free(a)`. Le pointeur `b` devient donc un **pointeur pendant (dangling pointer)** et son utilisation provoque un **use-after-free**.

## Classification de l'erreur

- Use-after-free
- Dangling pointer
- Invalid Read
- Invalid Write

## Vérification de l'explication de l'IA

Une explication générée par une IA indiquait que `free(a)` supprimait automatiquement tous les pointeurs vers cette mémoire.

Cette explication est fausse.

`free()` libère uniquement la mémoire allouée. Les pointeurs qui référencent cette mémoire ne sont pas modifiés automatiquement. Le pointeur `b` continue donc de contenir l'ancienne adresse, qui n'est plus valide.

---

# 2. heap_example.c

## Erreurs détectées par Valgrind

Valgrind indique :

```text
definitely lost: 6 bytes in 1 blocks
```

## Objet mémoire concerné

La chaîne de caractères :

```c
alice->name
```

## Cause de l'erreur

Chaque appel à `person_new()` réalise deux allocations :

- une allocation pour la structure `Person` ;
- une allocation pour la chaîne de caractères contenant le nom.

Pour `bob`, les deux allocations sont correctement libérées :

```c
free(bob->name);
free(bob);
```

Pour `alice`, seule la structure est libérée :

```c
free(alice);
```

La mémoire allouée pour `alice->name` reste dans le Heap et devient inaccessible.

Valgrind la signale donc comme une **fuite mémoire**.

## Classification de l'erreur

- Memory Leak (fuite mémoire)
- Lost Ownership (perte du pointeur propriétaire)
- Definitely Lost

## Vérification de l'explication de l'IA

Une IA expliquait que libérer une structure libérait automatiquement les champs qu'elle contient.

Cette explication est incorrecte.

Chaque appel à `malloc()` doit avoir son propre appel à `free()`. Les pointeurs contenus dans une structure doivent être libérés individuellement avant de libérer la structure.

---

# 3. crash_example.c

## Erreurs détectées par Valgrind

Valgrind indique :

```text
Invalid write of size 4
Address 0x0 is not stack'd, malloc'd or (recently) free'd
```

Puis :

```text
Process terminating with default action of signal 11 (SIGSEGV)
```

## Objet mémoire concerné

Le pointeur :

```c
nums
```

## Cause de l'erreur

Le programme appelle :

```c
allocate_numbers(0);
```

Comme `n` vaut `0`, la fonction retourne immédiatement :

```c
NULL
```

Aucune mémoire n'est allouée dans le Heap.

Le programme tente ensuite d'écrire :

```c
nums[0] = 42;
```

Le pointeur `nums` étant égal à `NULL`, cette instruction tente d'écrire à l'adresse mémoire `0x0`.

Le système d'exploitation interrompt immédiatement le programme avec un **Segmentation Fault**.

## Classification de l'erreur

- Déréférencement d'un pointeur `NULL`
- Invalid Write
- Segmentation Fault

## Vérification de l'explication de l'IA

Une IA expliquait que le crash était dû à un échec de `malloc()`.

Cette explication est fausse.

Dans ce programme, `malloc()` n'est jamais exécuté. La fonction retourne `NULL` avant d'atteindre l'appel à `malloc()` car `n <= 0`.

L'erreur provient uniquement du fait que le programme utilise un pointeur `NULL` sans le vérifier.

---

# 4. stack_example.c

## Résultat de Valgrind

Valgrind ne signale aucune erreur.

## Explication

Le programme n'effectue aucune allocation dynamique avec `malloc()`.

Toutes les variables sont stockées dans la Stack et sont automatiquement détruites lorsque les fonctions se terminent.

Aucune fuite mémoire ni accès invalide n'est détecté.

---

# Ce que j'ai appris

Grâce à ce projet, j'ai appris à relier les messages de Valgrind au comportement réel de la mémoire d'un programme.

Je sais désormais identifier les principales erreurs mémoire :

- fuite mémoire (_Memory Leak_) ;
- lecture invalide (_Invalid Read_) ;
- écriture invalide (_Invalid Write_) ;
- utilisation d'une mémoire déjà libérée (_Use-after-free_) ;
- pointeur pendant (_Dangling Pointer_) ;
- déréférencement d'un pointeur `NULL` ;
- Segmentation Fault.

J'ai également compris que les explications fournies par une IA doivent toujours être vérifiées en comparant le code source, les schémas mémoire et les résultats de Valgrind.

---

# Conclusion

Ce projet m'a permis de comprendre que chaque message affiché par Valgrind correspond à une erreur précise dans la gestion de la mémoire. En analysant les rapports de Valgrind et en les comparant avec le code et les schémas mémoire, j'ai développé une meilleure compréhension du fonctionnement de la mémoire en C et des bonnes pratiques pour écrire des programmes plus fiables et plus sécurisés.

Auteur

Bertrand
