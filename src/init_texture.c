/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:23:28 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/27 15:56:50 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_texture(t_data *mlx, t_image **img, char *file_path)
{
    *img = malloc(sizeof(t_image));
    if (!*img)
        return (0);
    (*img)->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, file_path,
        &((*img)->width), &((*img)->height));
    if (!(*img)->img_ptr)
    {
        printf("Failed to load texture from %s\n", file_path);
        free(*img);
        *img = NULL;
        return (0);
    }
    (*img)->pixel_data = mlx_get_data_addr((*img)->img_ptr,
    &(*img)->bpp, &(*img)->line_size, &(*img)->endian);
    return (1);
}
