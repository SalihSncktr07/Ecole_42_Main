/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:37:29 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:37:29 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Alfabetik karakter mi ya da rakam mı  kontrol eder */
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_isalnum(48));

	return (0);
}*/
