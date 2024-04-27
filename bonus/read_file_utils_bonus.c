/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:46:33 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/16 16:46:41 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_player	*player_pos(char **s, int j)
{
	size_t		x;
	int			y;
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	y = 0;
	while (y < j)
	{
		x = 0;
		while (x < ft_strlen(s[0]) - 1)
		{
			if (s[y][x] == 'P')
			{
				player->x = x;
				player->y = y;
				break ;
			}
			else
				x++;
		}
		y++;
	}
	return (player);
}

int	calculate_width(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->map[0][i])
		i++;
	return (i);
}
