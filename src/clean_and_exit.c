/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:53:37 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/27 09:38:32 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    clean_and_exit(t_data *mlx)
{
    if (mlx->player)
        free(mlx->player);
    if (mlx->map && mlx->map->map_grid)
		ft_free(mlx->map->map_grid);
    if (mlx->map)
        free(mlx->map);
    if (mlx)
        free(mlx);
    exit(EXIT_FAILURE);
}
