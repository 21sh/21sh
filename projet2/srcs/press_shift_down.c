/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_shift_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:28:39 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/06 17:42:29 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				p_s_down(t_shell *info)
{
	int					x_goal;
	int					y_goal;

	x_goal = info->x;
	y_goal = info->y + 1;
	while (info->command[info->len] && (x_goal > info->x ||
				y_goal > info->y))
		p_right(info);
}
