/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:10:29 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 13:06:01 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*This function is used in case of array allocation
if one's fail it will clean the previous allocations*/
void	free_arr(char **arr, int index)
{
	perror("Allocation fail for row ! : ");
	while (index >= 0)
		free(arr[index]);
	free(arr);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i++]);
	}
	free(map);
}

void	free_sprites_on_failure(t_data *mlx, t_image **sprites, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (sprites[i])
		{
			mlx_destroy_image(mlx->mlx_ptr, sprites[i]->img_ptr);
			free(sprites[i]);
			sprites[i] = NULL;
		}
		i++;
	}
}
