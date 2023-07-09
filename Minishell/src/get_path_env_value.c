/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_env_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 02:37:52 by spirnaz            #+#    #+#             */
/*   Updated: 2023/07/05 12:31:45 by spirnaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path_env_value(void)
{
	char	*path_env_value;

	path_env_value = get_env_value("PATH");
	if (path_env_value == NULL)
	{
		g_shell->exit_status = 1;
		ft_printf(2, "No such file or directory\n");
		return (NULL);
	}
	g_shell->exit_status = 0;
	return (path_env_value);
}
