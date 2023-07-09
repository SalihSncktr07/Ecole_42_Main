/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export_unset.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:53:56 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/05 12:46:59 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_unset(char **strings)
{
	int		i;
	char	*variable_value;

	i = 1;
	while (strings[i] != NULL)
	{
		variable_value = get_env_value(strings[i]);
		if (variable_value != NULL)
		{
			delete_env_variable(strings[i]);
			free(variable_value);
		}
		i++;
	}
	g_shell->exit_status = 0;
}

void	execute_export(char **strings)
{
	char	**variable;
	int		i;

	if (strings[1] == NULL)
		print_env_variables_alphabetically();
	else
	{
		i = 1;
		while (strings[i] != NULL)
		{
			variable = ft_split(strings[i], '=');
			if (ft_isdigit(variable[0][0]))
			{
				ft_printf(STDERR_FILENO,
					"export: `%s=%s': not a valid identifier\n",
					variable[0], variable[1]);
			}
			else
			{
				add_or_update_env_variable(variable[0], variable[1]);
			}
			clear_string_list(variable);
			i++;
		}
	}
}
