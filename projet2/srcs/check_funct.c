/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:10:00 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/14 19:14:22 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int			str_is_null(char *str)
{
	int i;

	i = 0;
	while (str[i] == ':')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (1);
	}
	else
		return (0);
}

static t_env		*create_e_path(char *str, int i)
{
	char	**tab1;
	t_env	*list;
	t_env	*retu;

	if (str_is_null(str))
		return (0);
	i = 0;
	tab1 = ft_strsplit(str, ':');
	list = (t_env*)malloc(sizeof(t_env));
	retu = list;
	retu->var = ft_strdup(tab1[0]);
	retu->next = NULL;
	while (tab1[i])
	{
		list->next = (t_env*)malloc(sizeof(t_env));
		list = list->next;
		list->var = ft_strdup(tab1[i]);
		list->next = NULL;
		i++;
	}
	free(str);
	free_c_tab(tab1);
	return (retu);
}

t_env				*check_e_path(t_env *list)
{
	t_env	*tmp;

	if (list == NULL)
		return (0);
	tmp = list;
	while (tmp)
	{
		if ((!(ft_strncmp(tmp->var, "PATH=", 4))) && tmp->var[5] != '\0')
			return (create_e_path(ft_strdup(&tmp->var[5]), 0));
		tmp = tmp->next;
	}
	return (NULL);
}
