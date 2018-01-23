/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:28:09 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/06 17:55:44 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				p_right(t_shell *info)
{
	struct winsize		screen;

	info->x++;
	ioctl(0, TIOCGWINSZ, &screen);
	if (info->x > screen.ws_col - 1)
	{
		info->x = 0;
		tputs(tgetstr("do", NULL), 1, ft_putchar);
		tputs(tgetstr("cr", NULL), 1, ft_putchar);
		info->len++;
		info->y++;
	}
	else
	{
		tputs(tgetstr("nd", NULL), 1, ft_putchar);
		info->len++;
	}
}
