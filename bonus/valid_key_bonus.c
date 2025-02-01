/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:34:13 by obouizi           #+#    #+#             */
/*   Updated: 2025/02/01 18:49:59 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_key(int key)
{
	if (key == LEFT || key == RIGHT || key == UP || key == DOWN
		|| key == D_KEY || key == S_KEY || key == A_KEY || key == W_KEY)
		return (1);
	return (0);
}
