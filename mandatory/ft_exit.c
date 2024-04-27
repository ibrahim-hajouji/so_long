/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:39:25 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/26 10:50:34 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_mlx_data *data)
{
	int	x;

	x = 0;
	while (x < data->w_height)
	{
		free(data->map[x]);
		x++;
	}
	free(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

void	ft_exit2(char **s, int j, t_mlx_data *data, t_player *player)
{
	int	x;

	x = 0;
	ft_printf("Error\n There's no possible path to the Exit\n");
	while (x < j)
		free(s[x++]);
	free(s);
	x = 0;
	while (x < j)
		free(data -> map[x++]);
	free(data -> map);
	free(data);
	free(player);
	exit(0);
	return ;
}

void	ft_quit(int x)
{
	int	i;

	i = 0;
	if (x == 0)
		ft_printf("Error\n You didnt put only one exit\n");
	else if (x == 1)
		ft_printf("Error\n You didnt put only one start\n");
	else if (x == 3)
		ft_printf("Error\n You entered a non valable character\n");
	else if (x == 4)
		ft_printf("Error\n You didnt put any collectable\n");
	else if (x == 5)
		ft_printf("Error\n The map must be rectangular\n");
	else if (x == 6)
		ft_printf("Error\n You gave the Spaceship an escape point\n");
	else if (x == 7)
		ft_printf("Error\n You've entered a giant map try smaller ones\n");
	exit(0);
}

void	_free(t_mlx_data *data, int i)
{
	int	k;

	k = 0;
	if (i == 1)
	{
		while (k < data->w_height)
			free(data->map[k++]);
		free(data->map);
		free(data);
		exit(0);
	}
	else if (i == 2)
	{
		while (k < data->w_height)
			free(data->map[k++]);
		free(data->map);
		exit(0);
	}
	return ;
}
