/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:29:22 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/24 19:17:51 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	turn_s2(t_mlx_data *data)
{
	int	x;

	x = 0;
	if (data->rand == 0)
	{
		get_image(data->player_x, data->player_y, data, "./textures/space.xpm");
		get_image(data->player_x + 8, data->player_y + 10, data,
			"./textures/spaceship_bonus.xpm");
		data->rand = 1;
	}
	else if (data->rand == 1)
	{
		get_image(data->player_x, data->player_y, data, "./textures/space.xpm");
		get_image(data->player_x + 8, data->player_y + 10, data,
			"./textures/spaceship2_bonus.xpm");
		data->rand = 0;
		while (x < 50000000)
			x++;
	}
	return (0);
}

int	turn_s(t_mlx_data *data)
{
	if (data->rand == 0)
	{
		get_image(data->player_x, data->player_y, data, "./textures/space.xpm");
		get_image(data->player_x + 8, data->player_y + 10, data,
			"./textures/spaceship_bonus.xpm");
		data->rand = 1;
	}
	else if (data->rand == 1)
	{
		get_image(data->player_x, data->player_y, data, "./textures/space.xpm");
		get_image(data->player_x + 8, data->player_y + 10, data,
			"./textures/spaceship2_bonus.xpm");
		data->rand = 0;
	}
	return (0);
}

int	move(t_mlx_data *data)
{
	int	random;

	turn_s(data);
	random = rand() % 4;
	if (random == 0)
		left(data);
	else if (random == 1)
		right(data);
	else if (random == 2)
		up(data);
	else if (random == 3)
		down(data);
	return (0);
}
