/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:41:10 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 18:47:42 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* src dizesini n. değerden itibaren dst nin sonuna ekler*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dsize;

	dsize = 0;
	while (dest[dsize] && dsize < size)
		dsize++;
	i = dsize;
	while (src[dsize - i] && dsize + 1 < size)
	{
		dest[dsize] = src[dsize - i];
		dsize++;
	}
	if (i < size)
		dest[dsize] = '\0';
	return (i + ft_strlen(src));
}

/* 
#include <stdio.h>
int main()
{
    char a[] = "salih";
    char b[] = " pirnaz";
    printf("%zu", ft_strlcat(a,b,3));
    return (0);
} */
