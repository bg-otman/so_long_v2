/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:57:45 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/30 16:17:13 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(char **map, t_data *mlx)
{
	int (i), (first_line), (current_line);
	first_line = ft_strlen(map[0]);
	i = 1;
	while (i < mlx->map->map_height)
	{
		current_line = ft_strlen(map[i]);
		if (first_line != current_line)
			put_error("Invalid map: incorrect format.\n", mlx);
		i++;
	}
	mlx->map->map_width = first_line;
}

void	is_not_wall(char c, t_data *mlx)
{
	if (c != '1')
		put_error("Invalid map: incorrect format.\n", mlx);
}

void	is_surrounded_by_wall(char **map, t_data *mlx)
{
	int (i), (j);
	j = 0;
	while (map[0][j])
		is_not_wall(map[0][j++], mlx);
	i = 1;
	while (map[i])
	{
		is_not_wall(map[i][0], mlx);
		is_not_wall(map[i][mlx->map->map_width - 1], mlx);
		i++;
	}
	j = 0;
	while (map[mlx->map->map_height - 1][j])
		is_not_wall(map[mlx->map->map_height - 1][j++], mlx);
}

void	count_elements(char element, t_data *mlx)
{
	if (element == 'P')
		mlx->map->found_player++;
	else if (element == 'E')
		mlx->map->found_exit++;
	else if (element == 'C')
		mlx->map->found_collect++;
}

void	parse_map(const char *map_path, t_data *mlx)
{
	read_map(map_path, mlx);
	check_rectangle(mlx->map->map_grid, mlx);
	is_surrounded_by_wall(mlx->map->map_grid, mlx);
	is_valid_element(mlx->map->map_grid, mlx);
	check_valid_path(mlx);
}
