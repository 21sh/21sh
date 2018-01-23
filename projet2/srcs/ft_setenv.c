/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:48:03 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/08 17:30:17 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		*modif(t_env *list, char *str)
{
	char	*tmp;

	tmp = list->var;
	list->var = ft_strdup(str);
	free(tmp);
	return (list);
}

t_env		*add_var(t_env *list, char **command2)
{
	t_env	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_env*)malloc(sizeof(t_env));
	tmp = tmp->next;
	tmp->var = ft_strdup(command2[1]);
	tmp->next = NULL;
	return (list);
}

int			check_as_var(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != ' ')
		i++;
	if (str[i] == '=')
		return (1);
	else
		return (0);
}

t_env		*ft_setenv(char **command2, t_env *list)
{
	t_env		*tmp;
	int			m;

	m = 0;
	if (command2[2] || !(check_as_var(command2[1])))
	{
		ft_print("usage: setenv [VAR=] new value\n");
		ft_print("       setenv [NEWVAR=] value\n");
		return (list);
	}
	tmp = list;
	while (tmp)
	{
		if (command2[1])
			if (check_ft_envfunct_action(command2, tmp, 0) == 2)
			{
				modif(tmp, command2[1]);
				m = 42;
			}
		tmp = tmp->next;
	}
	if (m == 0)
		list = add_var(list, command2);
	return (list);
}
