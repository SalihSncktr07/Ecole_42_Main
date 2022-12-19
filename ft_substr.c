/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:09:14 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:20:02 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*s dizesinden bir alt dize döndürür.
 Malloc fonksiyonu kullanılarak memoryde hafıza ayırılır ve
 belirtilen substringi döner. Substring başlangıç indisinden
 başlar ve maksimum boyutuna kadar devam eder
 #1. Substringin oluşturalacağı string.
 #2. Substringin ana string içerisindeki başlangıç indisi.
 #3. Substringin maksimum uzunluğu */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char	i[] = "bihter";
	printf("%s\n", ft_substr(i, 2, 4));
}*/
