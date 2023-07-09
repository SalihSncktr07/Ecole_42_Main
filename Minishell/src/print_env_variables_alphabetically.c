/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_variables_alphabetically.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:17:20 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/05 21:47:55 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_variables_count(void)
{
	int		count;
	t_env	*temp_env;

	count = 0;
	temp_env = g_shell->env;
	while (temp_env != NULL)
	{
		count++;
		temp_env = temp_env->next;
	}
	return (count);
}

static t_env	**get_copy_env_list(int env_count)
{
	int		i;
	t_env	**env_list;
	t_env	*temp_env;
	t_env	*copy_env;

	i = 0;
	env_list = (t_env **)malloc(sizeof(t_env *) * (env_count + 1));
	temp_env = g_shell->env;
	copy_env = NULL;
	while (temp_env != NULL)
	{
		copy_env = malloc(sizeof(t_env));
		copy_env->name = ft_strdup(temp_env->name);
		copy_env->value = ft_strdup(temp_env->value);
		copy_env->flag = 1;
		copy_env->next = NULL;
		env_list[i] = copy_env;
		temp_env = temp_env->next;
		i++;
	}
	env_list[i] = NULL;
	return (env_list);
}

static void	sort_env_list(t_env **env_list, int env_count)
{
	int		len;
	int		i;
	int		j;
	t_env	*temp;

	len = env_count;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(env_list[i]->name, env_list[j]->name) > 0)
			{
				temp = env_list[i];
				env_list[i] = env_list[j];
				env_list[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	print_env_variables_alphabetically(void)
{
	t_env	**env_list;
	int		env_count;
	int		i;

	env_count = get_env_variables_count();
	if (env_count == 0)
		return ;
	env_list = get_copy_env_list(env_count);
	sort_env_list(env_list, env_count);
	i = 0;
	while (i < env_count)
	{
		ft_printf(STDOUT_FILENO,
			"declare -x %s=\"%s\"\n", env_list[i]->name, env_list[i]->value);
		i++;
	}
	clear_env_list(env_list, env_count);
}
