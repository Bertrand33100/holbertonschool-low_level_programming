#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: pointer to the name
 * @f: pointer to a function that prints the name
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
