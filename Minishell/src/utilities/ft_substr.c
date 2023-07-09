/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:21:37 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 14:03:22 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*string;
	int		size;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - 1 < start)
		return (ft_strdup(""));
	s = s + start;
	size = ft_strlen(s);
	if (size < len)
		len = size;
	string = (char *)malloc(sizeof(char) * (len + 1));
	ft_strlcpy(string, s, len + 1);
	return (string);
}
