/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:44:05 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:44:05 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Dizinin  uzunluğunu buldurur */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main( void )
{
    const char *str = "salih";
    int ret;

    ret = ft_strlen(str);

    printf("%s karakter dizisinin uzunluğu: %d\n", str, ret);

    return 0;
}*/
