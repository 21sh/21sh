/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:35:27 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/12 21:13:52 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*stock_ll(long long nb, char c)
{
	if (c == 'd')
		return (ft_itoa((int)nb));
	return (0);
}

char		*stock_wstr(char *str, char c)
{
	if (c == 's')
		return (ft_strdup((char*)str));
	return (0);
}

char		*apply_list(char c, va_list ap)
{
	if (c == '%')
		return (ft_strdup("%"));
	if (ft_strchr(PRINT_LL, c))
		return (stock_ll(va_arg(ap, long long), c));
	if (ft_strchr("sS", c))
		return (stock_wstr(va_arg(ap, char*), c));
	return (ft_strdup("error print"));
}
