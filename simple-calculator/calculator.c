#include <stdio.h>

/**
 * main - Simple calculator
 *
 * Description: This calculator uses decimal division.
 *
 * Return: Always 0
 */
int main(void)
{
	int choice;
	int a;
	int b;

	do {
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		if (scanf("%d", &choice) != 1)
			return (1);

		if (choice < 0 || choice > 4)
		{
			printf("Invalid choice\n");
		}
		else if (choice == 1)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);
			printf("Result: %d\n", a + b);
		}
		else if (choice == 2)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);
			printf("Result: %d\n", a - b);
		}
		else if (choice == 3)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);
			printf("Result: %d\n", a * b);
		}
		else if (choice == 4)
		{
			printf("A: ");
			scanf("%d", &a);
			printf("B: ");
			scanf("%d", &b);

			if (b == 0)
			{
				printf("Error: division by zero\n");
			}
			else
			{
				printf("Result: %.1f\n", (double)a / b);
			}
		}
	} while (choice != 0);

	printf("Bye!\n");

	return (0);
}
