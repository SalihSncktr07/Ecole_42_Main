/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:39:14 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:39:14 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//src'dekileri n değeri kadar uzunlukta dest'e taşır
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!n || src == dest)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest < src)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

/* #include <stdio.h>
int main()
{
    char dst[] = "salih";
    char src[] = "pirnaz";
    printf("%s", ft_memmove(dst, src, 2));
    // printf("%s\n", src);
    return (0);
}  */
