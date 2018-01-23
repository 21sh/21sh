/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_left.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:28:25 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/16 16:56:42 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int					p_left(t_shell *info)
{
	struct winsize		screen;

	info->x--;
	ioctl(0, TIOCGWINSZ, &screen);
	if (info->x < 0)
	{
		info->y--;
		info->x = 0;
		tputs(tgetstr("up", NULL), 1, ft_putchar);
		while (info->x <= screen.ws_col)
		{
			tputs(tgetstr("nd", NULL), 1, ft_putchar);
			info->x++;
		}
		info->x = screen.ws_col - 1;
	}
	else
		tputs(tgetstr("le", NULL), 1, ft_putchar);
	info->len--;
	return (0);
}
