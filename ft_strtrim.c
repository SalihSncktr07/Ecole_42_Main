/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:08:30 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:19:59 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 'set' içinde belirtilen karakterlerin başından ve sonundan
kaldırıldığı bir s1 kopyasını döndürür.
Malloc kullanrak hafızada yer ayırılır ardından ana stringde
kırpılmak istenilen karakterlerin hepsi kırpılır sonuç
olarak elde edilen yeni string döndürülür.
 #1. Kırpılacak string.
 #2. Kırpılması istenen karakterler. */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
/*
#include <stdio.h>
int main()
{
    char i[] = "eeebihter111";
    char e[] = "e1";
    printf("%s\n",ft_strtrim(i,e));
}*/
