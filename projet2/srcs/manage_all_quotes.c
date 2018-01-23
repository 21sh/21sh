/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 23:53:08 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/16 18:30:55 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void				check_quotes(t_shell *info)
{
	int		a;
	int		b;
	int		i;

	a = 0;
	b = 0;
	i = ft_strlen(info->command);
	while (i >= 0 && info->command[i] != '\n')
	{
		if (info->command[i] == '\'')
		{
			if (info->quote == 1)
				info->quote = 0;
			else
				info->quote = 1;
		}
		if (info->command[i] == '\"')
		{
			if (info->dquote == 1)
				info->dquote = 0;
			else
				info->dquote = 1;
		}
		i--;
	}
}

int				check_press_quote(int buf, t_shell *info)
{
	char	str[2];

	str[0] = (char)buf;
	str[1] = '\0';
	if (buf == 2117294875)
		p_quote_delete(info);
	else if (buf == 4479771 && (info->x > 6))
		p_left(info);
	else if (buf == 4414235 && ((info->x) < info->quote_len))
		p_right(info);
	else if (check_copy(buf))
		print_cpy(buf, info);
	else if  (buf == 127 && info->x > 6)
		p_quote_backspace(info);
	else if ((buf > 32 && buf < 126) && (info->x == info->quote_len))
		p_ascii(info, str, buf);
	else if ((buf > 32 && buf < 126) && (info->x < info->quote_len))
		insert_quote_ascii(info, str);
	else if (buf == 32)
		p_quote_space(info, " ");
	else if (buf == 17202)
		p_s_right(info);
	else if (buf == 17458)
		p_s_quote_left(info);
	else if (buf == 4741915)
		p_quote_home(info);
	else if (buf == 4610843)
		p_end(info);
	else if (buf == 10)
		return (1);
	return (0);
}
