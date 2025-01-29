/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:17:10 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 13:18:06 by obouizi          ###   ########.fr       */
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
				put_img_to_buffer(mlx->buffer_img, mlx->obstacle, x, y);
			else if (map[i][j] == 'C')
				put_img_to_buffer(mlx->buffer_img, mlx->collect, x, y);
			else if (map[i][j] == 'E')
				put_img_to_buffer(mlx->buffer_img, mlx->door, x, y);
			else if (map[i][j] == 'P')
				put_img_to_buffer(mlx->buffer_img, mlx->player->img, x, y);
			x += mlx->img_wall->width;
			j++;
		}
		i++;
		y += mlx->img_wall->height;
	}
}
void clear_buffer(t_image *buffer, int color)
{
    for (int y = 0; y < buffer->height; y++)
    {
        for (int x = 0; x < buffer->width; x++)
        {
            put_pixel_to_buffer(buffer, x, y, color);
        }
    }
}


void draw_all(t_data *mlx)
{
	clear_buffer(mlx->buffer_img, 0x000000);
	draw_background(mlx);
	draw_wall(mlx);
	draw_map(mlx, mlx->map->map_grid);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->buffer_img->img_ptr, 0, 0);
}
