/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:54:47 by spirnaz           #+#    #+#             */
/*   Updated: 2023/04/16 18:54:48 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putstr(char *neww, int *byte)
{
	int	i;

	i = 0;
	if (!neww)
	{
		ft_putstr("(null)", byte);
		return ;
	}
	while (neww[i])
		ft_putchar(neww[i++], byte);
}

void	ft_putnumber(int x, int *byte)
{
	if (x < 0)
	{
		if (x == -2147483648)
		{
			ft_putstr("-2147483648", byte);
			return ;
		}
		ft_putchar('-', byte);
		x = -x;
	}
	if (x >= 10)
		ft_putnumber(x / 10, byte);
	ft_putchar((x % 10) + 48, byte);
}

void	ft_putunsigned(unsigned int x, int *byte)
{
	if (x >= 10)
		ft_putnumber(x / 10, byte);
	ft_putchar((x % 10) + 48, byte);
}

void	ft_puthex(unsigned int n, int type, int *byte)
{
	char	*a;

	if (type == 'X')
		a = ft_strdup("0123456789ABCDEF");
	else
		a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_puthex(n / 16, type, byte);
		ft_puthex(n % 16, type, byte);
	}
	else
		ft_putchar(a[n], byte);
	free(a);
}

void	ft_putaddress(unsigned long long n, int *byte)
{
	char	*a;

	a = ft_strdup("0123456789abcdef");
	if (n >= 16)
	{
		ft_putaddress(n / 16, byte);
		ft_putaddress(n % 16, byte);
	}
	else
		ft_putchar(a[n], byte);
	free(a);
}
