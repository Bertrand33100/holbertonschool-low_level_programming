# AI Memory Visualizer

## 1. stack_example.c

...

## 2. heap_example.c

...

## 3. aliasing_example.c

Lors de la compilation avec gcc -Wall -Wextra -Werror -pedantic -std=gnu89, GCC a détecté un use-after-free (pointer 'b' used after 'free') et a arrêté la compilation car -Werror transforme les avertissements en erreurs. Pour analyser le programme, il a été nécessaire de compiler sans -Werror (ou de désactiver cet avertissement spécifique).
...

## 4. crash_example.c

...
