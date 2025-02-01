/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:05:55 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/31 15:51:35 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_error(char *error_msg, t_data *mlx)
{
	ft_putstr_fd(error_msg, 2);
	clean_and_exit(mlx);
}
