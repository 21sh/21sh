/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:53:25 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/22 18:14:44 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	a;
	char	*str;

	a = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (0);
	while (a < size)
	{
		str[a] = '\0';
		a++;
	}
	str[a] = '\0';
	return (str);
}
