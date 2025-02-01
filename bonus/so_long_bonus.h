/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:26:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 16:17:10 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define NUM_SPRITE 17
# define E_NUM_SPRITES 16

typedef struct s_map
{
	char		**map_grid;
	char		**map_copy;
	int			map_width;
	int			map_height;
	int			found_player;
	int			found_exit;
	int			found_collect;
}				t_map;

typedef struct s_image
{
	void		*img_ptr;
	char		*pixel_data;
	int			bpp;
	int			endian;
	int			line_size;
	int			width;
	int			height;
}				t_image;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			width;
	int			height;
	t_image		*sprites[E_NUM_SPRITES];
}				t_enemy;

typedef struct s_player
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			speed;
	int			moves_count;
	int			look_right;
	t_image		*sprites_right[NUM_SPRITE];
	t_image		*sprites_left[NUM_SPRITE];
}				t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			window_width;
	int			window_height;
	int			collectable_count;
	int			enemy_count;
	int			collect_all;
	int			exit_status;
	int			frame;
	t_image		*obstacle;
	t_image		*collect;
	t_image		*door_close;
	t_image		*door_open;
	t_image		*img_wall;
	t_image		*img_bg;
	t_image		*buffer_img;
	t_player	*player;
	t_image		*digits[10];
	t_image		*moves_str;
	t_enemy		*enemy;
	t_map		*map;
}				t_data;

void			draw_background(t_data *mlx);
void			draw_wall(t_data *mlx);
void			draw_all(t_data *mlx);
void			draw_obstacle(t_data *mlx, int posX, int posY);
void			draw_img(t_data *mlx, t_image *img, int posX, int posY);
void			move_player(int key, t_data *mlx);
void			get_player_position(char **map, int *playerX, int *playerY);
void			free_static(int fd);
void			put_error(char *error_msg, t_data *mlx);
void			put_img_to_buffer(t_image *dst, t_image *src, int x, int y);
void			put_pixel_to_buffer(t_image *img, int x, int y, int color);
void			check_valid_path(t_data *mlx);
void			clean_and_exit(t_data *mlx);
void			init_player_data(t_data *mlx);
void			init_data(t_data *mlx);
void			game_over(t_data *mlx, int win);
void			init_buffer_img(t_data *mlx);
void			load_imgs(t_data *mlx);
void			process_map(const char *map_path, t_data *mlx);
void			parse_map(const char *map_path, t_data *mlx);
void			read_map(const char *map_path, t_data *mlx);
void			is_valid_element(char **map, t_data *mlx);
void			ft_free(char **map);
void			free_arr(char **arr, int index);
void			free_sprites_on_failure(t_data *mlx, t_image **sprites,
					int count);
void			enemy_collision(t_data *mlx, char **map);
void			draw_enemy(t_data *mlx, int x, int y);
void			display_move_count(t_data *mlx);
void			draw_player(t_data *mlx, int x, int y);
void			count_elements(char element, t_data *mlx);
int				init_texture(t_data *mlx, t_image **img, char *file_path);
int				close_window(t_data *mlx);
int				is_valid_key(int key);

#endif