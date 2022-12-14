/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:00:51 by berturk           #+#    #+#             */
/*   Updated: 2022/12/14 14:26:13 by spirnaz          ###   ########.fr       */
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

/* void	f(unsigned int i, char *c)
{
	*c = *c - 2;
}

#include <stdio.h>
int main()
{
	char	str[] = "salih";
	ft_striteri(str, f);
	printf("%s\n", str);
} */
