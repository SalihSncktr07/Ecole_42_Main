/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:46:43 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/07 04:13:35 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*g_shell;

static void	init_global_shell(void)
{
	g_shell = (t_shell *)malloc(sizeof(t_shell));
	g_shell->env = NULL;
	g_shell->exit_status = 0;
	g_shell->file_error_found = 0;
	g_shell->heredoc_count = 0;
	g_shell->token_count = 0;
}

static void	init_env_variables(char **envp)
{
	t_env	*env;

	while (*envp != NULL)
	{
		env = malloc(sizeof(t_env));
		env->name = ft_substr(*envp, 0, ft_strchr(*envp, '=') - *envp);
		env->value = ft_strdup(getenv(env->name));
		env->flag = 1;
		env->next = NULL;
		add_env_to_list(&g_shell->env, env);
		envp++;
	}
}

static void	sigint_handler(int signal_no)
{
	(void)signal_no;
	if (access("bin/.heredoc_temp", F_OK) == 0)
	{
		ft_printf(STDOUT_FILENO, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		ft_printf(STDIN_FILENO, "> ");
	}
	else
	{
		ft_printf(STDOUT_FILENO, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	g_shell->exit_status = 130;
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf(STDERR_FILENO, "Error: too many arguments.\n");
		return (0);
	}
	unlink("bin/.heredoc_temp");
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	init_global_shell();
	init_env_variables(envp);
	command_listen();
}
