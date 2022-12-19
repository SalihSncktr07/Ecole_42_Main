/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:58:25 by berturk           #+#    #+#             */
/*   Updated: 2022/12/10 16:16:59 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* s1 ile gösterilen dizinin aynısını döndürür. */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*p;

	p = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
/*
#include <stdio.h>
int main()
{
	char	s1[] = "bihter erturk";
	printf("%s\n", ft_strdup(s1));
}
*/
