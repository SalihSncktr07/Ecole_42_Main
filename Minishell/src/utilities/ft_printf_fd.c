/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:40:15 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 14:05:17 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_print_format(int fd, char c, va_list ap)
{
	int	print_length;

	print_length = 0;
	if (c == 'c')
		print_length += ft_print_char(fd, va_arg(ap, int));
	else if (c == 's')
		print_length += ft_print_string(fd, va_arg(ap, char *));
	else if (c == 'p')
		print_length += ft_print_pointer(fd, va_arg(ap, unsigned long));
	else if (c == 'd' || c == 'i')
		print_length += ft_print_integer(fd, va_arg(ap, int));
	else if (c == 'u')
		print_length += ft_print_unsigned_integer(fd, va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		print_length += ft_print_hexadecimal(fd, va_arg(ap, unsigned int), c);
	else if (c == '%')
		print_length += ft_print_char(fd, '%');
	else
	{
		print_length += ft_print_char(fd, '%');
		print_length += ft_print_char(fd, c);
	}
	return (print_length);
}

int	ft_printf(int fd, const char *format, ...)
{
	int		print_length;
	va_list	ap;

	print_length = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			print_length += ft_print_format(fd, *(format + 1), ap);
			format += 2;
		}
		else
		{
			print_length += ft_print_char(fd, *format);
			format++;
		}
	}
	va_end(ap);
	return (print_length);
}
