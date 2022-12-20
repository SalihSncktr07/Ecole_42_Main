/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:39:56 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:39:56 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Dosya tanıtıcısına bir sayı çıktısı alır */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = (unsigned int)n * -1;
	}
	else
		n2 = (unsigned int)n;
	if (n2 >= 10)
		ft_putnbr_fd(n2 / 10, fd);
	ft_putchar_fd((char)(n2 % 10 + 48), fd);
}
/*
int main()
{
	ft_putnbr_fd(-2345, 1);
}*/
