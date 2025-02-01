/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:42:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:02:03 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_entred_door(t_data *mlx, char **map)
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
	game_over(mlx, 1);
}

void	get_player_position(char **map, int *player_x, int *player_y)
{
	int (y), (x);
	y = 1;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*player_x = x;
				*player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	handle_horizontal_movement(int key, t_data *mlx, int x, int y)
{
	if (key == XK_Right || key == XK_d)
	{
		if (mlx->map->map_grid[y] && mlx->map->map_grid[y][x + 1] != '1'
			&& (mlx->map->map_grid[y][x + 1] != 'E' || mlx->collect_all))
		{
			mlx->player->x += mlx->player->speed;
			mlx->map->map_grid[y][x] = '0';
			mlx->map->map_grid[y][x + 1] = 'P';
			mlx->player->moves_count++;
		}
		mlx->player->look_right = 1;
	}
	if (key == XK_Left || key == XK_a)
	{
		if (mlx->map->map_grid[y] && mlx->map->map_grid[y][x - 1] != '1'
			&& (mlx->map->map_grid[y][x - 1] != 'E' || mlx->collect_all))
		{
			mlx->player->x -= mlx->player->speed;
			mlx->map->map_grid[y][x] = '0';
			mlx->map->map_grid[y][x - 1] = 'P';
			mlx->player->moves_count++;
		}
		mlx->player->look_right = 0;
	}
}

static void	handle_vertical_movement(int key, t_data *mlx, int player_x,
		int player_y)
{
	char	**map;

	map = mlx->map->map_grid;
	if (key == XK_Up || key == XK_w)
	{
		if (map[player_y - 1] && map[player_y - 1][player_x] != '1' &&
			(map[player_y - 1][player_x] != 'E' || mlx->collect_all))
		{
			mlx->player->y -= mlx->player->speed;
			map[player_y][player_x] = '0';
			map[player_y - 1][player_x] = 'P';
			mlx->player->moves_count++;
		}
	}
	if (key == XK_Down || key == XK_s)
	{
		if (map[player_y + 1] && map[player_y + 1][player_x] != '1' &&
			(map[player_y + 1][player_x] != 'E' || mlx->collect_all))
		{
			mlx->player->y += mlx->player->speed;
			map[player_y][player_x] = '0';
			map[player_y + 1][player_x] = 'P';
			mlx->player->moves_count++;
		}
	}
}

void	move_player(int key, t_data *mlx)
{
	int	player_x;
	int	player_y;

	get_player_position(mlx->map->map_grid, &player_x, &player_y);
	handle_horizontal_movement(key, mlx, player_x, player_y);
	handle_vertical_movement(key, mlx, player_x, player_y);
	enemy_collision(mlx, mlx->map->map_grid);
	if (mlx->collect_all)
		check_entred_door(mlx, mlx->map->map_grid);
}
