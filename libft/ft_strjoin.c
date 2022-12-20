/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:41:00 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:41:00 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Malloc ile hafızdan yer ayırdı, çıktı olarak 
// s1 ve s2 stringlerinin birleşimini verdi

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*newstr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (0);
	while (*s1)
		newstr[i++] = *s1++;
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}
/*
#include <stdio.h>
int main()
{
	char i[] = "salih";
	char e[] = "pırnaz";

	printf("%s\n", ft_strjoin(i,e));
}*/
