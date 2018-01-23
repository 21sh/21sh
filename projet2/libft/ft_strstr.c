/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:19:53 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/24 18:14:12 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	char	*str;
	char	*dest;
	int		i;
	int		f;

	i = 0;
	dest = (char*)src;
	str = (char*)to_find;
	if (str[0] == '\0')
		return (dest);
	while (dest[i] != '\0')
	{
		f = 0;
		if (dest[i] == str[f])
		{
			while (dest[f] != '\0' && dest[i + f] == str[f])
			{
				f++;
				if (str[f] == '\0')
					return (&dest[i]);
			}
		}
		i++;
	}
	return (0);
}
