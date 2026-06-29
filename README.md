# 📚 Low Level Programming - Cheat Sheet

## Compilation

Compile with the required flags:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 file.c -o output
```

Some benchmarking projects require:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-long-long file.c -o output
```

---

# Betty Style

Check one file:

```bash
betty file.c
```

Check the header file:

```bash
betty main.h
```

---

# Git Workflow

Check repository status:

```bash
git status
```

Add files:

```bash
git add .
```

or

```bash
git add filename.c
```

Commit:

```bash
git commit -m "Meaningful commit message"
```

Push:

```bash
git push
```

Restore a modified file:

```bash
git restore filename.c
```

---

# Header Files

Prototype example:

```c
int add(int a, int b);
```

Verify a prototype:

```bash
grep "int add(int a, int b);" main.h
```

---

# Project Structure

Typical files:

* `main.h`
* `0-file.c`
* `1-file.c`
* `_putchar.c`
* `README.md`

---

# Common Loops

For loop:

```c
for (i = 0; i < n; i++)
{
    /* code */
}
```

While loop:

```c
while (condition)
{
    /* code */
}
```

---

# ASCII Conversion

Character to integer:

```c
number = c - '0';
```

Integer to character:

```c
c = number + '0';
```

---

# _putchar()

Print one character:

```c
_putchar('A');
```

Print a newline:

```c
_putchar('\n');
```

---

# Printing Numbers Greater Than 9

```c
if (n >= 10)
    _putchar((n / 10) + '0');

_putchar((n % 10) + '0');
```

---

# Common Patterns

Square:

```text
####
####
####
####
```

Nested loops:

```c
for (i = 0; i < size; i++)
{
    for (j = 0; j < size; j++)
        _putchar('#');

    _putchar('\n');
}
```

Triangle:

```text
   #
  ##
 ###
####
```

Diagonal:

```text
\
 \
  \
   \
```

---

# Benchmarking

Measure execution time:

```c
clock_t start;
clock_t end;

start = clock();

/* code */

end = clock();
```

Convert to seconds:

```c
double elapsed;

elapsed = (double)(end - start) / CLOCKS_PER_SEC;
```

---

# Algorithm Comparison

Always compare:

* Same input
* Same machine
* Same compiler flags

Compute:

* Execution time
* Average execution time
* Relative performance

Example:

```text
Naive algorithm: 3.25 s
Single-pass: 0.00013 s

Naive ≈ 24,000× slower
```

---

# Instrumentation

Measure each phase independently:

```text
TOTAL
BUILD_DATA
PROCESS
REDUCE
```

Typical pattern:

```c
start = clock();

function();

end = clock();
```

---

# Useful Commands

Create a file:

```bash
touch file.c
```

Edit:

```bash
vi file.c
```

List files:

```bash
ls
```

Current directory:

```bash
pwd
```

Compile then execute:

```bash
gcc file.c -o program
./program
```

---

# Debugging

Read compiler errors carefully.

Most common mistakes:

* Missing `#include`
* Missing prototype
* Missing `;`
* Missing `}`
* Wrong return type
* Implicit function declaration
* Unused variable
* Incorrect function signature

---

# Good Practices

* Read the subject carefully.
* Respect the required prototype.
* Keep functions small.
* Use meaningful variable names.
* Follow Betty Style.
* Test before committing.
* Never modify files that the subject forbids changing.
* Measure performance before trying to optimize code.

---

# What I Learned

* C syntax and program structure
* Functions and prototypes
* Header files
* Loops and conditions
* Nested loops
* Character and number manipulation
* `_putchar()`
* Git workflow
* Compilation with strict flags
* Debugging compiler errors
* Benchmarking and performance measurement
* Algorithm comparison
* Execution time instrumentation with `clock()`
* Writing technical reports based on measured results

