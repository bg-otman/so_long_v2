/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:08:21 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:00:00 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_background(t_data *mlx)
{
	int (x), (y);
	if (!mlx->img_bg || !mlx->img_bg->img_ptr)
	{
		ft_printf("Background texture not loaded!\n");
		return ;
	}
	y = 0;
	while (y < mlx->window_height)
	{
		x = 0;
		while (x < mlx->window_width)
		{
			put_img_to_buffer(mlx->buffer_img, mlx->img_bg, x, y);
			x += mlx->img_bg->width;
		}
		y += mlx->img_bg->height;
	}
}
