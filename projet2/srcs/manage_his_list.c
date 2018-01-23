/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_his_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:57:56 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/06 17:42:47 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_his				*init_his(t_his *his, t_shell *info)
{
	his = (t_his*)malloc(sizeof(t_his));
	his->command = ft_strdup(info->command);
	his->first = 0;
	his->last = 1;
	his->next = NULL;
	his->prev = NULL;
	return (his);
}

t_his				*manage_his_list(t_his *his, t_shell *info)
{
	t_his		*tmp;
	t_his		*tmp2;

	tmp = his;
	if (his == NULL)
		return (init_his(his, info));
	while (tmp->next)
		tmp = tmp->next;
	tmp2 = tmp;
	tmp->next = (t_his*)malloc(sizeof(t_his));
	tmp = tmp->next;
	tmp->command = ft_strdup(info->command);
	tmp->next = NULL;
	tmp->prev = tmp2;
	return (tmp);
}
