/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_or_update_env_variable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:52:55 by spirnaz           #+#    #+#             */
/*   Updated: 2023/07/09 13:52:58 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*get_last_env(t_env *env)
{
	if (env == NULL)
		return (NULL);
	while (env->next != NULL)
		env = env->next;
	return (env);
}

void	add_env_to_list(t_env **env, t_env *new_env)
{
	if (new_env == NULL)
		return ;
	if (*env == NULL)
	{
		*env = new_env;
		return ;
	}
	get_last_env(*env)->next = new_env;
}

void	add_or_update_env_variable(char *name, char *value)
{
	t_env	*env;
	t_env	*new_env;

	env = g_shell->env;
	while (env != NULL)
	{
		if (ft_strncmp(env->name, name, ft_strlen(name)) == 0
			&& ft_strlen(env->name) == ft_strlen(name))
		{
			free(env->value);
			env->value = ft_strdup(value);
			return ;
		}
		env = env->next;
	}
	new_env = malloc(sizeof(t_env));
	new_env->name = ft_strdup(name);
	new_env->value = ft_strdup(value);
	new_env->flag = 2;
	new_env->next = NULL;
	add_env_to_list(&g_shell->env, new_env);
}
