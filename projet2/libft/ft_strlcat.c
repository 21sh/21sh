/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:03:59 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/23 14:55:05 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	if (ft_strlen(dest) < size)
		ft_strncat(dest, src, size - ft_strlen(dest) - 1);
	if ((ft_strlen(src) + size) < (ft_strlen(src) + ft_strlen(dest)))
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + ft_strlen(dest));
}
