/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd_pwd_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 01:17:16 by spirnaz            #+#    #+#             */
/*   Updated: 2023/06/21 14:16:05 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_old_pwd(char *old_pwd, char *new_pwd)
{
	t_env	*env;

	env = g_shell->env;
	if (old_pwd == NULL)
	{
		add_or_update_env_variable("OLDPWD", new_pwd);
		return ;
	}
	while (env != NULL)
	{
		if (ft_strncmp(env->name, "OLDPWD", 6) == 0)
		{
			free(env->value);
			env->value = ft_strdup(new_pwd);
			return ;
		}
		env = env->next;
	}
}

void	execute_cd(char **strings)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (strings[1] == NULL)
	{
		update_old_pwd(find_in_env_variables("OLDPWD"), pwd);
		chdir(find_in_env_variables("HOME"));
	}
	else if (ft_strncmp("-", strings[1], 2) == 0)
	{
		if (chdir(find_in_env_variables("OLDPWD")) == -1)
			ft_printf(STDERR_FILENO, "%s", "cd: OLDPWD not set\n");
		update_old_pwd(find_in_env_variables("OLDPWD"), pwd);
	}
	else
	{
		update_old_pwd(find_in_env_variables("OLDPWD"), pwd);
		if (chdir(strings[1]) == -1)
		{
			ft_printf(STDERR_FILENO,
				"cd: %s: No such file or directory\n", strings[1]);
			g_shell->exit_status = 1;
		}
	}
	free(pwd);
}

void	execute_pwd_without_options(void)
{
	char	*current_directory;

	current_directory = getcwd(NULL, 0);
	if (current_directory == NULL)
	{
		perror("Error getcwd failed");
		g_shell->exit_status = 126;
		return ;
	}
	ft_printf(STDOUT_FILENO, "%s\n", current_directory);
	free(current_directory);
	g_shell->exit_status = EXIT_SUCCESS;
}

void	execute_env_without_options(void)
{
	t_env	*env;

	env = g_shell->env;
	while (env != NULL && env->value != NULL)
	{
		if (ft_printf(STDOUT_FILENO, "%s=%s\n", env->name, env->value) == 0)
		{
			g_shell->exit_status = EXIT_FAILURE;
			return ;
		}
		env = env->next;
	}
	g_shell->exit_status = EXIT_SUCCESS;
}
