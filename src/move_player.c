/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:42:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/28 17:53:14 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

///  
void draw_rectangle_around_player(t_data *mlx)
{
    int pxl_x;
    int pxl_y;

    pxl_y = 0;
    while (pxl_y <= mlx->player->height)
    {
        pxl_x = 0;
        while (pxl_x <= mlx->player->width)
        {
            if (pxl_x == 0 || pxl_y == 0 || 
                pxl_y == mlx->player->height || 
                pxl_x == mlx->player->width)
            {
                mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 
                    mlx->player->x + pxl_x, mlx->player->y + pxl_y, 0x00FF00);
            }
            pxl_x++;
        }
        pxl_y++;
    }
}
///

void draw_player(t_data *mlx)
{
    draw_img(mlx, &mlx->player->img, mlx->player->x, mlx->player->y);
    draw_rectangle_around_player(mlx);
}

void move_player(int key, t_data *mlx)
{
    t_player *player;
    int max_move;
    int wall_width;

    player = mlx->player;
    wall_width = mlx->img_wall->width;
    mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
    if (key == XK_Left)
    {
        if (player->x > wall_width)
        {
            if (player->x - player->speed < wall_width)
                player->x = wall_width;
            else
                player->x -= player->speed;
        }
    }
    if (key == XK_Right)
    {
        if (player->x + player->width < mlx->WINDOW_WIDTH - wall_width)
        {
            max_move = mlx->WINDOW_WIDTH - wall_width - (player->x + player->width);
            if (player->speed > max_move)
                player->x += max_move;
            else
                player->x += player->speed;
        }
    }
    if (key == XK_Up)
    {
        if (player->y > wall_width)
        {
            if (player->y - player->speed < wall_width)
                player->y = wall_width;
            else
                player->y -= player->speed;
        }
    }
    if (key == XK_Down)
    {
        if (player->y + player->height < mlx->WINDOW_HEIGHT - wall_width)
        {
            max_move = mlx->WINDOW_HEIGHT - wall_width - (player->y + player->height);
            if (player->speed > max_move)
                player->y += max_move;
            else
                player->y += player->speed;
        }
    }
    draw_all(mlx);
}

// void    move_player(int key, t_data *mlx)
// {
//     t_player *player;

//     player = mlx->player;
//     if (key == 65363)
//         player->y += 10;
//     draw_all(mlx);
// }

