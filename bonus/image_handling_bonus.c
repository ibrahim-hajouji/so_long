/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:44:16 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/21 13:24:18 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_image_enemy(int x, int y, t_mlx_data *data)
{
	data->enemy_x = x;
	data->enemy_y = y;
	data->rand2 = 0;
	get_image(x, y, data, "./textures/space.xpm");
	get_image(x + 27, y + 20, data, "./textures/meteor.xpm");
}

void	get_image(int x, int y, t_mlx_data *data, char *file)
{
	int	a;
	int	b;
	int	z;

	z = 0;
	data->image = mlx_xpm_file_to_image(data->mlx_ptr, file, &a, &b);
	if (!data->image)
	{
		while (z < data->w_height)
			free(data->map[z++]);
		free(data->map);
		exit(0);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, x, y);
}

void	put_image_to_map(char c, int x, int y, t_mlx_data *data)
{
	if (c == '0')
		get_image(x, y, data, "./textures/space.xpm");
	else if (c == 'P')
	{
		data->player_x = x;
		data->player_y = y;
		data->rand = 0;
		get_image(x, y, data, "./textures/space.xpm");
		get_image(x, y + 10, data, "./textures/spaceship_bonus.xpm");
	}
	else if (c == '1')
		get_image(x, y, data, "./textures/blackhole.xpm");
	else if (c == 'E')
	{
		get_image(x, y, data, "./textures/space.xpm");
		get_image(x + 8, y + 8, data, "./textures/earth.xpm");
	}
	else if (c == 'C')
	{
		get_image(x, y, data, "./textures/space.xpm");
		get_image(x + 27, y + 20, data, "./textures/alien.xpm");
	}
	else if (c == 'S')
		get_image_enemy(x, y, data);
	return ;
}

void	put_image(t_mlx_data *data)
{
	int	x;
	int	y;
	int	x_map;
	int	y_map;

	y = 0;
	y_map = 0;
	while (y_map < data->w_height)
	{
		x = 0;
		x_map = 0;
		while (x_map < data->w_width)
		{
			put_image_to_map(data->map[y_map][x_map], x, y, data);
			x += 75;
			x_map++;
		}
		y += 75;
		y_map++;
	}
}
