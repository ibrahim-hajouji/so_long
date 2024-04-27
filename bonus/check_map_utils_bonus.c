/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:43:23 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/18 17:30:18 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	check_valid(char c)
{
	if (c != 'E' && c != 'P' && c != 'C' && c != '1' && c != '0' && c != 'S')
		return (0);
	return (1);
}

int	check_enemy(char **str, int len)
{
	int	i;
	int	j;
	int	s;

	i = 0;
	s = 0;
	while (i < len)
	{
		j = 0;
		while (j < line(str[0]))
		{
			if (str[i][j] == 'S')
				s++;
			j++;
		}
		i++;
	}
	if (s > 1)
		ft_quit(2);
	return (s);
}
