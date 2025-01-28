/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:45:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/28 17:51:05 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(t_data *mlx, t_image **img, int posX, int posY)
{
	unsigned int	color;

	int(pxl_x), (pxl_y), (pixel_index);
	if (!*img || !(*img)->img_ptr)
	{
		printf("texture not loaded!\n");
		return ;
	}
	pxl_y = 0;
	while (pxl_y < (*img)->height)
	{
		pxl_x = 0;
		while (pxl_x < (*img)->width)
		{
			pixel_index = pxl_y * (*img)->line_size + pxl_x * ((*img)->bpp / 8);
			color = *(unsigned int *)((*img)->pixel_data + pixel_index);
			if (color != 0xFF000000)
			{
				mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, posX + pxl_x,
                    posY + pxl_y, color);
			}
			pxl_x++;
		}
		pxl_y++;
	}
}
