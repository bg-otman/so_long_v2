/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:17:10 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/28 21:41:47 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *mlx, char **map)
{
	int (x), (y), (i), (j);	
	x = mlx->img_wall->width;
	y = mlx->img_wall->height;
	i = 1;
	while (y < mlx->WINDOW_HEIGHT - mlx->img_wall->height)
	{
		j = 1;
		x = mlx->img_wall->width;
		while (x < mlx->WINDOW_WIDTH - mlx->img_wall->width)
		{
			if (map[i][j] == '1')
				draw_obstacle(mlx, x, y);
			else if (map[i][j] == 'C')
				draw_collectable(mlx, x, y);
			else if (map[i][j] == 'E')
				draw_door(mlx, x, y);
			x += mlx->img_wall->width;
			j++;
		}
		i++;
		y += mlx->img_wall->height;
	}
}


void draw_all(t_data *mlx)
{
	draw_background(mlx);
	draw_wall(mlx);
	draw_map(mlx, mlx->map->map_grid);
	draw_player(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->buffer_img->img_ptr, 0, 0);
}
