/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:38:31 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:12:37 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Sayıyı stringe dönüştürür, Malloc ile yer ayrılır */
#include "libft.h"

static size_t	len_digits(int n)
{
	size_t	count;

	count = 0;
	if (n < 0 || n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		slen;
	const char	*digits;

	digits = "0123456789";
	slen = len_digits(n);
	str = (char *)malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	str[slen] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[--slen] = digits[n % 10];
		else
			str[--slen] = digits[n % 10 * (-1)];
		n /= 10;
	}
	return (str);
}
/*
#include <stdio.h>
int main()
{	
	printf("%s", ft_itoa(123));
	printf("\n%s", ft_itoa(-234567));
	printf("\n%s", ft_itoa(0));
	return (0);
}*/
