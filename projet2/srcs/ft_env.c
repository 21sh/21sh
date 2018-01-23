/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:00:48 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/12 16:21:19 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			print_env(t_env *list, char *str, t_env *l, int a)
{
	char	*tmp;

	if (a == 1)
	{
		tmp = l->var;
		l->var = ft_strdup(str);
	}
	while (list)
	{
		ft_print("%s\n", list->var);
		list = list->next;
	}
	if (a == 1)
	{
		free(l->var);
		l->var = tmp;
	}
	return (1);
}

int			exec_with_modif(char **command2, t_env *list, t_env *l, char *str)
{
	char	*tmp;

	tmp = l->var;
	l->var = ft_strdup(str);
	list = core(&command2[2], list);
	free(l->var);
	l->var = tmp;
	return (1);
}

int			ft_env2(char **command2, t_env *list, t_env *l)
{
	if (command2[1] == NULL && !(ft_strcmp(command2[0], "env")))
		return (print_env(list, NULL, l, 0));
	else
		while (l)
		{
			if (command2[1])
			{
				if (check_ft_envfunct_action(command2, l, 0) == 1)
					return (exec_with_modif(command2, list, l, command2[1]));
				if (check_ft_envfunct_action(command2, l, 0) == 2)
					return (print_env(list, command2[1], l, 1));
			}
			l = l->next;
		}
	return (0);
}

int			ft_env(char **command2, t_env *list)
{
	t_env	*l;

	l = list;
	if (command2[1] && command2[1][0] == '-' && command2[1][1] == 'i'
			&& !(ft_strcmp(command2[0], "env")) && command2[2])
		core(&command2[2], NULL);
	else if ((!ft_env2(command2, list, l)))
		core(&command2[1], list);
	return (1);
}
