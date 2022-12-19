/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:52:05 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:14:52 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Dosya tanıtıcısına  string çıktısı alır, ardından
 * yeni bir satır gelir */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
		write(fd, "\n", 1);
	}
}
/*
int main()
{
	ft_putendl_fd("bihter",1);
}*/
