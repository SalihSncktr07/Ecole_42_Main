/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 01:41:54 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 01:42:03 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*string;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	string = (char *)malloc((s1_length + s2_length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_memcpy(string, s1, s1_length);
	ft_strlcpy(string + s1_length, s2, s2_length + 1);
	return (string);
}
