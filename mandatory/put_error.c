/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:05:55 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/29 15:45:25 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error(char *error_msg, t_data *mlx)
{
	ft_putstr_fd(error_msg, 2);
	clean_and_exit(mlx);
}
