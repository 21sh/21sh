/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_shift_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:28:19 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/06 17:42:14 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void		p_s_up(t_shell *info)
{
	int					x_goal;
	int					y_goal;

	x_goal = info->x;
	y_goal = info->y - 1;
	while (info->len > 0 && (x_goal < info->x ||
				y_goal < info->y))
		p_left(info);
}
