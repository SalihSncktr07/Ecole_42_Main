/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:05:05 by berturk           #+#    #+#             */
/*   Updated: 2022/12/14 14:21:58 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 'f’ fonksiyonunu ‘s’ stringinin bütün karakterlerine uygular.
 Değiştirlen stringden yeni bir string yaratılır.
 #1. Üzerinde dolaşılacak string değeri.
 #2. Her bir karaktere uyugulanacak fonksiyon.*/
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (str[++i])
		str[i] = (*f)(i, str[i]);
	return (str);
}

/* char	f(unsigned int i, char c)
{
	return (c - 32);
}

#include <stdio.h>
int main ()
{
	printf("%s\n", ft_strmapi("abcdef", f));
}
 */