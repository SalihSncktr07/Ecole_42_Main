/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 07:47:22 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 14:28:40 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	word_counter(char *command)
{
	int	count;
	int	word_found;

	count = pipe_redirection_count(command);
	word_found = 0;
	while (*command != '\0')
	{
		if (ft_strchr("\"\'", *command))
		{
			count++;
			command = skip_quotes(command);
			word_found = 0;
			if (*command == '\0')
				return (count);
		}
		if (word_found == 0 && !ft_strchr("|<> \"\'", *command))
		{
			count++;
			word_found = 1;
		}
		else if (word_found == 1 && ft_strchr("|<> ", *command))
			word_found = 0;
		command++;
	}
	return (count);
}

char	**command_parser(char *command)
{
	char	**commands;
	int		index;

	commands = (char **)ft_calloc(word_counter(command) + 1, sizeof(char *));
	index = 0;
	while (*command != '\0')
	{
		commands[index] = command_separator(command);
		command = command + ft_strlen(commands[index]);
		while (*command == ' ')
			command++;
		index++;
	}
	commands[index] = NULL;
	return (commands);
}
