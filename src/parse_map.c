/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:57:45 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 15:42:34 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    read_map(const char *map_path, t_data *mlx)
{
    t_map *map;
    char    *temp;
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

void    check_rectangle(char **map, t_data *mlx)
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

void    is_not_wall(char c, t_data *mlx)
{
    if (c != '1')
        put_error("Invalid map: incorrect format.\n", mlx);
}

void    is_surrounded_by_wall(char **map, t_data *mlx)
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

void    count_elements(char element, t_data *mlx)
{
    if (element == 'P')
        mlx->map->found_player++;
    else if (element == 'E')
        mlx->map->found_exit++;
    else if (element == 'C')
        mlx->map->found_collect++;
}

void    check_elements(t_data *mlx)
{
    if (mlx->map->found_collect == 0)
        put_error("Invalid map: No Collectable found.\n", mlx);
    else if (mlx->map->found_exit == 0)
        put_error("Invalid map: No exit door found.\n", mlx);
    else if (mlx->map->found_exit > 1)
        put_error("Invalid map: only one exit door allowed.\n", mlx);
    else if (mlx->map->found_player == 0)
        put_error("Invalid map: no Player found.\n", mlx);
    else if (mlx->map->found_player > 1)
        put_error("Invalid map: only one Player allowed.\n", mlx);
}

void    is_valid_element(char **map, t_data *mlx)
{
    int (i), (j);
    mlx->map->found_collect = 0;
    mlx->map->found_player = 0;
    mlx->map->found_exit = 0;
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
                && map[i][j] != '0' && map[i][j] != '1')
            {
                put_error("Invalid map: invalid character.\n", mlx);
            }
            count_elements(map[i][j], mlx);
            j++;
        }
        i++;
    }
    check_elements(mlx);
}

void    parse_map(const char *map_path, t_data *mlx)
{
    read_map(map_path, mlx);
    check_rectangle(mlx->map->map_grid, mlx);
    is_surrounded_by_wall(mlx->map->map_grid, mlx);
    is_valid_element(mlx->map->map_grid, mlx);
    check_valid_path(mlx);
}
