/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:45:59 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:00:26 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_player(t_data *mlx, int x, int y)
{
	int	sprite_index;

	sprite_index = (mlx->frame / 10) % NUM_SPRITE;
	if (mlx->player->look_right)
		put_img_to_buffer(mlx->buffer_img,
			mlx->player->sprites_right[sprite_index], x, y);
	else
		put_img_to_buffer(mlx->buffer_img,
			mlx->player->sprites_left[sprite_index], x, y);
}

void	draw_img(t_data *mlx, t_image *img, int posX, int posY)
{
	unsigned int	color;
	char			*pixel_src;

	int (pxl_x), (pxl_y);
	if (!img || !img->img_ptr)
	{
		ft_printf("Texture not loaded!\n");
		return ;
	}
	pxl_y = 0;
	while (pxl_y < img->height)
	{
		pxl_x = 0;
		while (pxl_x < img->width)
		{
			pixel_src = img->pixel_data + (pxl_y * img->line_size + pxl_x
					* (img->bpp / 8));
			color = *(unsigned int *)pixel_src;
			if (color != 0xFF000000)
				put_pixel_to_buffer(mlx->buffer_img, posX + pxl_x, posY + pxl_y,
					color);
			pxl_x++;
		}
		pxl_y++;
	}
}
