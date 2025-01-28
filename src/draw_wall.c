/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:06:28 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/27 15:38:30 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_side_wall(t_data *mlx, int x, int y)
{
    while (y < mlx->WINDOW_HEIGHT - mlx->img_wall->height)
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall->img_ptr, x, y);
        y += mlx->img_wall->height;
    }
}

void draw_up_wall(t_data *mlx)
{
    int x = 0;
    while (x < mlx->WINDOW_WIDTH)
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall->img_ptr, x, 0);
        x += mlx->img_wall->width;
    }
}

void draw_down_wall(t_data *mlx)
{
    int x = 0;
    while (x < mlx->WINDOW_WIDTH)
    {
        mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_wall->img_ptr, 
            x, mlx->WINDOW_HEIGHT - mlx->img_wall->height);
        x += mlx->img_wall->width;
    }
}

void draw_wall(t_data *mlx)
{
    if (!mlx->img_wall->img_ptr)
    {
        printf("Wall texture not loaded!\n");
        return;
    }
    draw_up_wall(mlx);
    draw_down_wall(mlx);
    draw_side_wall(mlx, 0, mlx->img_wall->height);
    draw_side_wall(mlx, mlx->WINDOW_WIDTH - mlx->img_wall->width, mlx->img_wall->height);
}
