/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:38:06 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:38:06 by spirnaz          ###   ########.fr       */
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
