/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:47:41 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/17 15:38:20 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		*remv_var(t_env *rmv, t_env *list)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp = list;
	while (tmp->next && tmp->next != rmv)
		tmp = tmp->next;
	if (tmp->next)
		tmp2 = tmp->next;
	else
		tmp2 = NULL;
	tmp->next = tmp->next->next;
	free(tmp2->var);
	tmp2->var = NULL;
	free(tmp2);
	tmp2 = NULL;
	return (list);
}

int			check_as_var_u(char *str)
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

t_env		*ft_unsetenv(char **command2, t_env *list)
{
	t_env		*tmp;

	if (command2[1] == NULL)
	{
		ft_print("usage: unsetenv [VAR=] to delete\n");
		return (list);
	}
	if (command2[2] || !(check_as_var_u(command2[1])))
	{
		ft_print("usage: unsetenv [VAR=] to delete\n");
		return (list);
	}
	tmp = list;
	while (tmp)
	{
		if (check_ft_envfunct_action(command2, tmp, 0) == 2)
		{
			remv_var(tmp, list);
			break ;
		}
		tmp = tmp->next;
	}
	return (list);
}
