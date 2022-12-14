/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:54:45 by berturk           #+#    #+#             */
/*   Updated: 2022/12/14 14:33:05 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Dosya tanıtıcısına  bir string çıktısı alır. */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write (fd, s++, 1);
	}
}
/*
int main()
{
	ft_putstr_fd("asdf",1);
}*/
