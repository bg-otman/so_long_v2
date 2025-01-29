/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:26:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 10:29:47 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// # ifndef WINDOW_HEIGHT
// #  define WINDOW_HEIGHT 600
// # endif

// # ifndef WINDOW_WIDTH
// #  define WINDOW_WIDTH 1500
// # endif

typedef struct s_map
{
    char    **map_grid;
    int     map_width;
    int     map_height;
    int     found_player;
    int     found_exit;
    int     found_collect;
}       t_map;

typedef struct s_image
{
    void    *img_ptr;
    char    *pixel_data;
    int     bpp;
    int     endian;
    int     line_size;
    int     width;
    int     height;
}			t_image;

typedef struct s_player
{
	int		x;
	int		y;
    int     width;
    int     height;
    int     speed;
    t_image *img;
}			t_player;

typedef struct s_data
{
	void	    *mlx_ptr;
	void	    *win_ptr;
    int         WINDOW_WIDTH;
    int         WINDOW_HEIGHT;
    int         exit_status;
    t_image     *obstacle;
    t_image     *collect;
    t_image     *door;
    t_image     *img_wall;
    t_image     *img_bg;
    t_image     *buffer_img;
    t_player    *player;
    t_map       *map;
}			t_data;

void    draw_background(t_data *mlx);
void    draw_wall(t_data *mlx);
void    draw_player(t_data *mlx);
void    draw_all(t_data *mlx);
void    draw_obstacle(t_data *mlx, int posX, int posY);
void    draw_collectable(t_data *mlx, int posX, int posY);
void    draw_door(t_data *mlx, int posX, int posY);
void	draw_img(t_data *mlx, t_image *img, int posX, int posY);
void    move_player(int key, t_data *mlx);
void    get_player_position(char **map, int *playerX, int *playerY);
void    free_static(int fd);
void    put_error(char *error_msg, t_data *mlx);
void    put_img_to_buffer(t_image *dst, t_image *src, int x, int y);
void	put_pixel_to_buffer(t_image *img, int x, int y, int color);
void    check_valid_path(t_data *mlx);
void    clean_and_exit(t_data *mlx);
int     close_window(t_data *mlx);
int     is_valid_key(int key);
int     init_texture(t_data *mlx, t_image **img, char *file_path);
void    process_map(const char *map_path, t_data *mlx);
void    parse_map(const char *map_path, t_data *mlx);
void 	ft_free(char **map);
void    free_arr(char **arr, int index);

#endif