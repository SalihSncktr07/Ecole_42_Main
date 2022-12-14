/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:37:52 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:12:33 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Yazdırılabilir karakter olup olmadığına bakar*/
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}	
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_isprint(48));
	return (0);
}*/
