/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:42:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 21:20:33 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    game_over(t_data *mlx)
{
    printf("Game over You won!\n");
    close_window(mlx);
}

void    check_entred_door(t_data *mlx, char **map)
{
    int (y), (x);
    
    y = 1;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'E')
                return ;
            x++;
        }
        y++;
    }
    game_over(mlx);
}

void    is_valid_move(int key, t_player *player, char **map, t_data *mlx)
{
    int playerX;
    int playerY;

    get_player_position(map, &playerX, &playerY);
    if (key == XK_Right)
    {
        if (map[playerY] && map[playerY][playerX + 1] != '1'
             && (map[playerY][playerX + 1] != 'E' || mlx->collect_all))
        {
            player->x += player->speed;
            map[playerY][playerX] = '0';
            map[playerY][playerX + 1] = 'P';
        }
    }
    if (key == XK_Left)
    {
        if (map[playerY] && map[playerY][playerX - 1] != '1'
            && (map[playerY][playerX - 1] != 'E' || mlx->collect_all))
        {
            player->x -= player->speed;
            map[playerY][playerX] = '0';
            map[playerY][playerX - 1] = 'P';
        }
    }
    if (key == XK_Up)
    {
        if (map[playerY - 1] && map[playerY - 1][playerX] != '1'
            && (map[playerY - 1][playerX] != 'E' || mlx->collect_all))
        {
            player->y -= player->speed;
            map[playerY][playerX] = '0';
            map[playerY - 1][playerX] = 'P';
        }
    }
    if (key == XK_Down)
    {
        if (map[playerY + 1] && map[playerY + 1][playerX] != '1'
            && (map[playerY + 1][playerX] != 'E' || mlx->collect_all))
        {
            player->y += player->speed;
            map[playerY][playerX] = '0';
            map[playerY + 1][playerX] = 'P';
        }
    }
    if (mlx->collect_all)
    {
        check_entred_door(mlx, map);
    }
}



void move_player(int key, t_data *mlx)
{
    is_valid_move(key, mlx->player, mlx->map->map_grid, mlx);
    draw_all(mlx);
}
