/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:12:24 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 22:13:20 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_imgs(t_data *mlx, t_image *img)
{
	if (img && img->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, img->img_ptr);
	if (img)
		free(img);
}

int	close_window(t_data *mlx)
{
	int	exit_status;

	exit_status = mlx->exit_status;
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	free_imgs(mlx, mlx->img_wall);
	free_imgs(mlx, mlx->img_bg);
	free_imgs(mlx, mlx->obstacle);
	free_imgs(mlx, mlx->collect);
	free_imgs(mlx, mlx->door_close);
	free_imgs(mlx, mlx->door_open);
	free_imgs(mlx, mlx->player->img);
	free(mlx->player);
	free_imgs(mlx, mlx->buffer_img);
	if (mlx->map && mlx->map->map_grid)
		ft_free(mlx->map->map_grid);
	if (mlx->map)
		free(mlx->map);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	free(mlx);
	exit(exit_status);
}
