/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:28:52 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:09:41 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* str ile gösterilen dizeyi int'a dönüştürür.*/

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while (((*str >= 9 && *str <= 13) || *str == 32) && *str)
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		num = (num * 10) + (*str - 48);
		str++;
		if (num * sign > INT_MAX)
			return (-1);
		else if (num * sign < INT_MIN)
			return (0);
	}
	return (num * sign);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("-123fdsa--22"));

	return (0);
}*/
