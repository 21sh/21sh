/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 20:44:52 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/23 14:43:32 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*ptr;
	size_t			a;

	ptr = (char*)s;
	a = 0;
	while (a < n)
	{
		if (ptr[a] == (char)c)
			return (&ptr[a]);
		a++;
	}
	return (0);
}
