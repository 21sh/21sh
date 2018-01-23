/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreejoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:00:02 by corosteg          #+#    #+#             */
/*   Updated: 2017/09/26 19:08:41 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strfreejoin(char *s1, char *s2, int z)
{
	int		a;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	a = (ft_strlen(s1) + ft_strlen(s2));
	str = (char*)malloc(sizeof(char) * (a + 1));
	if (str == 0)
		return (0);
	str[a] = '\0';
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (str == 0)
		return (0);
	if (z == 1)
		free(s1);
	if (z == 2)
		free(s2);
	if (z == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
