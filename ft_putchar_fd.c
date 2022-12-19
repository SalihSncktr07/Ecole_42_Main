/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:50:23 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:14:43 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Bir dosya tanıtıcısına  bir karakter çıktısı alır*/
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int main()
{
	char c = 'A';
	ft_putchar_fd(c, 1);
}*/
