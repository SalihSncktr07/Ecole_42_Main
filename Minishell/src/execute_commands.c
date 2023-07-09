/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:42:13 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/06 21:51:42 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	restore_fd_and_clear_commands(char **commands)
{
	g_shell->file_error_found = 0;
	dup2(g_shell->dup_fd[0], STDIN_FILENO);
	close(g_shell->dup_fd[0]);
	dup2(g_shell->dup_fd[1], STDOUT_FILENO);
	close(g_shell->dup_fd[1]);
	free(commands);
}

static void	execute_commands_selector(char **commands)
{
	if (commands == NULL || commands[0] == NULL)
	{
		unlink("bin/.heredoc_temp");
		return ;
	}
	if (ft_strcmp("echo", commands[0]) == 0)
		execute_echo(commands);
	else if (ft_strcmp("cd", commands[0]) == 0)
		execute_cd(commands);
	else if (ft_strcmp("pwd", commands[0]) == 0 && commands[1] == NULL)
		execute_pwd_without_options();
	else if (ft_strcmp("export", commands[0]) == 0)
		execute_export(commands);
	else if (ft_strcmp("unset", commands[0]) == 0)
		execute_unset(commands);
	else if (ft_strcmp("env", commands[0]) == 0 && commands[1] == NULL)
		execute_env_without_options();
	else
		execute_non_builtin_commands(commands);
}

static void	execute_with_pipe(t_token *before_pipe, t_token *pipe_token,
	int *pipe_fd, int *heredoc_count)
{
	char	**commands_before_pipe;

	if (redirect_file_is_wrong(before_pipe))
	{
		g_shell->exit_status = 2;
		return ;
	}
	g_shell->dup_fd[0] = dup(STDIN_FILENO);
	g_shell->dup_fd[1] = dup(STDOUT_FILENO);
	if (heredoc_no_problem(before_pipe, pipe_fd))
		create_pipe(pipe_token, pipe_fd);
	execute_redirect_and_heredoc(before_pipe, heredoc_count);
	commands_before_pipe = get_commands_before_pipe(before_pipe);
	if (g_shell->file_error_found == 0)
		execute_commands_selector(commands_before_pipe);
	restore_fd_and_clear_commands(commands_before_pipe);
}

void	execute_commands(t_token *token)
{
	t_token	*temp_token;
	int		pipe_fd;
	int		heredoc_count;

	heredoc_count = 0;
	pipe_fd = 0;
	temp_token = token;
	while (temp_token != NULL)
	{
		if (temp_token->type == PIPE_TYPE)
		{
			execute_with_pipe(token, temp_token, &pipe_fd, &heredoc_count);
			if (temp_token->next == NULL)
			{
				last_pipe_handler();
				return ;
			}
			token = temp_token->next;
		}
		temp_token = temp_token->next;
	}
	if (temp_token == NULL)
		execute_with_pipe(token, temp_token, &pipe_fd, &heredoc_count);
	if (pipe_fd != 0)
		close(pipe_fd);
}
