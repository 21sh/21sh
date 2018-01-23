/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:34:49 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/23 19:14:20 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (s == 0 || (*f) == 0)
		return (0);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	ft_strcpy(str, s);
	while (str[i])
	{
		str[i] = (*f)(str[i]);
		i++;
	}
	return (str);
}
