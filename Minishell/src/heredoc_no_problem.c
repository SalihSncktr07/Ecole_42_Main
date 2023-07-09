/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_no_problem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:49:30 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/07 04:15:43 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_heredocs_comamnd(char *command)
{
	if (ft_strncmp(command, "cat", 4) == 0
		|| ft_strncmp(command, "head", 5) == 0
		|| ft_strncmp(command, "tail", 5) == 0
		|| ft_strncmp(command, "sort", 5) == 0)
	{
		return (1);
	}
	return (0);
}

static int	is_heredocs_grep(t_token *token)
{
	if (g_shell->heredoc_count > 0 && ft_strncmp(token->value, "grep", 5) == 0
		&& token->next->next != NULL
		&& ft_strncmp(token->next->next->value, "<<", 2) == 0)
	{
		return (1);
	}
	return (0);
}

int	heredoc_no_problem(t_token *token, int *pipe_fd)
{
	while (token != NULL && token->next != NULL && token->type != PIPE_TYPE)
	{
		if (is_heredocs_grep(token))
		{
			if (*pipe_fd != 0)
				close(*pipe_fd);
			*pipe_fd = 0;
			return (1);
		}
		if (token->next->type == REDIRECT_TYPE
			&& ft_strncmp(token->next->value, "<<", 2) == 0)
		{
			if (is_heredocs_comamnd(token->value))
			{
				if (*pipe_fd != 0)
					close(*pipe_fd);
				*pipe_fd = 0;
				return (1);
			}
			return (0);
		}
		token = token->next;
	}
	return (1);
}
