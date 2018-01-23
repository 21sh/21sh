/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:43:25 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/12 20:50:02 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		print_var(char *command, t_env *list)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_strdup(&command[i]);
	while (list)
	{
		if (!(ft_strncmp(tmp, list->var, ft_strclen(list->var, '='))) &&
				(list->var[ft_strclen(list->var, '=')] + 1) != '\0' &&
				command != NULL)
			ft_print("%s", &list->var[ft_strclen(list->var, '=')] + 1);
		list = list->next;
	}
	free(tmp);
}

int			ft_echo(char **command, t_env *list)
{
	int		i;
	int		nl;

	i = 0;
	nl = 0;
	if (!(command[i]))
		return (0);
	if (command[1] != NULL && !ft_strcmp(command[1], "-n"))
	{
		nl = 1;
		i++;
	}
	while (command[++i])
	{
		if (nl == 1 || i > 1 || i > 2)
			ft_putstr(" ");
		if (command[i][0] == '$')
			print_var(command[i], list);
		else if (command[i][0] != '$')
			ft_print("%s", command[i]);
	}
	if (nl != 1)
		ft_putstr("\n");
	return (0);
}
