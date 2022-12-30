/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:44:18 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:44:18 by spirnaz          ###   ########.fr       */
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
	size_t	s_strlen;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	s_strlen = ft_strlen(s);
	str = malloc(sizeof(char) * (s_strlen + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		str[i] = f(i, (char)*s);
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	f(unsigned int i, char c)
{
	return (c - 32);
}*/
/*#include <stdio.h>
int main ()
{
	printf("%s\n", ft_strmapi("abcdef", f));
}*/
