/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:19:40 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 14:02:43 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_strlen_trimmed(char *string, char *set)
{
	int		len;
	char	*trimmed_string;

	if (string == NULL || set == NULL)
		return (0);
	trimmed_string = ft_strtrim(string, set);
	len = ft_strlen(trimmed_string);
	free(trimmed_string);
	return (len);
}

int	ft_strlen_free(char *string)
{
	int	len;

	if (string == NULL)
		return (0);
	len = ft_strlen(string);
	free(string);
	return (len);
}
