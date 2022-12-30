/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:50:41 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:50:41 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Büyük harfi küçük harfe dönüştürür. */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
 * #include <stdio.h>
#include <ctype.h>
 * int main() {
    char c;

    c = 'm';
    printf("%c -> %c", c, ft_tolower(c));

    c = 'D';
    printf("\n%c -> %c", c, ft_tolower(c));

    c = '9';
    printf("\n%c -> %c", c, ft_tolower(c));
    return 0;
	}*/
