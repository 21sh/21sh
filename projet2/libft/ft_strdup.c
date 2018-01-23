/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:12:05 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/26 23:35:20 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		a;
	char	*str;

	if (s == NULL)
		return (NULL);
	a = ft_strlen(s);
	str = (char*)malloc(sizeof(char) * (a + 1));
	if (str == 0)
		return (0);
	ft_strcpy(str, s);
	str[a] = '\0';
	return (str);
}
