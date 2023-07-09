/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:57:59 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/05 13:08:15 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_temp_token(char **temp_token, char *line)
{
	free(line);
	clear_string_list(temp_token);
}

void	clear_token_list(t_token **token_list)
{
	t_token	*current;

	current = *token_list;
	if (token_list == NULL || current == NULL)
		return ;
	while (current->next != NULL)
	{
		current = (*token_list)->next;
		free((*token_list)->value);
		free(*token_list);
		*token_list = current;
	}
	free((*token_list)->value);
	free(*token_list);
}

void	clear_env_list(t_env **env_list, int env_count)
{
	int	i;

	i = 0;
	if (env_list == NULL)
		return ;
	while (i < env_count)
	{
		free(env_list[i]->name);
		free(env_list[i]->value);
		free(env_list[i]);
		i++;
	}
	free(env_list);
}

void	clear_string_list(char **string_list)
{
	int	i;

	i = 0;
	if (string_list == NULL)
		return ;
	while (string_list[i] != NULL)
	{
		free(string_list[i]);
		i++;
	}
	free(string_list);
}
