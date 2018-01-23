/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 17:37:43 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/12 21:12:48 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			print(char *final)
{
	int		b;

	ft_putstr(final);
	b = ft_strlen(final);
	free(final);
	final = NULL;
	return (b);
}

int			check_for_apply(const char *format, va_list ap, int a, int b)
{
	char	*str;

	str = ft_strdup("sSpdDioOuUxXcC%");
	while (format[b])
	{
		while (str[a])
		{
			if (format[b] == str[a])
			{
				free(str);
				return (print(apply_list(format[b], ap)));
			}
			a++;
		}
		a = 0;
		b++;
	}
	return (0);
}

int			rest(const char *format, int i)
{
	int		a;
	char	*str;
	char	*flags;

	a = 0;
	str = ft_strdup(format);
	flags = ft_strdup("sSpdDioOuUxXcC%");
	while (str[i] == ' ' || str[i] == '0' || str[i] == '-' || str[i] == '+'
			|| str[i] == '#' || str[i] == 'h' || str[i] == 'l' ||
			str[i] == 'j' || str[i] == 'z' || (str[i] > '0' && str[i] < '9'))
		i++;
	if (str[i] == '\0')
		return (i);
	while (flags[a])
	{
		if (str[i] == flags[a])
		{
			i++;
			break ;
		}
		a++;
	}
	free(str);
	free(flags);
	return (i);
}

int			ft_print(const char *format, ...)
{
	int			i;
	int			ret;
	va_list		ap;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] == '%')
		{
			ret = (ret + check_for_apply(&format[i + 1], ap, 0, 0));
			i = (i + (rest(&format[i + 1], 0)) + 1);
		}
		if (format[i] == '\0')
			break ;
		ft_putchar(format[i]);
		ret++;
		i++;
	}
	return (ret);
}
