/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_listen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:38:42 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/06 22:11:54 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_console(void)
{
	ft_printf(STDOUT_FILENO, "\033[2J");
	ft_printf(STDOUT_FILENO, "\033[1;1H");
}

static void	clear_helper(char **line, char **command)
{
	free(*line);
	free(*command);
	*line = NULL;
	*command = NULL;
}

void	command_listen(void)
{
	char	*line;
	char	*command;

	while (1)
	{
		line = readline("minishell$ ");
		if (line == NULL)
			exit(EXIT_SUCCESS);
		command = ft_strtrim(line, " \t");
		if (*line == '\0' || *command == '\0')
		{
			clear_helper(&line, &command);
			continue ;
		}
		if (ft_strncmp(command, "exit", 5) == 0
			|| ft_strncmp(command, "exit ", 5) == 0)
			exit(EXIT_SUCCESS);
		if (ft_strncmp(command, "clear", 6) == 0)
			clear_console();
		else
			command_handler(command);
		add_history(command);
		clear_helper(&line, &command);
	}
}
