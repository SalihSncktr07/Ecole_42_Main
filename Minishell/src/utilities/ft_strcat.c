/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:29:21 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 14:04:24 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strcat(char *dst, const char *src)
{
	int	dst_len;

	dst_len = ft_strlen(dst);
	ft_strcpy(dst + dst_len, src);
	return (dst);
}

void	ft_strcat_free(char *dst, char *src)
{
	if (src == NULL)
		return ;
	ft_strcpy(dst + ft_strlen(dst), src);
	free(src);
}
