#include <unistd.h>

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_putnbr(int nb) {
	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48);
}

int		ft_atoi(const char *str)
{
	int i = 0;
	int n= 1;
	int res = 0;

	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * n);
}

int prime(int num)
{
    int i = 3;

    if (num < 2 || num % 2 == 0)
        return 0;
    if (num == 2)
        return 2;
    while (i < num)
        {
            if (num % i == 0)
                return 0;
            i += 2;
        }
        return i;
        
}

int main(int ac, char **av)
{
    int sum = 0;
    int num = ft_atoi(av[1]);
    
    if (ac == 2)
    {    
        while(num > 2)
            if(prime(num--))
                sum += num + 1;
        sum += 2;
        ft_putnbr(sum);
    }
    else
        write (1, "0", 1);

    write (1, "\n", 1);
    return 0;
}
