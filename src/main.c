/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:28:03 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 13:07:32 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_data *mlx)
{
	int exit_status;

	exit_status = mlx->exit_status;
	if (mlx->win_ptr)
        mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		
	if (mlx->img_wall && mlx->img_wall->img_ptr)
    	mlx_destroy_image(mlx->mlx_ptr, mlx->img_wall->img_ptr);
	if (mlx->img_wall)
		free(mlx->img_wall);
		
	if (mlx->img_bg && mlx->img_bg->img_ptr)
    	mlx_destroy_image(mlx->mlx_ptr, mlx->img_bg->img_ptr);
	if (mlx->img_bg)
		free(mlx->img_bg);

	if (mlx->obstacle && mlx->obstacle->img_ptr)
    	mlx_destroy_image(mlx->mlx_ptr, mlx->obstacle->img_ptr);
	if (mlx->obstacle)
		free(mlx->obstacle);

	if (mlx->collect && mlx->collect->img_ptr)
    	mlx_destroy_image(mlx->mlx_ptr, mlx->collect->img_ptr);
	if (mlx->collect)
		free(mlx->collect);

	if (mlx->door && mlx->door->img_ptr)
    	mlx_destroy_image(mlx->mlx_ptr, mlx->door->img_ptr);
	if (mlx->door)
		free(mlx->door);

	if (mlx->player && mlx->player->img)
	{
		if (mlx->player->img->img_ptr)
			mlx_destroy_image(mlx->mlx_ptr, mlx->player->img->img_ptr);
		free(mlx->player->img);
	}	
	if (mlx->player)
		free(mlx->player);
	
	if (mlx->map && mlx->map->map_grid)
	{
		ft_free(mlx->map->map_grid);
	}
	if (mlx->map)
		free(mlx->map);
	
	if (mlx->buffer_img && mlx->buffer_img->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->buffer_img->img_ptr);
	if (mlx->buffer_img)
		free(mlx->buffer_img);

	if (mlx->mlx_ptr)
	{
    	mlx_destroy_display(mlx->mlx_ptr);
    	free(mlx->mlx_ptr);
	}
	free(mlx);
    exit(exit_status);
    return (0);
}

int key_press(int key, t_data *mlx)
{
	if (key == XK_Escape)
		close_window(mlx);
	if (is_valid_key(key))
		move_player(key, mlx);
	// printf("Button Clicked : {%d}\n", key);
	return (1);
}

void	init_data(t_data *mlx)
{
	mlx->player = malloc(sizeof(t_player));
	if (!mlx->player)
	{
		free(mlx);
		perror("player allocation fail :");
		exit(EXIT_FAILURE);
	}
	mlx->map->map_grid = NULL;
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img_bg = NULL;
	mlx->obstacle = NULL;
	mlx->collect = NULL;
	mlx->door = NULL;
	mlx->img_wall = NULL;
	mlx->buffer_img = malloc(sizeof(t_image));
	if (!mlx->buffer_img)
	{
		free(mlx->player);
		free(mlx);
		perror("Allocation failed for buffer_img structure! :");	
		close_window(mlx);
	}
	mlx->buffer_img->img_ptr = NULL;
	mlx->exit_status = EXIT_SUCCESS;
}

void	init_player_data(t_data *mlx)
{
	mlx->player->speed = 80;
	mlx->player->height = mlx->player->img->height;
    mlx->player->width = mlx->player->img->width;
	mlx->player->x *= mlx->img_wall->width;
	mlx->player->y *= mlx->img_wall->height;
}

int	main(int ac, char *av[])
{
	t_data *mlx;

	if (ac != 2)
	{
		ft_putstr_fd("Invalid arguments\n", 2);
		return (1);
	}
	mlx = malloc(sizeof(t_data));
	if (!mlx)
	{
		perror("mlx allocation fail :");
		return (1);
	}
	mlx->map = malloc(sizeof(t_map));
	if (!mlx->map)
	{
		free(mlx);
		perror("Allocation failed for map structure! :");	
		return (1);
	}
	init_data(mlx);
	process_map(av[1], mlx);
	parse_map(av[1], mlx);
	
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		clean_and_exit(mlx);
	if (!init_texture(mlx, &(mlx->img_bg), "assets/bg.xpm")
		|| !init_texture(mlx, &(mlx->img_wall), "assets/wall.xpm")
		|| !init_texture(mlx, &(mlx->player->img), "assets/warrior.xpm")
		|| !init_texture(mlx, &(mlx->obstacle), "assets/box_grey.xpm")
		|| !init_texture(mlx, &(mlx->collect), "assets/coin_skull.xpm")
		|| !init_texture(mlx, &(mlx->door), "assets/gate_closed.xpm"))
	{
		mlx->exit_status = EXIT_FAILURE;
		close_window(mlx);
	}

	init_player_data(mlx);
	
	mlx->WINDOW_WIDTH = mlx->map->map_width * mlx->img_wall->width;
	mlx->WINDOW_HEIGHT = mlx->map->map_height * mlx->img_wall->height;
	
	
	mlx->buffer_img->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->WINDOW_WIDTH, mlx->WINDOW_HEIGHT);
	if (!mlx->buffer_img->img_ptr)
	{
		perror("Failed to create buffer image!");
		mlx->exit_status = EXIT_FAILURE;
		close_window(mlx);
	}
	mlx->buffer_img->pixel_data = mlx_get_data_addr(
    mlx->buffer_img->img_ptr,
    &mlx->buffer_img->bpp,
    &mlx->buffer_img->line_size,
    &mlx->buffer_img->endian
	);

	mlx->buffer_img->width = mlx->WINDOW_WIDTH;
	mlx->buffer_img->height = mlx->WINDOW_HEIGHT;
	
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->WINDOW_WIDTH, mlx->WINDOW_HEIGHT, "Hello world!");
	draw_all(mlx);
	// mlx_hook(mlx->win_ptr, 2, 1L << 0, key_press, (t_data *) mlx);
	mlx_key_hook(mlx->win_ptr, key_press, (t_data *) mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_window, (t_data *) mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
