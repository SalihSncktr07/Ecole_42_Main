/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:03:44 by berturk           #+#    #+#             */
/*   Updated: 2022/12/11 12:22:40 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* src'den dst'ye dstsize kadar kopyalar kalanını null yapar. */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < (dstsize -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/* 
#include <stdio.h>
int main()
{
	char src[] = "salih";
	char dst[] = "pirnaz";

	printf ("%zu\n", ft_strlcpy(src, dst, 3));
    printf("%s\n", src);

} */
