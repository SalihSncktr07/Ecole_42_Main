#include <unistd.h>

int ft_atoi(char *str)
{
    int res = 0;
    int n = 1;

    if(*str == '-')
    {
        n *= -1;
        str++;
    }
    while(*str)
    {
        res = (res * 10) + (*str - 48);
        str++;
    }
    return res * n;
}

void    ft_putnbr(int n)
{
    char str[] = "0123456789";

    if(n < 0)
    {
        write(1, "-", 1);
        n *= -1;
    }
    if(n > 9)
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
    else if (n <= 9)
        write(1, &str[n % 10], 1);
}

int main(int ac, char **av)
{
    int i = 1;
    int res = 0;
    int num = ft_atoi(av[1]);
    
    if (ac == 2)
    {
        while(i <= 9)
        {
            ft_putnbr(i);
            write(1, " * ", 3);
            ft_putnbr(num);
            write(1, " = ", 3);
            res = num * i;
            ft_putnbr(res);
            res = 0;
            i++;
            write(1, "\n", 1);
        }
    }
    else
        write(1, "\n", 1);
}

// #include <unistd.h>

// int	ft_atoi(char *str)
// {
// 	int result;
// 	int sign;

// 	result = 0;
// 	sign = 1;
// 	while (*str == ' ' || (*str >= 9 && *str <= 13))
// 		str++;
// 	if (*str == '-')
// 		sign = -1;
// 	if (*str == '-' || *str == '+')
// 		str++;
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		result = result * 10 + *str - '0';
// 		str++;
// 	}
// 	return (sign * result);
// }

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	ft_putnbr(int nb)
// {
// 	if (nb == -2147483648)
// 	{
// 		ft_putchar('-');
// 		ft_putchar('2');
// 		nb = (nb % 1000000000 * -1);
// 	}
// 	if (nb < 0)
// 	{
// 		ft_putchar('-');
// 		nb = (nb * -1);
// 	}
// 	if (nb / 10 > 0)
// 		ft_putnbr(nb / 10);
// 	ft_putchar(nb % 10 + '0');
// }

// int	main(int argc, char *argv[])
// {
// 	int	i;
// 	int	nbr;

// 	if (argc != 2)
// 		write(1, "\n", 1);
// 	else
// 	{
// 		i = 1;
// 		nbr = ft_atoi(argv[1]);
// 		while (i <= 9)
// 		{
// 			ft_putnbr(i);
// 			write(1, " x ", 3);
// 			ft_putnbr(nbr);
// 			write(1, " = ", 3);
// 			ft_putnbr(i * nbr);
// 			write(1, "\n", 1);
// 			i += 1;
// 		}
// 	}
// 	return (0);
// }
