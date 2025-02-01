/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_buffer_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 21:12:30 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:04:24 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_pixel_to_buffer(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		dst = img->pixel_data + (y * img->line_size + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_pixel_color(t_image *img, int x, int y)
{
	return (*(unsigned int *)((img->pixel_data + (y * img->line_size) + (x
				* img->bpp / 8))));
}

void	put_img_to_buffer(t_image *buffer_img, t_image *img, int x, int y)
{
	int	i;
	int	j;

	if (!img || !buffer_img)
		return ;
	j = 0;
	while (j < img->height)
	{
		i = 0;
		while (i < img->width)
		{
			put_pixel_to_buffer(buffer_img, x + i, y + j, get_pixel_color(img,
					i, j));
			i++;
		}
		j++;
	}
}
