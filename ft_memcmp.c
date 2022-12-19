/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:42:07 by berturk           #+#    #+#             */
/*   Updated: 2022/12/11 12:21:09 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Belirtilen alan kadar karakteri karşılaştırarak
hangisinin büyük olduğunu bulıur.*/

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)ptr1;
	s2 = (unsigned char *)ptr2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
int main () {
   char s1[] = "salih pırnaz";
   char s2[] = "saliH pırnaz";
   int ret;
 
   ret = ft_memcmp(s1, s2, 5);
   //ret = ft_memcmp(s1, s2, 4); //Eşit olur
   if(ret > 0) {
      printf("s2,  s1'den daha küçük.");
   } else if(ret < 0) {
       printf("s1, s2'den daha küçükk.");
   } else
      printf("s1, s2'ye eşit.");
   return (0);
} */
