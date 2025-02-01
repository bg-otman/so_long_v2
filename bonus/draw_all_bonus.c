/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:17:10 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 17:59:51 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collectable_count(t_data *mlx, char **map)
{
	int (i), (j);
	i = 0;
	mlx->collectable_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				mlx->collectable_count++;
			j++;
		}
		i++;
	}
}

void	draw_door(t_data *mlx, char **map, int x, int y)
{
	collectable_count(mlx, map);
	if (mlx->collectable_count == 0)
	{
		put_img_to_buffer(mlx->buffer_img, mlx->door_open, x, y);
		mlx->collect_all = 1;
	}
	else
		put_img_to_buffer(mlx->buffer_img, mlx->door_close, x, y);
}

void	draw_map(t_data *mlx, char **map, int x, int y)
{
	int (j), (i);
	i = 1;
	while (y < mlx->window_height - mlx->img_wall->height)
	{
		j = 1;
		x = mlx->img_wall->width;
		while (x < mlx->window_width - mlx->img_wall->width)
		{
			if (map[i][j] == '1')
				put_img_to_buffer(mlx->buffer_img, mlx->obstacle, x, y);
			else if (map[i][j] == 'C')
				put_img_to_buffer(mlx->buffer_img, mlx->collect, x, y);
			else if (map[i][j] == 'E')
				draw_door(mlx, map, x, y);
			else if (map[i][j] == 'P')
				draw_player(mlx, x, y);
			else if (map[i][j] == 'N')
				draw_enemy(mlx, x, y);
			x += mlx->img_wall->width;
			j++;
		}
		i++;
		y += mlx->img_wall->height;
	}
}

void	clear_buffer_img(t_image *buffer, int color)
{
	int (x), (y);
	y = 0;
	while (y < buffer->height)
	{
		x = 0;
		while (x < buffer->width)
		{
			put_pixel_to_buffer(buffer, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_all(t_data *mlx)
{
	clear_buffer_img(mlx->buffer_img, 0x000000);
	draw_background(mlx);
	draw_wall(mlx);
	draw_map(mlx, mlx->map->map_grid, mlx->img_wall->width,
		mlx->img_wall->height);
	display_move_count(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->buffer_img->img_ptr, 0, 0);
}
