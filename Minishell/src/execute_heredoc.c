/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:34:22 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/07 00:10:34 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *delimiter)
{
	ft_printf(STDERR_FILENO,
		"\nbash: warning: here-document delimited by end-of-file (wanted `%s')\n",
		delimiter);
}

static void	heredoc_handler_helper(int fd, char **temp_token, char *line)
{
	change_all_env_variable_to_value(temp_token);
	ft_printf(fd, "%s\n", temp_token[0]);
	clear_temp_token(temp_token, line);
}

static void	readable_for_heredoc(char *file_name, t_token *token)
{
	int		fd;
	t_token	*prev_token;

	prev_token = NULL;
	while (token != NULL && token->next != NULL
		&& ft_strncmp(token->next->value, "<<", 2))
	{
		prev_token = token;
		token = token->next;
	}
	if ((prev_token != NULL && ft_strncmp(prev_token->value, "grep", 5) == 0)
		|| ft_strncmp(token->value, "cat", 4) == 0
		|| ft_strncmp(token->value, "head", 5) == 0
		|| ft_strncmp(token->value, "tail", 5) == 0
		|| ft_strncmp(token->value, "sort", 5) == 0)
	{
		fd = open(file_name, O_RDONLY, 0644);
		if (fd == -1)
		{
			ft_printf(STDERR_FILENO, "File can't opened !\n");
			return ;
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

static void	heredoc_handler(char *delimiter, int fd)
{
	char	*line;
	char	**temp_token;

	while (1)
	{
		temp_token = (char **)malloc(sizeof(char *) * 2);
		ft_printf(STDIN_FILENO, "> ");
		line = get_next_line(0);
		temp_token[0] = ft_strdup(line);
		temp_token[1] = NULL;
		if (line == NULL)
		{
			print_error(delimiter);
			clear_temp_token(temp_token, line);
			break ;
		}
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			clear_temp_token(temp_token, line);
			break ;
		}
		heredoc_handler_helper(fd, temp_token, line);
	}
	close(fd);
}

void	execute_heredoc(char *file_name, t_token *token, int *heredoc_count)
{
	int	fd;

	*heredoc_count += 1;
	fd = open("bin/.heredoc_temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_printf(STDERR_FILENO, "File can't opened !\n");
		g_shell->exit_status = 1;
		g_shell->file_error_found = 1;
		return ;
	}
	heredoc_handler(file_name, fd);
	readable_for_heredoc("bin/.heredoc_temp", token);
}
