# 📚 C - Pointers, Arrays and Strings - Cheat Sheet

## Variables

Declare a variable:

```c
int number;
char letter;
```

Initialize a variable:

```c
int number = 42;
char letter = 'A';
```

---

# Addresses

Get the address of a variable:

```c
int n = 98;

printf("%p\n", (void *)&n);
```

The `&` operator returns the memory address of a variable.

---

# Pointers

Declare a pointer:

```c
int *p;
```

Store the address of a variable:

```c
int n = 98;
int *p = &n;
```

Access the value stored at the address:

```c
printf("%d\n", *p);
```

Modify the value through the pointer:

```c
*p = 402;
```

---

# Pointer Operators

```text
&   Address of a variable
*   Value stored at an address
```

Example:

```c
int n = 98;
int *p = &n;

printf("%d\n", n);
printf("%p\n", (void *)&n);
printf("%p\n", (void *)p);
printf("%d\n", *p);
```

---

# Arrays

Declare an array:

```c
int numbers[5];
```

Initialize an array:

```c
int numbers[5] = {1, 2, 3, 4, 5};
```

Access an element:

```c
numbers[2];
```

Modify an element:

```c
numbers[0] = 10;
```

Loop through an array:

```c
int i;

for (i = 0; i < 5; i++)
	printf("%d\n", numbers[i]);
```

---

# Strings

Declare a string:

```c
char str[] = "Holberton";
```

Character array:

```c
char word[] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

Print a string:

```c
printf("%s\n", str);
```

Print one character:

```c
_putchar(str[0]);
```

---

# Common String Functions

Length:

```c
strlen(str);
```

Copy:

```c
strcpy(dest, src);
```

Compare:

```c
strcmp(str1, str2);
```

Concatenate:

```c
strcat(dest, src);
```

---

# Pointer Arithmetic

Next element:

```c
p++;
```

Example:

```c
int numbers[] = {1, 2, 3};

int *p = numbers;

printf("%d\n", *p);

p++;

printf("%d\n", *p);
```

---

# Arrays and Pointers

These are equivalent:

```c
numbers[2]
```

```c
*(numbers + 2)
```

---

# Function with a Pointer

```c
void reset_to_98(int *n)
{
	*n = 98;
}
```

---

# Swap Two Variables

```c
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
```

---

# Useful Commands

Compile:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o program
```

Run:

```bash
./program
```

Betty:

```bash
betty *.c
betty main.h
```

---

# Git Workflow

```bash
git status
git add .
git commit -m "Complete pointers arrays and strings tasks"
git push
```

---

# Common Mistakes

* Forgetting `&` when passing an address.
* Forgetting `*` when dereferencing a pointer.
* Accessing an array outside its bounds.
* Forgetting the `'\0'` at the end of a string.
* Confusing a pointer with the value it points to.
* Not initializing a pointer before using it.

---

# Good Practices

* Initialize pointers before using them.
* Use meaningful variable names.
* Respect function prototypes.
* Test every function.
* Check Betty Style before submitting.
* Read compiler errors carefully.

---

# What I Learned

* Variables and memory addresses.
* Pointer declaration and initialization.
* Dereferencing pointers.
* Passing pointers to functions.
* Modifying variables through pointers.
* Creating and using arrays.
* Traversing arrays with loops.
* Creating and manipulating strings.
* Relationship between arrays and pointers.
* Basic pointer arithmetic.
* Writing cleaner and safer C code.

