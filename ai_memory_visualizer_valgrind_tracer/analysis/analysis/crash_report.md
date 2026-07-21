# Crash Report – crash_example.c

## 1. Description du crash

Lors de l'exécution du programme, celui-ci affiche :

```text
crash_example: deterministic NULL dereference (segmentation fault)
requesting n=0
```

Le programme s'interrompt ensuite brutalement avec un **Segmentation Fault (SIGSEGV)**.

Le crash est entièrement reproductible : il se produit à chaque exécution avec les mêmes données d'entrée (`n = 0`).

---

## 2. Analyse de la cause racine (Root Cause Analysis)

Le problème débute dans la fonction `main()` lorsque la variable `n` est initialisée à `0`.

```c
int n = 0;
```

Cette valeur est transmise à la fonction :

```c
nums = allocate_numbers(n);
```

Dans `allocate_numbers()`, la condition suivante est immédiatement vérifiée :

```c
if (n <= 0)
    return NULL;
```

Comme `n` vaut `0`, la fonction retourne `NULL` sans effectuer d'allocation mémoire avec `malloc()`.

Le pointeur `nums` contient donc la valeur `NULL`.

Le programme continue ensuite son exécution sans vérifier ce pointeur.

Il exécute l'instruction suivante :

```c
nums[0] = 42;
```

Cette instruction tente d'accéder à l'adresse mémoire `0x0`.

Le système d'exploitation détecte cet accès mémoire invalide et interrompt immédiatement le programme en envoyant le signal **SIGSEGV**.

La cause du crash est donc l'utilisation d'un pointeur `NULL` sans vérification préalable.

---

## 3. Chaîne complète des événements

Le crash résulte de la succession d'événements suivante :

1. `n` est initialisé à `0`.
2. `allocate_numbers(0)` est appelée.
3. La fonction retourne immédiatement `NULL`.
4. `nums` reçoit cette valeur.
5. Le programme tente d'écrire dans `nums[0]`.
6. L'écriture correspond à un accès à l'adresse `0x0`.
7. Le système d'exploitation déclenche un **Segmentation Fault**.

Le Segmentation Fault n'est donc pas la cause du problème, mais sa conséquence.

---

## 4. Nature de l'accès mémoire invalide

L'erreur correspond à un **déréférencement d'un pointeur `NULL`** (_NULL Pointer Dereference_).

Le programme tente d'écrire dans une adresse mémoire qui n'a jamais été allouée.

Aucune mémoire dynamique n'est créée dans le Heap, car `malloc()` n'est jamais appelé.

Le pointeur `nums` reste égal à `NULL` pendant toute l'exécution.

Cette opération constitue un **comportement indéfini (Undefined Behavior)**.

---

## 5. Zone mémoire concernée

L'erreur implique principalement :

- la **Stack**, où est stocké le pointeur `nums` ;
- une tentative d'accès à une adresse mémoire invalide (`0x0`).

Le Heap n'est pas concerné, car aucune allocation dynamique n'est réalisée.

---

## 6. Vérification des explications fournies par une IA

### Explication correcte

Une IA peut indiquer que le programme déréférence un pointeur `NULL` et que cette opération provoque un accès mémoire invalide.

Cette explication est correcte.

### Explication incorrecte

Une autre explication pourrait affirmer que le programme plante parce que `malloc()` échoue.

Cette affirmation est fausse.

Dans ce programme, `malloc()` n'est jamais exécuté.

La fonction `allocate_numbers()` retourne immédiatement `NULL` parce que `n` est inférieur ou égal à `0`.

Le problème ne provient donc pas d'un échec d'allocation mémoire, mais de l'utilisation d'un pointeur `NULL` sans vérification.

---

Cette vérification empêche le programme d'accéder à une adresse mémoire invalide.

---

## 7. Conclusion

La cause du crash est un déréférencement de pointeur `NULL`. La fonction `allocate_numbers()` retourne `NULL` lorsque `n` vaut `0`, mais cette valeur n'est jamais vérifiée avant son utilisation. Le programme tente ensuite d'écrire à l'adresse mémoire `0x0`, ce qui constitue un comportement indéfini. Le système d'exploitation détecte cet accès invalide et interrompt le programme en envoyant un signal **SIGSEGV**.
