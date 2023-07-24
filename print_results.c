#include "simple_shell.h"
/**
 * print_result - prints all natural numbers
 * @n: parameter to print
 * Return: Always 0
 */
void print_result(int n)
{
	unsigned int i, cont = 1;
	char c;
	unsigned int var1, num, var2, var3 = 1;

	var2 = n;
	num = var2;
	while (num > 9)
	{
		num = num / 10;
		cont++;
		var3 = var3 * 10;
	}
	for (i = 1; i <= cont; i++)
	{
		var1 = var2 / var3;
		var2 = var2 % var3;
		var3 = var3 / 10;
		c = '0' + var1;
		write(STDERR_FILENO, &c, 1);
	}
}
