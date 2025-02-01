/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:28:03 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 16:35:55 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_data *mlx, int win)
{
	char	*msg;

	if (win)
		msg = ft_strdup("Won !");
	else
		msg = ft_strdup("Lost!");
	ft_printf("|-------------------|\n");
	ft_printf("|Game over You %s|\n", msg);
	ft_printf("|-------------------|\n");
	free(msg);
	close_window(mlx);
}

int	key_press(int key, t_data *mlx)
{
	if (key == XK_Escape)
		close_window(mlx);
	if (is_valid_key(key))
		move_player(key, mlx);
	return (1);
}

static t_data	*allocate_memory(void)
{
	t_data	*mlx;

	mlx = malloc(sizeof(t_data));
	if (!mlx)
	{
		perror("mlx allocation fail :");
		exit(1);
	}
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
	{
		free(mlx);
		perror("Allocation failed for map structure! :");
		exit(1);
	}
	return (mlx);
}

int	update_frame(t_data *mlx)
{
	mlx->frame++;
	if (mlx->frame > E_NUM_SPRITES * 10)
		mlx->frame = 0;
	draw_all(mlx);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	*mlx;

	if (ac != 2)
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		exit(1);
	}
	mlx = allocate_memory();
	init_data(mlx);
	process_map(av[1], mlx);
	parse_map(av[1], mlx);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		clean_and_exit(mlx);
	load_imgs(mlx);
	init_player_data(mlx);
	init_buffer_img(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->window_width,
			mlx->window_height, "so_long");
	mlx_key_hook(mlx->win_ptr, key_press, (t_data *)mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, (t_data *)mlx);
	mlx_loop_hook(mlx->mlx_ptr, update_frame, (t_data *)mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
