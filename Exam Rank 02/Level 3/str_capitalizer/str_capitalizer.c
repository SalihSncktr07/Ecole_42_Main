#include <unistd.h>

void capitalize(char *str)
{
int i = 0;

		while (str[i])
		{
			if(str[i - 1] == '\t' || str[i - 1] == ' ' || str[i - 1] == '\0')
			{	if(str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
			write(1, &str[i++], 1);
		}
		write (1, "\n", 1);
}

int main(int ac, char **av)
{
	int i = 1;

	if (ac < 2)
		write(1, "\n", 1);

	while(i < ac)
		capitalize(av[i++]);
}

/*
void	str_capitalizer(char *str)
{
	int i = 0;

	if (str[i] >= 'a' && 'z' >= str[i])
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[++i])
	{
		if (str[i] >= 'A' && 'Z' >= str[i])
			str[i] += 32;
		if ((str[i] >= 'a' && 'z' >= str[i]) && (str[i - 1] == ' ' || \
		str[i - 1] == '\t'))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int main(int argc, char *argv[])
{
	int i;

	if (argc < 2)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i += 1;
		}
	}
	return (0);
}
*/