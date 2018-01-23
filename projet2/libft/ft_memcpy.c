/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:46:01 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/23 15:54:05 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			nb;
	unsigned char	*ptr;
	unsigned char	*adr;

	ptr = (unsigned char*)dest;
	adr = (unsigned char*)src;
	nb = 0;
	while (nb < n)
	{
		ptr[nb] = adr[nb];
		nb++;
	}
	return (ptr);
}
