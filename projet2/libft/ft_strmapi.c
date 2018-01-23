/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:19:44 by paoroste          #+#    #+#             */
/*   Updated: 2016/11/24 18:30:42 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*s1;
	int				i;
	unsigned int	l;

	if (s == 0 || (*f) == 0)
		return (0);
	s1 = (char*)s;
	i = ft_strlen(s1);
	l = 0;
	str = (char*)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = f(l, s1[i]);
		i++;
		l++;
	}
	str[i] = '\0';
	return (str);
}
