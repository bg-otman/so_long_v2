/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:23:28 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:01:29 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_player_data(t_data *mlx)
{
	mlx->player->speed = 80;
	mlx->player->moves_count = 0;
	mlx->player->look_right = 1;
	mlx->player->height = mlx->player->sprites_left[0]->height;
	mlx->player->width = mlx->player->sprites_right[0]->width;
	mlx->player->x *= mlx->img_wall->width;
	mlx->player->y *= mlx->img_wall->height;
}

static void	allocate_characters(t_data *mlx)
{
	mlx->player = malloc(sizeof(t_player));
	if (!mlx->player)
	{
		free(mlx);
		perror("player allocation fail :");
		exit(EXIT_FAILURE);
	}
	mlx->enemy = malloc(sizeof(t_enemy));
	if (!mlx->enemy)
	{
		free(mlx->player);
		free(mlx);
		perror("enemy allocation fail :");
		exit(EXIT_FAILURE);
	}
}

void	init_data(t_data *mlx)
{
	allocate_characters(mlx);
	mlx->map->map_grid = NULL;
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->buffer_img = NULL;
	mlx->obstacle = NULL;
	mlx->collect = NULL;
	mlx->door_close = NULL;
	mlx->door_open = NULL;
	mlx->img_wall = NULL;
	mlx->img_bg = NULL;
	mlx->collect_all = 0;
	mlx->frame = 0;
	mlx->enemy_count = 0;
	mlx->exit_status = EXIT_SUCCESS;
}

void	init_buffer_img(t_data *mlx)
{
	mlx->window_width = mlx->map->map_width * mlx->img_wall->width;
	mlx->window_height = mlx->map->map_height * mlx->img_wall->height;
	mlx->buffer_img = malloc(sizeof(t_image));
	if (!mlx->buffer_img)
	{
		perror("Allocation failed for buffer_img structure! :");
		close_window(mlx);
	}
	mlx->buffer_img->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->window_width,
			mlx->window_height);
	if (!mlx->buffer_img->img_ptr)
	{
		perror("Failed to create buffer image!");
		mlx->exit_status = EXIT_FAILURE;
		close_window(mlx);
	}
	mlx->buffer_img->pixel_data = mlx_get_data_addr(
			mlx->buffer_img->img_ptr, &mlx->buffer_img->bpp,
			&mlx->buffer_img->line_size, &mlx->buffer_img->endian);
	mlx->buffer_img->width = mlx->window_width;
	mlx->buffer_img->height = mlx->window_height;
}

int	init_texture(t_data *mlx, t_image **img, char *file_path)
{
	*img = malloc(sizeof(t_image));
	if (!*img)
	{
		perror("Allocation failed for Texture!: ");
		mlx->exit_status = EXIT_FAILURE;
		return (0);
	}
	(*img)->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, file_path,
			&((*img)->width), &((*img)->height));
	if (!(*img)->img_ptr)
	{
		ft_printf("Failed to load texture from %s\n", file_path);
		free(*img);
		*img = NULL;
		mlx->exit_status = EXIT_FAILURE;
		return (0);
	}
	(*img)->pixel_data = mlx_get_data_addr((*img)->img_ptr, &(*img)->bpp,
			&(*img)->line_size, &(*img)->endian);
	return (1);
}
