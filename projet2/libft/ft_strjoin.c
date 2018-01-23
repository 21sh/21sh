/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:17:05 by corosteg          #+#    #+#             */
/*   Updated: 2017/06/07 17:25:53 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (0);
	a = (ft_strlen(s1) + ft_strlen(s2));
	str = (char*)malloc(sizeof(char) * (a + 1));
	if (str == 0)
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (str == 0)
		return (0);
	return (str);
}
