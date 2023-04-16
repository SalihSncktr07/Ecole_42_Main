/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:37:20 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:37:20 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Belirtilen türde belirtilrn sayıda bellek miktarı ayırır, bayt değerlerini 0
olarak alır. */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*
#include <stdio.h>
int main()
{
	char *dst;

	dst = (char *)ft_calloc(20,1);
	printf("%s",dst);
	printf("%d\n", *dst);
}
*/
