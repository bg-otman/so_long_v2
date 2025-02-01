/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:42:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:44:50 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game_over(mlx);
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

static void	handle_horizontal_movement(int key, t_data *mlx, int player_x,
		int player_y)
{
	char	**map;

	map = mlx->map->map_grid;
	if (key == RIGHT || key == D_KEY)
	{
		if (map[player_y] && map[player_y][player_x + 1] != '1'
			&& (map[player_y][player_x + 1] != 'E' || mlx->collect_all))
		{
			mlx->player->x += mlx->player->speed;
			map[player_y][player_x] = '0';
			map[player_y][player_x + 1] = 'P';
			ft_printf("player moves : %d\n", ++(mlx->player->moves_count));
		}
	}
	if (key == LEFT || key == A_KEY)
	{
		if (map[player_y] && map[player_y][player_x - 1] != '1'
			&& (map[player_y][player_x - 1] != 'E' || mlx->collect_all))
		{
			mlx->player->x -= mlx->player->speed;
			map[player_y][player_x] = '0';
			map[player_y][player_x - 1] = 'P';
			ft_printf("player moves : %d\n", ++(mlx->player->moves_count));
		}
	}
}

static void	handle_vertical_movement(int key, t_data *mlx, int player_x,
		int player_y)
{
	char	**map;

	map = mlx->map->map_grid;
	if (key == UP || key == W_KEY)
	{
		if (map[player_y - 1] && map[player_y - 1][player_x] != '1' &&
			(map[player_y - 1][player_x] != 'E' || mlx->collect_all))
		{
			mlx->player->y -= mlx->player->speed;
			map[player_y][player_x] = '0';
			map[player_y - 1][player_x] = 'P';
			ft_printf("player moves : %d\n", ++(mlx->player->moves_count));
		}
	}
	if (key == DOWN || key == S_KEY)
	{
		if (map[player_y + 1] && map[player_y + 1][player_x] != '1' &&
			(map[player_y + 1][player_x] != 'E' || mlx->collect_all))
		{
			mlx->player->y += mlx->player->speed;
			map[player_y][player_x] = '0';
			map[player_y + 1][player_x] = 'P';
			ft_printf("player moves : %d\n", ++(mlx->player->moves_count));
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
	if (mlx->collect_all)
		check_entred_door(mlx, mlx->map->map_grid);
	draw_all(mlx);
}
