/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:13:02 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/06 16:26:07 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_token_count(t_token *token)
{
	int	count;

	count = 0;
	while (token != NULL)
	{
		count++;
		token = token->next;
	}
	return (count);
}

static t_token	*get_last_token(t_token *token)
{
	if (token == NULL)
		return (NULL);
	while (token->next != NULL)
		token = token->next;
	return (token);
}

static void	add_token_to_list(t_token **token_list, t_token *new_token)
{
	if (new_token == NULL)
		return ;
	if (*token_list == NULL)
	{
		*token_list = new_token;
		return ;
	}
	get_last_token(*token_list)->next = new_token;
}

static void	trim_quotes_from_token(t_token *token)
{
	char	*trimmed_value;

	if (ft_strchr("\"\'", token->value[0]))
	{
		trimmed_value = ft_strtrim_char(token->value, token->value[0]);
		free(token->value);
		token->value = trimmed_value;
		token->quote_check = 1;
	}
}

void	fill_token_list(char **parsed_commands, t_token **token_list)
{
	int		i;
	t_token	*token;

	i = 0;
	*token_list = NULL;
	while (parsed_commands[i] != NULL)
	{
		if (parsed_commands[i][0] == '\0')
		{
			i++;
			continue ;
		}
		token = malloc(sizeof(t_token));
		token->value = ft_strdup(parsed_commands[i]);
		token->type = 0;
		token->quote_check = 0;
		token->heredoc_check = 0;
		token->next = NULL;
		trim_quotes_from_token(token);
		add_token_to_list(token_list, token);
		i++;
	}
	g_shell->token_count = get_token_count(*token_list);
}
