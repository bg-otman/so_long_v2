/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:32:56 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 15:43:21 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int count_valid_lines(int fd)
{
    char *buffer;
    int line_count;
    
    line_count = 0;
    buffer = get_next_line(fd);
    while (buffer)
    {
        if (*buffer == '\n')
        {
            free(buffer);
            break ;
        }
        line_count++;
        free(buffer);
        buffer = get_next_line(fd);
    }
    return (line_count);
}

static int validate_trailing_lines(int fd)
{
    char *buffer;

    buffer = get_next_line(fd);
    while (buffer)
    {
        if (*buffer != '\n')
        {
            free(buffer);
            return (-1);
        }
        free(buffer);
        buffer = get_next_line(fd);
    }
    return (0);
}

int map_len(const char *map_path)
{
    int fd;
    int line_count;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        return (-1);
    line_count = count_valid_lines(fd);
    if (line_count == 0 || validate_trailing_lines(fd) == -1)
    {
        free_static(fd);
        close(fd);
        return (-1);
    }
    close(fd);
    return (line_count);
}

void    system_error(char *error_msg, t_data *mlx, int fd)
{
    perror(error_msg);
    if (fd != -1)
        close(fd);
    clean_and_exit(mlx);
}

void    process_map(const char *map_path, t_data *mlx)
{
    int fd;
    t_map *map;
    
    if (ft_strncmp(&map_path[ft_strlen(map_path) - 4], ".ber", 4))
    {
        put_error("Only files with \".ber\" extention allowed!\n", mlx);
    }
    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        system_error("Error opening map file : ", mlx, fd);
    map = mlx->map;
    map->map_height = map_len(map_path);
    if (map->map_height < 3)
    {
        close(fd);
        put_error("Invalid map: incorrect format.\n", mlx);
    }
    map->map_grid = malloc(sizeof(char *) * (map->map_height + 1));
    if (!map->map_grid)
        system_error("Allocation failed for map grid!", mlx, fd);
    close(fd);
}
