/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:18:56 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/24 20:13:16 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_without_option(char **strings)
{
	int	i;

	i = 1;
	while (strings[i] != NULL)
	{
		ft_printf(STDOUT_FILENO, "%s", strings[i]);
		if (strings[i + 1] != NULL)
			ft_printf(STDOUT_FILENO, "%c", ' ');
		i++;
	}
	ft_printf(STDOUT_FILENO, "%c", '\n');
	g_shell->exit_status = EXIT_SUCCESS;
}

static void	echo_with_option(char **strings)
{
	int	i;

	i = 2;
	while (strings[i] != NULL)
	{
		ft_printf(STDOUT_FILENO, "%s", strings[i]);
		if (strings[i + 1] != NULL)
			ft_printf(STDOUT_FILENO, "%c", ' ');
		i++;
	}
	g_shell->exit_status = EXIT_SUCCESS;
}

void	execute_echo(char **strings)
{
	if (strings[1] != NULL && ft_strncmp("-n", strings[1], 3) == 0)
	{
		echo_with_option(strings);
	}
	else
	{
		echo_without_option(strings);
	}
}
