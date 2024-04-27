/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:38:06 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/25 17:28:19 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_left(t_mlx_data *data)
{
	if (data->map[data->player_y / 75][(data->player_x - 75) / 75] != '1')
	{
		get_image(data->player_x, data->player_y, data, "./textures/space.xpm");
		if (data->map[data->player_y / 75][data->player_x / 75] == 'E')
			get_image(data->player_x + 8, data->player_y + 8, data,
				"./textures/earth.xpm");
		if (data->map[data->player_y / 75][(data->player_x - 75) / 75] == 'C')
		{
			data->map[data->player_y / 75][(data->player_x - 75) / 75] = '0';
			data->coins_collected++;
		}
		data->move++;
		ft_printf("move : %d\n", data->move);
		data->player_x -= 75;
		get_image(data->player_x + 8, data->player_y + 8, data,
			"./textures/spaceship.xpm");
		if (data->map[(data->player_y) / 75][(data->player_x) / 75] == 'E'
			&& data->coins_collected == data->num_coins)
		{
			ft_printf("CONGRATS, you have conquered the earth successfully\n");
			ft_exit(data);
		}
	}
}

void	to_right(t_mlx_data *data)
{
	if (data->map[data->player_y / 75][(data->player_x + 75) / 75] != '1')
	{
		get_image(data->player_x, data->player_y, data, "./textures/space.xpm");
		if (data->map[data->player_y / 75][data->player_x / 75] == 'E')
			get_image(data->player_x + 8, data->player_y + 8, data,
				"./textures/earth.xpm");
		if (data->map[data->player_y / 75][(data->player_x + 75) / 75] == 'C')
		{
			data->map[data->player_y / 75][(data->player_x + 75) / 75] = '0';
			data->coins_collected++;
		}
		data->move++;
		ft_printf("move : %d\n", data->move);
		data->player_x += 75;
		get_image(data->player_x + 8, data->player_y + 8, data,
			"./textures/spaceship.xpm");
		if (data->map[(data->player_y) / 75][(data->player_x) / 75] == 'E'
			&& data->coins_collected == data->num_coins)
		{
			ft_printf("CONGRATS, you have conquered the earth successfully\n");
			ft_exit(data);
		}
	}
}

void	to_up(t_mlx_data *data)
{
	if (data->map[(data->player_y - 75) / 75][(data->player_x) / 75] != '1')
	{
		get_image(data->player_x, data->player_y, data, "./textures/space.xpm");
		if (data->map[data->player_y / 75][data->player_x / 75] == 'E')
			get_image(data->player_x + 8, data->player_y + 8, data,
				"./textures/earth.xpm");
		if (data->map[(data->player_y - 75) / 75][(data->player_x) / 75] == 'C')
		{
			data->map[(data->player_y - 75) / 75][(data->player_x) / 75] = '0';
			data->coins_collected++;
		}
		data->move++;
		ft_printf("move : %d\n", data->move);
		data->player_y -= 75;
		get_image(data->player_x + 8, data->player_y + 8, data,
			"./textures/spaceship.xpm");
		if (data->map[(data->player_y) / 75][(data->player_x) / 75] == 'E'
			&& data->coins_collected == data->num_coins)
		{
			ft_printf("CONGRATS, you have conquered the earth successfully\n");
			ft_exit(data);
		}
	}
}

void	to_down(t_mlx_data *data)
{
	if (data->map[(data->player_y + 75) / 75][(data->player_x) / 75] != '1')
	{
		get_image(data->player_x, data->player_y, data, "./textures/space.xpm");
		if (data->map[data->player_y / 75][data->player_x / 75] == 'E')
			get_image(data->player_x + 8, data->player_y + 8, data,
				"./textures/earth.xpm");
		if (data->map[(data->player_y + 75) / 75][(data->player_x) / 75] == 'C')
		{
			data->map[(data->player_y + 75) / 75][(data->player_x) / 75] = '0';
			data->coins_collected++;
		}
		data->move++;
		ft_printf("move : %d\n", data->move);
		data->player_y += 75;
		get_image(data->player_x + 8, data->player_y + 8, data,
			"./textures/spaceship.xpm");
		if (data->map[(data->player_y) / 75][(data->player_x) / 75] == 'E'
			&& data->coins_collected == data->num_coins)
		{
			ft_printf("CONGRATS, you have conquered the earth successfully\n");
			ft_exit(data);
		}
		data->map[(data->player_y) / 75][(data->player_x) / 75] = '0';
	}
}
