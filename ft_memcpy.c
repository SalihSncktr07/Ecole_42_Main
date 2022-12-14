/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:43:04 by berturk           #+#    #+#             */
/*   Updated: 2022/12/11 12:21:25 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
src param. ile gösterilen bellek bölgesindeki  karakterleri,
n değeri kadar uzunlukta dest
parametresindeki bellek bölgesine kopyalar.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!src && !dest)
		return (0);
	if (!n || src == dest)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

/* #include <stdio.h>
int main()
{
    char dst[] = "salih";
    char src[] = "pirnaz";
    printf("%s", ft_memcpy(dst, src, 2));
    return (0);
} */