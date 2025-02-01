/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:48:43 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 17:59:06 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	allowed_move(char **map, int x, int y, int allow_exit)
{
	if (map[y][x] == '0' || map[y][x] == 'C' || (allow_exit
			&& map[y][x] == 'E'))
		return (1);
	return (0);
}

void	floodfill(int x, int y, t_map *map, int allow_exit)
{
	char	visited;
	char	**map_copy;

	visited = 'X';
	map_copy = map->map_copy;
	map_copy[y][x] = visited;
	if (x - 1 >= 0 && allowed_move(map_copy, x - 1, y, allow_exit))
		floodfill(x - 1, y, map, allow_exit);
	if (x + 1 < map->map_width && allowed_move(map_copy, x + 1, y, allow_exit))
		floodfill(x + 1, y, map, allow_exit);
	if (y + 1 < map->map_height && allowed_move(map_copy, x, y + 1, allow_exit))
		floodfill(x, y + 1, map, allow_exit);
	if (y - 1 >= 0 && allowed_move(map_copy, x, y - 1, allow_exit))
		floodfill(x, y - 1, map, allow_exit);
}

char	**copy_map(char **map, int map_size, t_data *mlx)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (map_size + 1));
	if (!map_copy)
	{
		perror("Allocation fail ! : ");
		clean_and_exit(mlx);
	}
	i = 0;
	while (i < map_size)
	{
		map_copy[i] = malloc(ft_strlen(map[i]) + 1);
		if (!map_copy[i])
		{
			free_arr(map_copy, --i);
			clean_and_exit(mlx);
		}
		ft_memmove(map_copy[i], map[i], ft_strlen(map[i]) + 1);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	is_reached_all_element(char **map_copy, char element, t_data *mlx)
{
	int (i), (j), (found_element);
	found_element = 0;
	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == element)
				found_element = 1;
			j++;
		}
		i++;
	}
	if (found_element == 1)
	{
		ft_free(map_copy);
		if (element == 'C')
			put_error("Invalid Map : Player can't reach all Collectable!\n",
				mlx);
		else if (element == 'E')
			put_error("Invalid Map : Player can't reach exit door!\n", mlx);
	}
}

void	check_valid_path(t_data *mlx)
{
	get_player_position(mlx->map->map_grid, &mlx->player->x, &mlx->player->y);
	mlx->map->map_copy = copy_map(mlx->map->map_grid, mlx->map->map_height,
			mlx);
	floodfill(mlx->player->x, mlx->player->y, mlx->map, 0);
	is_reached_all_element(mlx->map->map_copy, 'C', mlx);
	ft_free(mlx->map->map_copy);
	mlx->map->map_copy = copy_map(mlx->map->map_grid, mlx->map->map_height,
			mlx);
	floodfill(mlx->player->x, mlx->player->y, mlx->map, 1);
	is_reached_all_element(mlx->map->map_copy, 'E', mlx);
	ft_free(mlx->map->map_copy);
}
