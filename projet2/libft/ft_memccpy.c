/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:01:24 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/28 20:44:25 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str;
	char	*srcs;
	size_t	i;

	str = (char*)dest;
	srcs = (char*)src;
	i = 0;
	while (i < n)
	{
		str[i] = srcs[i];
		if (str[i] == (char)c)
		{
			i++;
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
