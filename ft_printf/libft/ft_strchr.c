/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:37 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:36:37 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* s dizesinde karakterin geçtiği yerden itibaren alır
(c yi s de bulduğu yerden itibaren alır)*/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
}

/* #include <stdio.h>
int main( )
{
    char cdizi[] = "salih";
    char *ret;
    ret = ft_strchr(cdizi, 'i');
    
    printf("Bulunan karakterden itibaren dizi içeriği: %s\n", ret);
    return 0;
} */
