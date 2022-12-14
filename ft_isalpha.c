/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:35:52 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:12:02 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Büyük veya küçük alfabetik karakter kontrolü yapar */
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha(97));

	return (0);
}*/
