/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:51:29 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/01 00:51:55 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_print_string(int fd, const char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (*string != '\0')
	{
		ft_print_char(fd, *string);
		string++;
		i++;
	}
	return (i);
}
