/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looking_for_bin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:58:28 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/17 17:00:59 by corosteg         ###   ########.fr       */
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

static t_path		*create_e_path(char *str, int i)
{
	char	**tab1;
	t_path	*list;
	t_path	*retu;

	if (str_is_null(str))
		return (0);
	i = 0;
	tab1 = ft_strsplit(str, ':');
	list = (t_path*)malloc(sizeof(t_path));
	retu = list;
	retu->path = ft_strdup(tab1[0]);
	retu->next = NULL;
	while (tab1[i])
	{
		list->next = (t_path*)malloc(sizeof(t_path));
		list = list->next;
		list->path = ft_strdup(tab1[i]);
		list->next = NULL;
		i++;
	}
	free(str);
	free_c_tab(tab1);
	return (retu);
}

t_path					*parse_path(t_env *list)
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
