/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:06:28 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 13:16:59 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_side_wall(t_data *mlx, int x, int y)
{
    while (y < mlx->WINDOW_HEIGHT - mlx->img_wall->height)
    {
        put_img_to_buffer(mlx->buffer_img, mlx->img_wall, x, y);
        y += mlx->img_wall->height;
    }
}

void draw_up_wall(t_data *mlx)
{
    int x = 0;
    while (x < mlx->WINDOW_WIDTH)
    {
        put_img_to_buffer(mlx->buffer_img, mlx->img_wall, x, 0);
        x += mlx->img_wall->width;
    }
}

void draw_down_wall(t_data *mlx)
{
    int x = 0;
    while (x < mlx->WINDOW_WIDTH)
    {
        put_img_to_buffer(mlx->buffer_img, mlx->img_wall, x, mlx->WINDOW_HEIGHT - mlx->img_wall->height);
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
