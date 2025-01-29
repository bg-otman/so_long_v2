/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:42:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 13:09:06 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    is_valid_move(int key, t_player *player, char **map)
{
    int playerX;
    int playerY;

    get_player_position(map, &playerX, &playerY);
    if (key == XK_Right)
    {
        if (map[playerY] && map[playerY][playerX + 1] != '1')
        {
            player->x += player->speed;
            map[playerY][playerX] = '0';
            map[playerY][playerX + 1] = 'P';
        }
    }
    if (key == XK_Left)
    {
        if (map[playerY] && map[playerY][playerX - 1] != '1')
        {
            player->x -= player->speed;
            map[playerY][playerX] = '0';
            map[playerY][playerX - 1] = 'P';
        }
    }
    if (key == XK_Up)
    {
        if (map[playerY - 1] && map[playerY - 1][playerX] != '1')
        {
            player->y -= player->speed;
            map[playerY][playerX] = '0';
            map[playerY - 1][playerX] = 'P';
        }
    }
    if (key == XK_Down)
    {
        if (map[playerY + 1] && map[playerY + 1][playerX] != '1')
        {
            player->y += player->speed;
            map[playerY][playerX] = '0';
            map[playerY + 1][playerX] = 'P';
        }
    }
}

void move_player(int key, t_data *mlx)
{
    t_player *player;
    player = mlx->player;
    is_valid_move(key, player, mlx->map->map_grid);
    draw_all(mlx);
}
