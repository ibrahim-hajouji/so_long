/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:01:05 by ihajouji          #+#    #+#             */
/*   Updated: 2024/04/25 16:35:36 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' 
		|| str[i - 3] != '.' || ((i - 4) == 0))
	{
		ft_printf("Error\n Invalid map description file\n");
		exit(0);
	}
	return ;
}

int	handle_key(int keycode, t_mlx_data *data)
{
	if (keycode == 53)
		ft_exit(data);
	else if (keycode == 0 || keycode == 123)
		to_left(data);
	else if (keycode == 2 || keycode == 124)
		to_right(data);
	else if (keycode == 13 || keycode == 126)
		to_up(data);
	else if (keycode == 1 || keycode == 125)
		to_down(data);
	return (0);
}

void	init_vars(t_mlx_data *data)
{
	data->w_width = calculate_width(data);
	if (data -> w_width > 110)
		ft_quit(7);
	if (data -> w_height > 80)
		ft_quit(7);
	data->num_coins = calculate_coins(data);
	data->coins_collected = 0;
	data->move = 0;
}

int	main(int ac, char **av)
{
	t_mlx_data	*data;

	if (ac != 2)
		return (0);
	data = malloc(sizeof(t_mlx_data));
	data->w_height = check_file(av, data);
	init_vars(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		_free(data, 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->w_width - 1) * 75,
			data->w_height * 75, "So_long");
	if (!data->win_ptr)
		_free(data, 2);
	put_image(data);
	mlx_hook(data->win_ptr, 2, 0, handle_key, data);
	mlx_hook(data->win_ptr, 17, 0, ft_exit, data);
	mlx_loop(data->mlx_ptr);
}
