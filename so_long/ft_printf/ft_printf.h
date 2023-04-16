/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:55:41 by spirnaz           #+#    #+#             */
/*   Updated: 2023/04/16 18:55:43 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

void	ft_putchar(int x, int *index);
void	ft_putstr(char *neww, int *byte);
void	ft_putnumber(int x, int *byte);
void	ft_putunsigned(unsigned int x, int *byte);
void	ft_puthex(unsigned int n, int type, int *byte);
void	ft_putaddress(unsigned long long n, int *byte);

int		ft_printf(const	char *str, ...);

#endif
