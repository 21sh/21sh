/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:20:21 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/22 22:26:06 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*str;

	a = 0;
	str = (char*)s;
	while (str[a])
	{
		if (str[a] == (char)c)
			return (&str[a]);
		a++;
	}
	if (str[a] == (char)c)
		return (&str[a]);
	return (0);
}
