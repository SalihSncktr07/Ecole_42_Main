/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:48:13 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/01 00:48:53 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_hexadecimal_len(unsigned int number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 16;
		len++;
	}
	return (len);
}

int	ft_print_hexadecimal(int fd, unsigned int number, char token)
{
	int	len;

	len = ft_hexadecimal_len(number);
	if (number <= 9)
		ft_print_char(fd, number + '0');
	else if (number < 16)
	{
		if (token == 'x')
			ft_print_char(fd, (number - 10) + 'a');
		else
			ft_print_char(fd, (number - 10) + 'A');
	}
	else
	{
		ft_print_hexadecimal(fd, number / 16, token);
		ft_print_hexadecimal(fd, number % 16, token);
	}
	return (len);
}
