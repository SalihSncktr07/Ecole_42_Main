/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:39:34 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:39:34 by spirnaz          ###   ########.fr       */
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
