/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:57:13 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/24 16:15:17 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim(char *str, char *final)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		final[b] = str[i];
		b++;
		i++;
	}
	while (final[b - 1] == ' ' || final[b - 1] == '\t' || final[b - 1] == '\n')
		b--;
	final[b] = '\0';
	return (final);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	char	*final;

	if (s == 0)
		return (0);
	str = ft_strdup(s);
	if (str == 0)
		return (0);
	ft_strcpy(str, s);
	final = ft_strdup(str);
	if (final == 0)
		return (0);
	ft_trim(str, final);
	ft_strdup(final);
	if (final == 0)
		return (0);
	return (final);
}
