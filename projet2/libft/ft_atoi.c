/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:59:37 by paoroste          #+#    #+#             */
/*   Updated: 2017/05/30 13:12:58 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		entier;
	int		what;
	int		i;

	entier = 0;
	what = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		what = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		entier = entier * 10;
		entier = entier + (str[i] - '0');
		i++;
	}
	if (what == 1)
		return (-entier);
	else
		return (entier);
}
