#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	number;

	if (argc == 2)
	{
		i = 1;
		number = atoi(argv[1]);
		if (number == 1)
			printf("1");
		while (number >= ++i)
		{
			if (number % i == 0)
			{
				printf("%d", i);
				if (number == i)
					break ;
				printf("*");
				number /= i;
				i = 1;
			}
		}
	}
	printf("\n");
	return (0);
}

/*
int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;

	argv++;
	int result = 1;
	int i = 1;
	// printf("%s\n",*argv);
	int arg = atoi(*argv);
	// printf("%d\n",arg);
	if (arg == 1)
		printf("1");
	while (arg >= i)
	{
		i++;
		if (arg % i == 0)
		{
			printf("%d", i);
			if(arg == i)
				break;
			printf("*");
			arg /= i;
			i = 1;
		}
	}
}
*/


/* #include <stdio.h>
#include <stdlib.h>

void	fprime(int nb)
{
	int i;

	i = 2;
	if (nb == 1)
	{
		printf("1");
		return ;
	}
	while (nb >= i)
	{
		if (nb % i == 0)
		{
			printf("%d", i);
			if (nb != i)
				printf("*");
			nb /= i;
			i--;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);
}
 */