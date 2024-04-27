/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:26:37 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/16 15:44:03 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	calculate_coins(t_mlx_data *data)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	y = 0;
	while (y < data->w_height)
	{
		x = 0;
		while (x < data->w_width)
		{
			if (data->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

int	check_char2(char c)
{
	if (c != 'E' && c != 'P' && c != 'C' && c != '1' && c != '0')
		return (0);
	return (1);
}
