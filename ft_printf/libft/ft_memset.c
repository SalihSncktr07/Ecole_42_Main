/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:39:25 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:39:25 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* memset() işlevi, c değerinde (işaretsiz bir karaktere dönüştürülmüş)
len baytlarını b dizesine yazar. (b dizisini len kadar c ye çevirir)*/
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len--)
		*ptr++ = c;
	return (b);
}

/*
#include <stdio.h>
int main()
{

	char cdizi[] = "Bilgisayar";

    printf("cdizi bellek içeriği: %s\n", cdizi);

    //ft_memset(cdizi, 'x', 5);
	ft_memset(cdizi, 48, 5);

    printf("ft_memset sonrası bellek içeriği: %s", cdizi);

    return 0;
}
*/
