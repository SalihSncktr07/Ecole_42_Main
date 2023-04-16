/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 18:56:22 by spirnaz           #+#    #+#             */
/*   Updated: 2023/04/16 18:56:23 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_create(t_data *data)
{
	data->img.bg = mlx_xpm_file_to_image(data->mlx, "img/background.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, "img/coin.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.door = mlx_xpm_file_to_image(data->mlx, "img/door.xpm",
			&data->img.img_w, &data->img.img_h);
	data->img.character = mlx_xpm_file_to_image(data->mlx, "img/character.xpm",
			&data->img.img_w, &data->img.img_h);
}

void	map_read(t_data *data)
{
	int		fd;
	int		i;
	int		j;
	char	*area;

	i = 0;
	j = 0;
	fd = open(data->map_tmp, O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * data->map_height);
	while (i < data->map_height)
	{
		j = 0;
		area = get_next_line(fd);
		data->map[i] = (char *)malloc(sizeof(char) * data->map_width);
		if (area == NULL)
			break ;
		while (j < data->map_width)
		{
			data->map[i][j] = area[j];
			j++;
		}
		data->map[i][j] = '\0';
		i++;
		free(area);
	}
}

static void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_width * IMG_SIZE,
			data->map_height * IMG_SIZE, "SoLong");
	data->coin_count = 0;
	data->coin_collected = 0;
	data->step_count = 0;
	data->exit_count = 0;
	data->wall_count = 0;
	data->player_count = 0;
	data->unwanted_character_count = 0;
}

void	mlx_create(t_data *data)
{
	data_init(data);
	image_create(data);
	map_read(data);
	map_background_put(data);
	map_create(data);
	wall_control(data);
	min_element_control(data);
	placeholder(data, data->exit_x, data->exit_y);
	if (data->i_map.read_count != data->coin_count + 1)
		err_msg(">>> Map is wrong!");
	hook(data);
	mlx_loop(data->mlx);
}
