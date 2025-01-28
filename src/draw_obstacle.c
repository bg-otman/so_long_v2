/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obstacle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:55:57 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/27 15:38:44 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_obstacle(t_data *mlx, int posX, int posY)
{
    if (!mlx->obstacle || !mlx->obstacle->img_ptr)
    {
        printf("Background texture not loaded!\n");
        return ;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->obstacle->img_ptr, posX, posY);
}
