/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements_enemy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:11:35 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/21 11:54:47 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <limits.h>

void	left(t_mlx_data *data)
{
	long	x;

	x = 0;
	if (data->map[data->enemy_y / 75][(data->enemy_x - 75) / 75] != '1'
		&& data->map[data->enemy_y / 75][(data->enemy_x - 75) / 75] != 'E'
		&& data->map[data->enemy_y / 75][(data->enemy_x - 75) / 75] != 'C')
	{
		get_image(data->enemy_x, data->enemy_y, data, "./textures/space.xpm");
		data->enemy_x -= 75;
		get_image(data->enemy_x, data->enemy_y + 10, data,
			"./textures/meteor.xpm");
		if (data->enemy_x == data->player_x && data->enemy_y == data->player_y)
		{
			ft_printf("GAME OVER, you've been hit by a meteor\n");
			ft_exit(data);
		}
		data->map[(data->enemy_y) / 75][(data->enemy_x) / 75] = '0';
		while (x < 50000000)
			x++;
	}
}

void	right(t_mlx_data *data)
{
	long	x;

	x = 0;
	if (data->map[data->enemy_y / 75][(data->enemy_x + 75) / 75] != '1'
		&& data->map[data->enemy_y / 75][(data->enemy_x + 75) / 75] != 'E'
		&& data->map[data->enemy_y / 75][(data->enemy_x + 75) / 75] != 'C')
	{
		get_image(data->enemy_x, data->enemy_y, data, "./textures/space.xpm");
		data->enemy_x += 75;
		get_image(data->enemy_x, data->enemy_y + 10, data,
			"./textures/meteor.xpm");
		if (data->enemy_x == data->player_x && data->enemy_y == data->player_y)
		{
			ft_printf("GAME OVER, you've been hit by a meteor\n");
			ft_exit(data);
		}
		data->map[(data->enemy_y) / 75][(data->enemy_x) / 75] = '0';
		while (x < 50000000)
			x++;
	}
}

void	up(t_mlx_data *data)
{
	long	x;

	x = 0;
	if (data->map[(data->enemy_y - 75) / 75][(data->enemy_x) / 75] != '1'
		&& data->map[(data->enemy_y - 75) / 75][(data->enemy_x) / 75] != 'E'
		&& data->map[(data->enemy_y - 75) / 75][(data->enemy_x) / 75] != 'C')
	{
		get_image(data->enemy_x, data->enemy_y, data, "./textures/space.xpm");
		data->enemy_y -= 75;
		get_image(data->enemy_x, data->enemy_y + 10, data,
			"./textures/meteor.xpm");
		if (data->enemy_x == data->player_x && data->enemy_y == data->player_y)
		{
			ft_printf("GAME OVER, you've been hit by a meteor\n");
			ft_exit(data);
		}
		data->map[(data->enemy_y) / 75][(data->enemy_x) / 75] = '0';
		while (x < 50000000)
			x++;
	}
}

void	down(t_mlx_data *data)
{
	long	x;

	x = 0;
	if (data->map[(data->enemy_y + 75) / 75][(data->enemy_x) / 75] != '1'
		&& data->map[(data->enemy_y + 75) / 75][(data->enemy_x) / 75] != 'E'
		&& data->map[(data->enemy_y + 75) / 75][(data->enemy_x) / 75] != 'C')
	{
		get_image(data->enemy_x, data->enemy_y, data, "./textures/space.xpm");
		data->enemy_y += 75;
		get_image(data->enemy_x, data->enemy_y + 10, data,
			"./textures/meteor.xpm");
		if (data->enemy_x == data->player_x && data->enemy_y == data->player_y)
		{
			ft_printf("GAME OVER, you've been hit by a meteor\n");
			ft_exit(data);
		}
		data->map[(data->enemy_y) / 75][(data->enemy_x) / 75] = '0';
		while (x < 50000000)
			x++;
	}
}
