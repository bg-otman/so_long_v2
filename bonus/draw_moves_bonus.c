/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:42:55 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 15:43:11 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_move_count(t_data *mlx)
{
	char	*moves_count;
	int		x;
	int		i;
	int		digit;

	moves_count = ft_itoa(mlx->player->moves_count);
	if (!moves_count)
	{
		perror("Alocation fail ! : ");
		close_window(mlx);
		return ;
	}
	put_img_to_buffer(mlx->buffer_img, mlx->moves_str, 100, 20);
	x = 400;
	i = 0;
	while (moves_count[i])
	{
		digit = moves_count[i] - '0';
		if (digit >= 0 && digit <= 9)
			put_img_to_buffer(mlx->buffer_img, mlx->digits[digit], x, 20);
		x += mlx->digits[digit]->width;
		i++;
	}
	free(moves_count);
}
