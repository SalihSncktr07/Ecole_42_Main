/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:49:23 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/01 00:49:52 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_integer_len(long number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number != 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

int	ft_print_integer(int fd, int number)
{
	long	temp;
	int		len;

	temp = number;
	len = ft_integer_len(temp);
	if (temp < 0)
	{
		ft_print_char(fd, '-');
		temp = -temp;
	}
	if (temp < 10)
		ft_print_char(fd, temp + '0');
	else
	{
		ft_print_integer(fd, temp / 10);
		ft_print_integer(fd, temp % 10);
	}
	return (len);
}
