/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_static.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:57:48 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/26 10:59:01 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*All this function doing is just freeing 
the remaining data in the static variable*/
void	free_static(int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
	}
}
