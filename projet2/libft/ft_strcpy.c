/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:55:55 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/18 16:51:02 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int		a;
	char	*str;
	char	*str2;

	a = 0;
	str = (char*)dest;
	str2 = (char*)src;
	while (str2[a])
	{
		str[a] = str2[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}
