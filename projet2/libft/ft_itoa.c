/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paoroste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:48:25 by paoroste          #+#    #+#             */
/*   Updated: 2017/05/31 16:41:07 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*n_is_positive(int nbr, int i)
{
	char	*str;

	str = (char*)malloc(sizeof(str) * (i));
	if (str == 0)
		return (0);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

static char		*n_is_negative(int nbr, int i)
{
	char	*str;

	i = i + 2;
	str = (char*)malloc(sizeof(str) * i);
	if (str == 0)
		return (0);
	str[i] = '\0';
	i--;
	while (i > 0)
	{
		str[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	str[i] = '-';
	return (str);
}

static char		*ft_min(void)
{
	char	*str;

	str = ft_strdup("-2147483648");
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	int		nb;
	int		np;

	i = 0;
	nb = n;
	np = 0;
	if (n == -2147483648)
		return (ft_min());
	if (n < 0)
	{
		nb = nb * -1;
		n = n * -1;
		np = 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (np == 1)
		return (n_is_negative(nb, i));
	else
		return (n_is_positive(nb, i));
}
