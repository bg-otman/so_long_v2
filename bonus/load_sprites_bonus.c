/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:02:04 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:03:20 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy_sprites(t_data *mlx)
{
	int		i;
	char	path[40];
	char	*num;

	i = 0;
	while (i < E_NUM_SPRITES)
	{
		num = ft_itoa(i);
		if (!num)
		{
			free_sprites_on_failure(mlx, mlx->enemy->sprites, i);
			close_window(mlx);
		}
		ft_strlcpy(path, "assets/enemy_sprites/enemy_", sizeof(path));
		ft_strlcat(path, num, sizeof(path));
		ft_strlcat(path, ".xpm", sizeof(path));
		if (!init_texture(mlx, &(mlx->enemy->sprites[i]), path))
		{
			free(num);
			free_sprites_on_failure(mlx, mlx->enemy->sprites, i);
			close_window(mlx);
		}
		free(num);
		i++;
	}
}

void	load_player_sprites(t_data *mlx, t_image **sprites, char *path)
{
	int		i;
	char	full_path[50];
	char	*num;

	i = 0;
	while (i < NUM_SPRITE)
	{
		num = ft_itoa(i);
		if (!num)
		{
			free_sprites_on_failure(mlx, sprites, i);
			close_window(mlx);
		}
		ft_strlcpy(full_path, path, sizeof(full_path));
		ft_strlcat(full_path, num, sizeof(full_path));
		ft_strlcat(full_path, ".xpm", sizeof(full_path));
		if (!init_texture(mlx, &(sprites[i]), full_path))
		{
			free(num);
			free_sprites_on_failure(mlx, sprites, i);
			close_window(mlx);
		}
		free(num);
		i++;
	}
}

void	load_digits_sprites(t_data *mlx)
{
	int		i;
	char	full_path[30];
	char	*num;

	i = 0;
	while (i < 10)
	{
		num = ft_itoa(i);
		if (!num)
		{
			free_sprites_on_failure(mlx, mlx->digits, i);
			close_window(mlx);
		}
		ft_strlcpy(full_path, "assets/digits_sprites/", sizeof(full_path));
		ft_strlcat(full_path, num, sizeof(full_path));
		ft_strlcat(full_path, ".xpm", sizeof(full_path));
		if (!init_texture(mlx, &(mlx->digits[i]), full_path))
		{
			free(num);
			free_sprites_on_failure(mlx, mlx->digits, i);
			close_window(mlx);
		}
		free(num);
		i++;
	}
}

void	load_sprites(t_data *mlx)
{
	load_player_sprites(mlx, mlx->player->sprites_right,
		"assets/warrior_sprites/right/w_");
	load_player_sprites(mlx, mlx->player->sprites_left,
		"assets/warrior_sprites/left/w_left_");
	load_enemy_sprites(mlx);
	load_digits_sprites(mlx);
}

void	load_imgs(t_data *mlx)
{
	load_sprites(mlx);
	if (!init_texture(mlx, &(mlx->img_bg), "assets/bg.xpm")
		|| !init_texture(mlx, &(mlx->img_wall), "assets/wall.xpm")
		|| !init_texture(mlx, &(mlx->obstacle), "assets/box_grey.xpm")
		|| !init_texture(mlx, &(mlx->collect), "assets/coin_skull.xpm")
		|| !init_texture(mlx, &(mlx->door_close), "assets/gate_closed.xpm")
		|| !init_texture(mlx, &(mlx->door_open), "assets/gate_open.xpm")
		|| !init_texture(mlx, &(mlx->moves_str),
			"assets/digits_sprites/moves_str.xpm"))
		close_window(mlx);
}
