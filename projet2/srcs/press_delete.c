/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:12:07 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/16 17:18:09 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void		modify_string(t_shell *info)
{
	char	*str;
	char	*tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (info->command[info->len] != '\0')
	{
		tmp = info->command;
		str = (char*)malloc(sizeof(char) * ft_strlen(info->command));
		str[ft_strlen(info->command) - 1] = '\0';
		while (info->command[i])
		{
			if (i == info->len)
				i++;
			if (info->command[i] == '\0')
				break ;
			str[a] = info->command[i];
			i++;
			a++;
		}
		info->command = str;
		free(tmp);
	}
}

void			p_quote_delete(t_shell *info)
{
	int		cursor;

	cursor = info->x;
	modify_string(info);
	while (info->x > 6)
		p_left(info);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	press_quote_string(info);
	while (info->x > cursor)
		p_left(info);
	info->quote_len--;
}

void			p_delete(t_shell *info)
{
	int		cursor;

	cursor = info->len;
	modify_string(info);
	while (info->len > 0)
		p_left(info);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	press_string(info);
	while (info->len > cursor)
		p_left(info);
	if (info->is_his)
		info->no_move_his = 1;
}
