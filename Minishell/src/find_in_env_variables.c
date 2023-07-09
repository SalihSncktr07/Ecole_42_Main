/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_env_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:08:32 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/20 14:47:51 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_in_env_variables(char *variable_name)
{
	t_env	*env;
	int		env_name_len;
	int		var_name_len;

	if (variable_name == NULL)
		return (NULL);
	env = g_shell->env;
	var_name_len = ft_strlen(variable_name);
	while (env != NULL)
	{
		env_name_len = ft_strlen(env->name);
		if (ft_strncmp(env->name, variable_name, env_name_len) == 0
			&& (env_name_len == var_name_len))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
