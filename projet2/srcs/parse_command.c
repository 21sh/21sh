/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:36:00 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/17 21:28:22 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int		check_false(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (ft_print("\n21sh: syntax error near unexpected token 'newline'\n"
					));
	if (str[i] == ';')
		return (ft_print("\n21sh: syntax error near unexpected token ';'\n"));
	if (str[i] == '>' && (str[i + 1] > '9' || str[i + 1] < '0'))
		return (ft_print("\n21sh: syntax error near unexpected token '%c'\n"),
				str[i]);
	if (str[i] == '|')
		return (ft_print("\n21sh: syntax error near unexpected token '|'\n"));
	if (str[i] == '>' && str[i + 1] == '>')
		return (ft_print("\n21sh: syntax error near unexpected token '>'\n"));
	if (str[i] == '<')
		return (ft_print("\n21sh: syntax error near unexpected token '<'\n"));
	return (0);
}

static int		check_false2(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (ft_print("\n21sh: syntax error near unexpected token 'newline'\n"
					));
	if (str[i] == ';')
		return (ft_print("\n21sh: syntax error near unexpected token ';'\n"));
	if (str[i] == '&')
		return (ft_print("\n21sh: syntax error near unexpected token '&'\n"));
	if (str[i] == '<')
		return (ft_print("\n21sh: syntax error near unexpected token '<'\n"));
	return (0);
}

int				parse_command(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '&')
			if (check_false(str, (i + 1)))
				return (0);
		if (str[i] == '|')
			if (check_false2(str, (i + 1)))
				return (0);
		i++;
	}
	return (1);
}
