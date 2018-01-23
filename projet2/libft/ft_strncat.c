/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:01:35 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/21 14:07:59 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	a;
	char	*str;
	size_t	b;

	a = 0;
	b = 0;
	str = (char*)src;
	while (dest[a])
		a++;
	while (src[b] && b < n)
	{
		dest[a] = str[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}
