/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:03:46 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/18 18:20:33 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	tmp[n];
	unsigned char	*srcs;
	size_t			i;

	dst = (unsigned char*)dest;
	srcs = (unsigned char*)src;
	i = 0;
	if ((char)n == '\0')
		return (&dst[n]);
	while (i < n)
	{
		tmp[i] = srcs[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dst[i] = tmp[i];
		i++;
	}
	return (dst);
}
