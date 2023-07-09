/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:18:29 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 14:30:52 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_redirection_count(char *command)
{
	int	count;

	count = 0;
	while (*command != '\0')
	{
		if (*command == '\'' || *command == '\"')
			command = skip_quotes(command);
		if (ft_strchr("<>", *command) && *(command + 1) == *command)
		{
			count++;
			command++;
		}
		else if (ft_strchr("|><", *command))
			count++;
		command++;
	}
	return (count);
}

char	*skip_quotes(char *str)
{
	char	quote;

	if (*str == '\'' || *str == '\"')
	{
		quote = *str;
		str++;
		while (*str != '\0' && *str != quote)
			str++;
	}
	return (str);
}

char	*skip_pipe_redirection(char *str)
{
	while (*str != '\0' && ft_strchr("|<>", *str))
		str++;
	return (str);
}

int	word_len(char *command)
{
	int		len;
	char	*temp_command;

	len = 0;
	if (ft_strchr("\"\'", *command))
	{
		temp_command = skip_quotes(command);
		len = temp_command - command + 1;
	}
	else if (ft_strchr("|<>", *command))
	{
		temp_command = skip_pipe_redirection(command);
		len = temp_command - command;
	}
	else
	{
		temp_command = command;
		while (*temp_command != '\0' && !ft_strchr("|<> \"\'", *temp_command))
			temp_command++;
		len = temp_command - command;
	}
	return (len);
}
