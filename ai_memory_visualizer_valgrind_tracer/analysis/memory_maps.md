# AI Memory Visualizer

## 1. stack_example.c

# Analyse mémoire – stack_example.c

## Objectif du programme

Ce programme permet d'observer le fonctionnement de la **Stack (pile)** lors d'appels de fonctions récursifs. Il montre que chaque appel de fonction crée une nouvelle frame (cadre d'exécution) contenant ses propres variables locales. Contrairement aux autres programmes, aucune allocation dynamique n'est réalisée : le **Heap n'est jamais utilisé**.

## Déroulement de l'exécution

Le programme commence dans la fonction `main()`, qui affiche un message puis appelle la fonction `walk_stack(0, 3)`.

À chaque appel de `walk_stack()`, une nouvelle variable locale `marker` est créée dans la Stack. La fonction appelle ensuite `dump_frame()`, qui crée à son tour trois variables locales :

- `local_int`
- `local_buf`
- `p_local`

Ces variables existent uniquement pendant l'exécution de `dump_frame()`. Lorsque la fonction se termine, elles sont automatiquement supprimées de la Stack.

La fonction `walk_stack()` s'appelle ensuite elle-même jusqu'à atteindre la profondeur maximale (`depth = 3`). Chaque appel récursif crée une nouvelle frame dans la Stack avec ses propres copies des variables locales. Les adresses affichées par le programme montrent que chaque appel possède des variables différentes stockées à des emplacements mémoire différents.

Une fois la profondeur maximale atteinte, les appels se terminent dans l'ordre inverse de leur création. Les frames sont alors retirées de la Stack une par une jusqu'au retour dans `main()`.

## Stack

La Stack contient successivement :

- les variables de `main()`,
- les variables `marker` de chaque appel à `walk_stack()`,
- les variables `local_int`, `local_buf` et `p_local` de chaque appel à `dump_frame()`.

Chaque appel de fonction possède sa propre frame et ses propres variables locales.

## Heap

Le programme n'utilise jamais `malloc()`, `calloc()` ou `realloc()`.

Aucune mémoire n'est allouée dans le Heap.

## Durée de vie des variables

Les variables locales existent uniquement pendant l'exécution de la fonction dans laquelle elles sont déclarées.

Lorsque la fonction se termine, ces variables sont automatiquement détruites et leur espace mémoire est libéré dans la Stack.

## Résultat de Valgrind

Valgrind ne détecte normalement aucune erreur mémoire.

Le programme :

- ne lit pas de mémoire invalide ;
- n'écrit pas dans une mémoire invalide ;
- n'utilise pas de mémoire après un `free()` ;
- ne présente aucune fuite mémoire puisqu'aucune mémoire dynamique n'est allouée.

## Correction d'une explication d'IA

Une explication incorrecte pourrait être :

> « Les variables locales restent en mémoire après la fin de la fonction. »

Cette affirmation est fausse.

Les variables locales sont stockées dans la Stack et existent uniquement pendant l'exécution de leur fonction. À chaque retour de fonction, la frame correspondante est supprimée et toutes les variables locales disparaissent automatiquement.

## Conclusion

Ce programme montre le fonctionnement de la Stack lors des appels récursifs. Chaque appel crée une nouvelle frame contenant ses propres variables locales. Les adresses mémoire affichées permettent de visualiser cette organisation. Aucune allocation dynamique n'est utilisée, le Heap reste donc vide pendant toute l'exécution du programme.

## 2. heap_example.c

# Analyse mémoire – heap_example.c

## Objectif du programme

Ce programme montre comment utiliser `malloc()` pour créer des structures dans le Heap. Il illustre également l'importance de libérer toutes les allocations afin d'éviter les fuites mémoire (_memory leaks_).

## Déroulement de l'exécution

Le programme crée deux pointeurs, `alice` et `bob`, initialisés à `NULL`.

La fonction `person_new()` est appelée deux fois. Pour chaque personne, deux allocations sont réalisées :

- une allocation pour la structure `Person` ;
- une allocation pour la chaîne de caractères contenant le nom.

Au total, quatre allocations sont effectuées dans le Heap :

- la structure `alice` ;
- la chaîne `"Alice"` ;
- la structure `bob` ;
- la chaîne `"Bob"`.

Le programme affiche ensuite les adresses mémoire des structures et de leurs noms.

## Stack

La Stack contient :

- `alice`
- `bob`
- les variables locales utilisées dans `person_new()` (`p`, `len` et `i`).

Ces variables sont automatiquement détruites lorsque les fonctions se terminent.

## Heap

Le Heap contient quatre blocs mémoire :

```text
alice -------> +----------------------+
               | Person               |
               | age = 30             |
               | name ---------------+|
               +---------------------||
                                     ||
                                     \/
                                  "Alice"

bob ---------> +----------------------+
               | Person               |
               | age = 41             |
               | name ---------------+|
               +---------------------||
                                     ||
                                     \/
                                   "Bob"
```

## Libération de la mémoire

Pour `bob`, la mémoire est correctement libérée :

```c
free(bob->name);
free(bob);
```

En revanche, pour `alice`, la fonction `person_free_partial()` exécute uniquement :

```c
free(alice);
```

La mémoire contenant la chaîne `"Alice"` n'est jamais libérée.

Cette allocation reste présente dans le Heap jusqu'à la fin du programme.

## Résultat de Valgrind

Valgrind indique :

- **5 allocations**
- **4 libérations**
- **1 bloc mémoire perdu**

Le résumé affiche :

```text
definitely lost: 6 bytes in 1 blocks
```

Ces 6 octets correspondent à la mémoire allouée pour la chaîne `"Alice"` (5 caractères + le caractère de fin `'\0'`).

Valgrind indique également que cette allocation provient de :

- `malloc()` dans `person_new()`
- ligne 21 de `heap_example.c`

Cela confirme que la chaîne de caractères de `alice` n'a jamais été libérée.

## Durée de vie des variables

| Variable           | Mémoire | Durée de vie                   |
| ------------------ | ------- | ------------------------------ |
| `alice`            | Stack   | Pendant `main()`               |
| `bob`              | Stack   | Pendant `main()`               |
| `p`, `len`, `i`    | Stack   | Pendant `person_new()`         |
| Structure `Person` | Heap    | De `malloc()` jusqu'à `free()` |
| Chaîne `name`      | Heap    | De `malloc()` jusqu'à `free()` |

## Correction d'une explication d'IA

Une explication incorrecte pourrait être :

> « Appeler `free()` sur une structure libère automatiquement toute la mémoire qu'elle référence. »

Cette affirmation est fausse.

`free()` libère uniquement la mémoire pointée par son argument. Les pointeurs contenus dans une structure doivent être libérés séparément.

Dans ce programme, il aurait fallu exécuter :

```c
free(alice->name);
free(alice);
```

pour éviter la fuite mémoire.

## Conclusion

Cette analyse montre que chaque appel à `malloc()` doit avoir un appel correspondant à `free()`. Même si une structure est libérée, les allocations qu'elle contient doivent également être libérées explicitement. Valgrind détecte cette erreur en signalant une fuite mémoire de 6 octets correspondant à la chaîne `"Alice"`.

## 3. aliasing_example.c

# Analyse mémoire – aliasing_example.c

## Objectif du programme

Ce programme illustre le fonctionnement de l'allocation dynamique avec `malloc()`, le principe de l'aliasing (deux pointeurs qui référencent la même zone mémoire), ainsi que les conséquences d'une utilisation de la mémoire après un appel à `free()` (_use-after-free_).

## Déroulement de l'exécution

Au début du programme, les variables `a`, `b` et `n` sont créées dans la **Stack**. Les pointeurs `a` et `b` sont initialisés à `NULL`.

La fonction `make_numbers(5)` est ensuite appelée. Elle alloue dynamiquement un tableau de cinq entiers dans le **Heap** à l'aide de `malloc()`. Les valeurs du tableau sont initialisées à `0`, `11`, `22`, `33` et `44`. L'adresse de ce tableau est retournée à la fonction `main()` et stockée dans le pointeur `a`.

L'instruction `b = a;` copie uniquement l'adresse mémoire. Les pointeurs `a` et `b` pointent donc vers la même zone mémoire du Heap. C'est ce qu'on appelle **l'aliasing**.

Le programme affiche ensuite les adresses de `a` et `b`. Lors de l'exécution, les deux pointeurs possèdent la même adresse, ce qui confirme qu'ils référencent le même tableau.

L'appel à `free(a)` libère la mémoire allouée dans le Heap. Toutefois, les variables `a` et `b` contiennent toujours cette ancienne adresse. Elles deviennent alors des **pointeurs pendants (dangling pointers)**.

Le programme continue ensuite à lire (`b[2]`) puis à modifier (`b[3] = 1234`) cette mémoire déjà libérée. Cette situation correspond à une erreur de type **use-after-free**. Le comportement du programme devient alors indéfini : il peut afficher une valeur incorrecte, sembler fonctionner ou provoquer un plantage.

## Analyse des résultats Valgrind

L'exécution avec Valgrind met en évidence trois erreurs mémoire :

- **Invalid Read of size 4** à la ligne 42 : le programme tente de lire un entier dans une zone mémoire déjà libérée.
- **Invalid Write of size 4** à la ligne 44 : le programme tente d'écrire dans une zone mémoire qui n'est plus valide.
- **Invalid Read of size 4** à la ligne 45 : le programme relit une mémoire déjà libérée.

Valgrind indique également que la mémoire concernée a été :

- allouée par `malloc()` dans `make_numbers()` ;
- libérée par `free(a)` dans `main()`.

Le résumé du Heap affiche :

- **2 allocations**
- **2 libérations**
- **0 octet encore alloué à la fin du programme**

Le message _"All heap blocks were freed -- no leaks are possible"_ confirme qu'il n'y a **aucune fuite mémoire**. Le problème n'est donc pas un oubli de `free()`, mais l'utilisation d'une mémoire après sa libération.

## Correction d'une explication d'IA

Une explication incorrecte pourrait être :

> « Après `free(a)`, seul le pointeur `a` devient invalide, tandis que `b` reste valide. »

Cette explication est fausse. Les pointeurs `a` et `b` pointent vers la même zone mémoire. Lorsque `free(a)` est exécuté, cette zone est libérée pour tous les pointeurs qui y font référence. Les deux pointeurs deviennent donc des pointeurs pendants et il est interdit de les déréférencer.

## Conclusion

Cette analyse montre l'importance de comprendre la différence entre la Stack et le Heap, le fonctionnement de `malloc()` et `free()`, ainsi que les risques liés à l'aliasing. Elle met également en évidence qu'un pointeur conservant une adresse mémoire après un `free()` n'est plus utilisable. Valgrind permet de détecter précisément ces erreurs de type **use-after-free** grâce aux messages **Invalid Read** et **Invalid Write**.

## 4. crash_example.c

# Analyse mémoire – crash_example.c

## Objectif du programme

Ce programme illustre une erreur classique en C : le déréférencement d'un pointeur `NULL`. Il provoque volontairement un **Segmentation Fault** afin de montrer comment Valgrind détecte un accès mémoire invalide.

## Déroulement de l'exécution

Le programme déclare deux variables dans la Stack :

- `nums`, initialisé à `NULL`
- `n`, initialisé à `0`

La fonction `allocate_numbers(n)` est ensuite appelée.

Comme `n` est égal à `0`, la condition suivante est vraie :

```c
if (n <= 0)
    return NULL;
```

La fonction retourne donc immédiatement `NULL` sans appeler `malloc()`.

Le pointeur `nums` contient alors la valeur `NULL`.

Le programme exécute ensuite :

```c
nums[0] = 42;
```

Cette instruction tente d'écrire dans une zone mémoire inexistante (adresse `0x0`), ce qui provoque immédiatement un **Segmentation Fault**.

Le programme s'arrête avant d'exécuter les instructions suivantes.

## Organisation de la mémoire

### Stack

La Stack contient :

- `nums`
- `n`
- les variables locales `arr` et `i` de la fonction `allocate_numbers()`.

Ces variables sont automatiquement détruites à la fin des fonctions.

### Heap

Aucune mémoire n'est allouée dans le Heap.

La fonction `allocate_numbers()` retourne avant l'appel à `malloc()`.

## Résultat de Valgrind

Valgrind signale l'erreur suivante :

```text
Invalid write of size 4
Address 0x0 is not stack'd, malloc'd or (recently) free'd
```

Cette erreur indique que le programme tente d'écrire 4 octets à l'adresse mémoire `0x0`.

Valgrind indique également :

```text
Process terminating with default action of signal 11 (SIGSEGV)
```

Le système d'exploitation interrompt le programme car il tente d'accéder à une adresse mémoire invalide.

Le résumé mémoire affiche :

```text
definitely lost: 0 bytes
still reachable: 1,024 bytes in 1 blocks
```

Les **1024 octets "still reachable"** correspondent à des allocations internes de la bibliothèque standard (`stdio`) qui n'ont pas été libérées car le programme s'est arrêté brutalement. Il ne s'agit pas d'une fuite mémoire du programme.

La ligne importante est :

```text
definitely lost: 0 bytes
```

Cela confirme qu'aucune fuite mémoire n'a été créée par le programme.

## Durée de vie des variables

| Variable        | Mémoire | Durée de vie                       |
| --------------- | ------- | ---------------------------------- |
| `nums`          | Stack   | Pendant toute la fonction `main()` |
| `n`             | Stack   | Pendant toute la fonction `main()` |
| `arr`           | Stack   | Pendant `allocate_numbers()`       |
| `i`             | Stack   | Pendant `allocate_numbers()`       |
| Allocation Heap | Aucune  | Aucune allocation réalisée         |

## Correction d'une explication d'IA

Une IA pourrait affirmer :

> « Le programme plante parce que `malloc()` a échoué. »

Cette explication est incorrecte.

Le programme ne tente jamais d'allouer de mémoire avec `malloc()` puisque `n` vaut `0`. La fonction retourne immédiatement `NULL`.

Le véritable problème est que le programme utilise ce pointeur `NULL` sans le vérifier avant d'écrire :

```c
nums[0] = 42;
```

## Conclusion

Ce programme montre qu'il est indispensable de vérifier qu'un pointeur est différent de `NULL` avant de l'utiliser. Déréférencer un pointeur `NULL` provoque un accès mémoire invalide et entraîne un **Segmentation Fault**. Valgrind permet d'identifier précisément l'origine de cette erreur et la ligne de code responsable.

Création Ia
