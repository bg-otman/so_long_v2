/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:28:03 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/30 15:55:18 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_data *mlx)
{
	ft_printf("|------------------|\n");
	ft_printf("|Game over You won!|\n");
	ft_printf("|------------------|\n");
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

static void	validate_args(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		exit(1);
	}
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

int	main(int ac, char *av[])
{
	t_data	*mlx;

	validate_args(ac);
	mlx = allocate_memory();
	init_data(mlx);
	process_map(av[1], mlx);
	parse_map(av[1], mlx);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		clean_and_exit(mlx);
	load_imgs(mlx);
	init_player_data(mlx);
	mlx->window_width = mlx->map->map_width * mlx->img_wall->width;
	mlx->window_height = mlx->map->map_height * mlx->img_wall->height;
	init_buffer_img(mlx);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->window_width,
			mlx->window_height, "so_long");
	draw_all(mlx);
	mlx_key_hook(mlx->win_ptr, key_press, (t_data *)mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, (t_data *)mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
