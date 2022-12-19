/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:35:02 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:11:48 by spirnaz          ###   ########.fr       */
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
