/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:45:57 by spirnaz           #+#    #+#             */
/*   Updated: 2022/12/20 14:45:57 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 'haystack'dizesinde 'needle' alt dizesinin ilk 
 oluşumunu bulur ve bu konuma işaretçi döndürür (belirtilen
 len kadar alanda needle haystack de varsa needle dan itibaren sona
 kadar veirir yoksa NULL verir.) */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && (size_t)i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)&haystack[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}
/*#include <stdio.h>

int main()
{
    const char    *lstr = "Foo Bar Baz";
    const char    *sstr = "Bar";
    char    *ptr;

    prt = ft_strnstr(lstr, sstr, 8);
    printf("%s", ptr);

}*/
