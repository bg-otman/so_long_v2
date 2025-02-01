/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:01:45 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:04:33 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	read_map(const char *map_path, t_data *mlx)
{
	t_map	*map;
	char	*temp;

	int (fd), (i);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening map file");
		clean_and_exit(mlx);
	}
	map = mlx->map;
	i = 0;
	while (i < map->map_height)
	{
		temp = get_next_line(fd);
		map->map_grid[i] = ft_strtrim(temp, "\n");
		if (temp)
			free(temp);
		if (!map->map_grid[i])
			free_arr(map->map_grid, --i);
		i++;
	}
	map->map_grid[i] = NULL;
	free_static(fd);
	close(fd);
}
