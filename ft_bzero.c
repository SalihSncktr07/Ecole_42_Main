/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:32:35 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:11:38 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*bzero() işlevi, s dizesine sıfırlanmış n bayt yazar. 
 * n sıfır ise, bzero() hiçbir şey yapmaz.*/
#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*(ptr++) = '\0';
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
int main ()
{
	char dst[] = "bihter";
	printf("Girilen değer : %s, \nSonuç : ",dst);
	ft_bzero(dst,3);
	printf("%s",dst);
}*/
