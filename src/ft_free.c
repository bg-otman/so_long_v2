/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <obouizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:10:29 by obouizi           #+#    #+#             */
/*   Updated: 2025/01/27 10:14:00 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This function is used in case of array allocation
if one's fail it will clean the previous allocations*/
void    free_arr(char **arr, int index)
{
    perror("Allocation fail for row ! : ");
    while (index >= 0)
        free(arr[index]);
    free(arr);
}

void 	ft_free(char **map)
{
	int i;
	
	i = 0;
	while (map[i])
	{
		free(map[i++]);
	}
	free(map);	
}
