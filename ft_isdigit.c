/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:37:20 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:12:27 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Rakam mı değil mi kontrol eder */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_isdigit('a'));

	return (0);
}*/
