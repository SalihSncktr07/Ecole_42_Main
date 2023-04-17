/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:46:36 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:46:36 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*strchr'ye göre farkı sondan gelerek istenilen c karakterini
bulması */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (!ft_strchr(s, (char)c))
		return (0);
	while (*s)
		s++;
	while (*s != (char)c)
		s--;
	return ((char *)s);
}
/* #include <stdio.h>
  int main( void )
{
    const char cdizi[] = "Bilgisayar";
    char *ret;

    ret = ft_strrchr(cdizi, 's');

    printf("Bulunan karakterden itibaren dizi içeriği: %s", ret);

    return 0;
}*/
