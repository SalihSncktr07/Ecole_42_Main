/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:05:43 by berturk           #+#    #+#             */
/*   Updated: 2022/12/11 12:23:10 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Birinci yazının ilk n karakteri ikinci yazının ilk n 
karakterine eşitse fonksiyon pozitif bir değere geri 
döner. Birinci yazının ilk n karakteri ikinci yazının 
ilk n karakterinden büyükse fonksiyon pozitif 
bir değere, küçükse negatif bir degere geri döner.
(s1 ve s1 arasında n kadarlık alana bakar ilk farkı
gördüklerinin ascii farkını alır.)
 */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* #include <stdio.h>
int main()
{
	const char *cp1 = "Bilgisayar";
    const char *cp2 = "Bilgileri";
    int ret;

    ret = ft_strncmp(cp1, cp2, 6);
	printf("%d", ret);

   // if(ret < 0) 
	//	printf("cp1 karakter dizisi cp2 karakter dizisinden küçüktür!");
   // else if(ret > 0)
	 //  	printf("cp2 karakter dizisi cp1 karakter dizisinden küçüktür!");
   	//else 
	//	printf("cp1 karakter dizisi cp2 karakter dizisine eşittir!");

    return (0);
} */
