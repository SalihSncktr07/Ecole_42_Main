/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:40:39 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:40:39 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*‘f’ fonksiyonun stringin her karakterine uygular.
 Eğer gerekli olursa her karakter adresi ile gönderilmelidir
 #1. Üzerinde dolaşılacak string değeri.
 #2. Her karatere uyugulanacak fonksiyon.*/
#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (*s)
			f(i++, s++);
	}
}

/*void	f(unsigned int i, char *c)
{
	*c = *c - 2;
}

#include <stdio.h>
int main()
{
	char	str[] = "salih";
	ft_striteri(str, f);
	printf("%s\n", str);
}*/
