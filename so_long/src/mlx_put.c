/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:56:31 by spirnaz           #+#    #+#             */
/*   Updated: 2023/04/16 18:56:32 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_put(int i, int j, t_data *data)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.door,
			j * IMG_SIZE, i * IMG_SIZE);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.character, j * IMG_SIZE, i * IMG_SIZE);
}

static void	map_element_counter(int i, int j, t_data *data)
{
	int	idiot;

	idiot = 0;
	if (data->map[i][j] == '1')
		data->wall_count++;
	else if (data->map[i][j] == '0')
		idiot++;
	else if (data->map[i][j] == 'C')
		data->coin_count++;
	else if (data->map[i][j] == 'E')
	{
		data->exit_count++;
		data->exit_x = j;
		data->exit_y = i;
	}
	else if (data->map[i][j] == 'P')
	{
		data->player_x = j;
		data->player_y = i;
		data->player_count++;
	}
	else
		data->unwanted_character_count++;
}

void	map_create(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			map_put(i, j, data);
			map_element_counter(i, j, data);
			j++;
		}
		i++;
	}
}

void	map_background_put(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img.bg,
				j * IMG_SIZE, i * IMG_SIZE);
			j++;
		}
		i++;
	}
}
