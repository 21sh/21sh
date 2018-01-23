/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:24:27 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/23 14:40:41 by paoroste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *s1, const char *to_find, size_t len)
{
	size_t	i;
	size_t	f;
	size_t	tmp;

	i = 0;
	if (((char*)to_find)[0] == '\0')
		return (((char*)s1));
	while (((char*)s1)[i] != '\0' && len > 0)
	{
		f = 0;
		tmp = len;
		if (((char*)s1)[i] == ((char*)to_find)[f])
			while (((char*)s1)[f] != '\0' && ((char*)s1)[i + f] ==
				((char*)to_find)[f] && len > 0)
			{
				f++;
				len--;
				if (((char*)to_find)[f] == '\0')
					return (&((char*)s1)[i]);
			}
		len = tmp;
		len--;
		i++;
	}
	return (0);
}
