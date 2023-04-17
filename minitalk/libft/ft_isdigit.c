/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:37:59 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:37:59 by spirnaz          ###   ########.fr       */
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
