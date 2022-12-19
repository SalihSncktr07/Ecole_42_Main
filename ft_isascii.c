/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:36:34 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:12:20 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ASCII karakter kümesine uyup uymadığını kontrol eder*/
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_isascii(48));
	return (0);
}*/
