/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:12:24 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 15:36:41 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_image(t_data *mlx, t_image *img)
{
	if (img && img->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	if (img)
		free(img);
}

static void	free_sprites(t_data *mlx, t_image **sprites, int num_sprites)
{
	int	i;

	i = 0;
	while (i < num_sprites)
	{
		if (sprites[i])
		{
			if (sprites[i]->img_ptr)
				mlx_destroy_image(mlx->mlx_ptr, sprites[i]->img_ptr);
			free(sprites[i]);
			sprites[i] = NULL;
		}
		i++;
	}
}

static void	free_imgs(t_data *mlx)
{
	destroy_image(mlx, mlx->img_wall);
	destroy_image(mlx, mlx->img_bg);
	destroy_image(mlx, mlx->obstacle);
	destroy_image(mlx, mlx->collect);
	destroy_image(mlx, mlx->door_close);
	destroy_image(mlx, mlx->door_open);
	destroy_image(mlx, mlx->moves_str);
	destroy_image(mlx, mlx->buffer_img);
}

static void	free_ressources(t_data *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free_imgs(mlx);
	if (mlx->player && mlx->player->sprites_right)
		free_sprites(mlx, mlx->player->sprites_right, NUM_SPRITE);
	if (mlx->player && mlx->player->sprites_left)
		free_sprites(mlx, mlx->player->sprites_left, NUM_SPRITE);
	if (mlx->player)
		free(mlx->player);
	if (mlx->enemy && mlx->enemy->sprites)
		free_sprites(mlx, mlx->enemy->sprites, E_NUM_SPRITES);
	if (mlx->enemy)
		free(mlx->enemy);
	if (mlx->digits)
		free_sprites(mlx, mlx->digits, 10);
	if (mlx->map && mlx->map->map_grid)
		ft_free(mlx->map->map_grid);
	if (mlx->map)
		free(mlx->map);
}

int	close_window(t_data *mlx)
{
	int	exit_status;

	exit_status = mlx->exit_status;
	free_ressources(mlx);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	free(mlx);
	exit(exit_status);
}
