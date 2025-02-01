/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:53:37 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/31 16:27:32 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_and_exit(t_data *mlx)
{
	if (mlx->player)
		free(mlx->player);
	if (mlx->map && mlx->map->map_grid)
		ft_free(mlx->map->map_grid);
	if (mlx->map)
		free(mlx->map);
	if (mlx->buffer_img && mlx->buffer_img->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->buffer_img->img_ptr);
	if (mlx->buffer_img)
		free(mlx->buffer_img);
	if (mlx)
		free(mlx);
	exit(EXIT_FAILURE);
}
