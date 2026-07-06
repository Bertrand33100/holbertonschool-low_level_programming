#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to the string
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i;
	char separators[] = " \t\n,;.!?\"(){}";
	int j;
	int is_new_word;

	is_new_word = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (is_new_word && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}

		is_new_word = 0;

		for (j = 0; separators[j] != '\0'; j++)
		{
			if (str[i] == separators[j])
			{
				is_new_word = 1;
				break;
			}
		}
	}

	return (str);
}
