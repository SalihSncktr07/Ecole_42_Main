/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 01:42:46 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 01:42:55 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_address;

	dest_address = dest;
	if (dest == src || n == 0)
		return (dest);
	while (0 < n)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
		n--;
	}
	return (dest_address);
}
