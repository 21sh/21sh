/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:11:33 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/18 18:46:14 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *dest, const char *src)
{
	int		a;
	int		b;
	char	*str;

	a = 0;
	b = 0;
	str = (char*)src;
	while (dest[a])
		a++;
	while (src[b])
	{
		dest[a] = str[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}
