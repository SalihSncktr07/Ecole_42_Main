/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:38:42 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:38:42 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Aranan harfe kadar tarar bulduktan sonra ondan itibaren
geri kalanı stringde yazdırır.
 */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}

/* 
#include <stdio.h>
int main()
{
	char a[] = "salih";
	printf("%s", ft_memchr(a, 'i' ,4));
	return (0);
}
*/