/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:31:55 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/22 20:43:56 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_move(t_mlx_data *data)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = "Move : ";
	str2 = ft_itoa(data->move);
	str3 = ft_strjoin(str, str2);
	get_image(0, 0, data, "./textures/space.xpm");
	get_image(0, 0, data, "./textures/blackhole.xpm");
	get_image(75, 0, data, "./textures/space.xpm");
	get_image(75, 0, data, "./textures/blackhole.xpm");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 25, 0x00FFFFFF,
		str3);
	free(str3);
	free(str2);
	return ;
}

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
		render_move(data);
		data->player_x -= 75;
		get_image(data->player_x, data->player_y + 10, data,
			"./textures/spaceship_bonus.xpm");
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
		render_move(data);
		data->player_x += 75;
		get_image(data->player_x, data->player_y + 10, data,
			"./textures/spaceship_bonus.xpm");
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
		render_move(data);
		data->player_y -= 75;
		get_image(data->player_x, data->player_y + 10, data,
			"./textures/spaceship_bonus.xpm");
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
		render_move(data);
		data->player_y += 75;
		get_image(data->player_x, data->player_y + 10, data,
			"./textures/spaceship_bonus.xpm");
		if (data->map[(data->player_y) / 75][(data->player_x) / 75] == 'E'
			&& data->coins_collected == data->num_coins)
		{
			ft_printf("CONGRATS, you have conquered the earth successfully\n");
			ft_exit(data);
		}
	}
}
