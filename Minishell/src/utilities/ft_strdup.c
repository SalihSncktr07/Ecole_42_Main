/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:21:01 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 14:01:10 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(const char *s)
{
	char	*copy_string;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	copy_string = (char *)malloc(s_len + 1);
	if (copy_string == NULL)
		return (NULL);
	ft_strlcpy(copy_string, s, s_len + 1);
	return (copy_string);
}
