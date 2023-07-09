/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_all_env_variable_to_value.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:35:13 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/05 13:38:41 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_tilde(char **command)
{
	char	*value;

	value = get_env_value("HOME");
	free(*command);
	*command = value;
}

static void	handle_tilde_with_slash(char **command)
{
	char	*home;
	char	*value;

	home = get_env_value("HOME");
	value = ft_strjoin(home, &command[0][1]);
	free(home);
	free(*command);
	*command = value;
}

static int	command_contains_dollar_and_quote(char *command)
{
	if (ft_strchr(command, '$')
		&& (ft_strchr(command, '\"') || ft_strchr(command, '\'')))
	{
		return (1);
	}
	return (0);
}

static void	replace_env_variable_value(char **command)
{
	char	*temp_command;

	temp_command = get_env_variable_value(*command);
	free(*command);
	*command = temp_command;
}

void	change_all_env_variable_to_value(char **commands)
{
	int		i;

	i = 0;
	while (commands[i] != NULL)
	{
		if (ft_strncmp("~", commands[i], 2) == 0)
		{
			handle_tilde(&commands[i]);
		}
		else if (commands[i][0] == '~' && commands[i][1] == '/')
		{
			handle_tilde_with_slash(&commands[i]);
		}
		else if (command_contains_dollar_and_quote(commands[i]))
		{
			if (commands[i][0] != '\"')
				return ;
			replace_env_variable_value(&commands[i]);
		}
		else if (ft_strchr(commands[i], '$') || ft_strchr(commands[i], '?'))
		{
			replace_env_variable_value(&commands[i]);
		}
		i++;
	}
}
