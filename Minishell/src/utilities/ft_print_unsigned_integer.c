/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_integer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:52:33 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/01 00:52:58 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_unsigned_integer_len(unsigned int number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

int	ft_print_unsigned_integer(int fd, unsigned int number)
{
	int	len;

	len = ft_unsigned_integer_len(number);
	if (number < 10)
		ft_print_char(fd, number + '0');
	else
	{
		ft_print_integer(fd, number / 10);
		ft_print_integer(fd, number % 10);
	}
	return (len);
}
