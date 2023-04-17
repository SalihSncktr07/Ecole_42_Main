/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:37:00 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:37:00 by spirnaz          ###   ########.fr       */
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
	char dst[] = "salih";
	printf("Girilen değer: %s",dst);
	printf("Sonuc: %s", ft_bzero(dst,3));
	printf("%s",dst);
}*/
