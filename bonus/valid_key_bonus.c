/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:34:13 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/31 15:51:50 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_key(int key)
{
	if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down
		|| key == XK_d || key == XK_s || key == XK_a || key == XK_w)
		return (1);
	return (0);
}
