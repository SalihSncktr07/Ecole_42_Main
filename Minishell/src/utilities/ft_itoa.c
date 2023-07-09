/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:51:56 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 13:55:38 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_array(char *str, unsigned int count, long int val)
{
	while (count > 0)
	{
		str[val--] = '0' + (count % 10);
		count = count / 10;
	}
	return (str);
}

static long int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		val;
	unsigned int	count;
	int				sign;

	sign = 1;
	val = ft_len(n);
	str = (char *)malloc(sizeof(char) * (val + 1));
	if (!str)
		return (NULL);
	str[val--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		count = n * -1;
		str[0] = '-';
	}
	else
		count = n;
	str = ft_array(str, count, val);
	return (str);
}
