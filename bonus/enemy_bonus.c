/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:39:29 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:03:34 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_collision(t_data *mlx, char **map)
{
	int (i), (j), (enemy_num);
	i = 0;
	enemy_num = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				enemy_num++;
			j++;
		}
		i++;
	}
	if (enemy_num < mlx->enemy_count)
		game_over(mlx, 0);
}

void	draw_enemy(t_data *mlx, int x, int y)
{
	int	sprite_index;

	sprite_index = (mlx->frame / 10) % E_NUM_SPRITES;
	put_img_to_buffer(mlx->buffer_img, mlx->enemy->sprites[sprite_index], x, y);
}
