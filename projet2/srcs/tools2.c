/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:06:25 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/17 17:46:18 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int			check_n(char *str)
{
	int			i;

	i = ft_strlen(str);
	while (i >= 0 && str[i] != '\n')
		i--;
	i++;
	return (i);
}

void				press_quote_string(t_shell *info)
{
	int		i;
	struct winsize		screen;

	i = check_n(info->command);
	ioctl(0, TIOCGWINSZ, &screen);
	while (info->command[i])
	{
		ft_putchar(info->command[i]);
		info->len++;
		info->x++;
		if (info->x > screen.ws_col - 1)
		{
			info->x = 0;
			tputs(tgetstr("do", NULL), 1, ft_putchar);
			tputs(tgetstr("cr", NULL), 1, ft_putchar);
			info->y++;
		}
		i++;
	}
}

char		*look_for_bin(char *co, t_path *e_path)
{
	DIR				*rep;
	char			*tmp;
	t_path			*tpm;
	struct dirent	*ent;

	tpm = e_path;
	if (tpm)
		while (tpm)
		{
			if ((rep = opendir(tpm->path)))
			{
				while ((ent = readdir(rep)))
				{
					if (!(ft_strcmp(ent->d_name, co)))
					{
						closedir(rep);
						tmp = ft_strfreejoin(tpm->path, "/", 0);
						return (co = ft_strfreejoin(tmp, co, 1));
					}
				}
				closedir(rep);
			}
			tpm = tpm->next;
		}
	return (ft_strdup(co));
}
