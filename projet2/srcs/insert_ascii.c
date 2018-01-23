/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:58:47 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/16 18:21:27 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void			modify_string(t_shell *info, char *str2, int insert_len)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strndup(info->command, insert_len);
	tmp = ft_strfreejoin(tmp, str2, 1);
	tmp = ft_strfreejoin(tmp, &info->command[insert_len], 1);
	tmp2 = info->command;
	info->command = ft_strdup(tmp);
	free(tmp);
	free(str2);
	free(tmp2);
}

int					insert_ascii(t_shell *info, char *str)
{
	int					buf;
	char				*str2;
	int					insert_len;
	int					cursor;
	struct winsize		screen;

	ioctl(0, TIOCGWINSZ, &screen);
	insert_len = info->len;
	str2 = ft_strdup(str);
	cursor = info->len + 1;
	modify_string(info, str2, insert_len);
	while (info->len > 0)
		p_left(info);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	press_string(info);
	while (info->len > cursor)
		p_left(info);
	if (info->is_his)
		info->no_move_his = 1;
	return (0);
}

int					insert_quote_ascii(t_shell *info, char *str)
{
	int					buf;
	char				*str2;
	int					insert_len;
	int					cursor;
	struct winsize		screen;

	ioctl(0, TIOCGWINSZ, &screen);
	insert_len = info->len;
	str2 = ft_strdup(str);
	cursor = info->len + 1;
	modify_string(info, str2, insert_len);
	while (info->x > 6)
		p_left(info);
	tputs(tgetstr("cd", NULL), 1, ft_putchar);
	press_quote_string(info);
	while (info->len > cursor)
		p_left(info);
	info->quote_len++;
	return (0);
}
