/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:23:12 by corosteg          #+#    #+#             */
/*   Updated: 2016/11/30 19:31:25 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *fin;

	if (lst == 0 || (*f) == 0)
		return (0);
	tmp = (*f)(lst);
	fin = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = (*f)(lst);
		if (tmp == NULL)
			return (fin);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (fin);
}
