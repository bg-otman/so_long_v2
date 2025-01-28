/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:54:27 by obouizi           #+#    #+#             */
/*   Updated: 2024/11/04 18:31:15 by obouizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s1);
	ptr = (char *) malloc(s_len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < s_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[s_len] = '\0';
	return (ptr);
}
