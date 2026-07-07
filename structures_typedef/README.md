# Structures and Typedef

## Description

This project introduces **structures (`struct`)** and **`typedef`** in the C programming language.

Structures allow grouping multiple variables of different types into a single object. They are useful for representing real-world entities such as a person, a dog, a student, or a book.

The project also covers the use of `typedef` to create aliases for existing data types, making code easier to read and maintain.

---

## Learning Objectives

By the end of this project, I am able to:

- Understand what a structure is.
- Define and declare structures.
- Access and modify structure members.
- Understand when and why structures are useful.
- Create aliases using `typedef`.
- Improve code readability with `typedef`.
- Organize structure declarations inside header files.
- Use include guards to prevent multiple inclusions.

---

## Concepts

### Structure (`struct`)

A structure groups several related variables under one name.

Example:

- Name
- Age
- Owner

These values belong to the same object.

---

### Typedef

`typedef` creates an alias for an existing type.

Instead of writing:

```c
struct dog my_dog;
```

You can write:

```c
dog_t my_dog;
```

This makes the code shorter and easier to read.

---

## Files

| File        | Description                         |
| ----------- | ----------------------------------- |
| `dog.h`     | Defines the `struct dog` structure. |
| `README.md` | Project documentation.              |

---

## Compilation

Compile with:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o output
```

---

## Betty Style

This project follows the Betty coding style.

Check style with:

```bash
betty *.c *.h
```

---

## Requirements

- Ubuntu 20.04 LTS
- GCC
- C89 (`-std=gnu89`)
- No global variables
- Maximum of 5 functions per file
- Allowed functions:
  - `printf`
  - `malloc`
  - `free`
  - `exit`

---

## Author

Bertrand Oeung

Student at Holberton School
