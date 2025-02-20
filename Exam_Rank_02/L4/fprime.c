/*Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int isPrime(int num)
{
	int i;

	if (num < 2)
		return (0);
	if (num < 4)
		return(1);
	if (num % 2 == 0 || num % 3 == 0)
		return(0);
	i = 5;
	while (i*i < num)
	{
		if (num % i == 0)
			return(0);
		i++;
	}
	return(1);
}

int main(int argn, char **argv)
{
	int i;
	int num;

	if (argn == 2)
	{
		num = atoi(argv[1]);
		if (num == '1')
			printf("1");
		while (num > 1)
		{
			i = 2;
			while (i <= num)
			{
				if (isPrime(i) == 1 && num % i == 0)
				{
					if (num != i)
						printf("%d*", i);
					else
						printf("%d", i);
					break ;
				}					
				i++;			
			}
			num = num / i;
		}
		printf("\n");
	}
	else
		printf("\n");
}
