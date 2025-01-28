/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:12:45 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/28 16:16:27 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    draw_door(t_data *mlx, int posX, int posY)
{
    if (!mlx->door || !mlx->door->img_ptr)
    {
        printf("door texture not loaded!\n");
        return ;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->door->img_ptr, posX, posY);
}