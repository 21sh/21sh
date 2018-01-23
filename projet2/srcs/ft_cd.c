/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:26:12 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/12 20:35:45 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			env_cmp(char *arg, t_env *env)
{
	if (!(ft_strncmp(arg, env->var, ft_strclen(env->var, '='))) &&
	(env->var[ft_strclen(env->var, '=')] + 1) != '\0' &&
	arg != NULL)
		return (1);
	else
		return (0);
}

t_env		*set_env(char *path, t_env *env, char *arg, int p)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		if ((env_cmp(arg, tmp)) == 1)
		{
			if (p == 1)
			{
				free(tmp->var);
				tmp->var = ft_strfreejoin("PWD=", path, 0);
				break ;
			}
			else if (p == 2)
			{
				free(tmp->var);
				tmp->var = ft_strfreejoin("OLDPWD=", path, 0);
				break ;
			}
		}
		tmp = tmp->next;
	}
	return (env);
}

char		*findhome(t_env *env)
{
	char	*path;
	t_env	*tmp;

	tmp = env;
	path = NULL;
	while (tmp)
	{
		if ((env_cmp("HOME", tmp)) == 1)
			path = ft_strdup(tmp->var);
		tmp = tmp->next;
	}
	return (path);
}

char		*findoldpwd(t_env *env)
{
	char	*path;
	t_env	*tmp;

	tmp = env;
	path = NULL;
	while (tmp)
	{
		if ((env_cmp("OLDPWD", tmp)) == 1)
			path = ft_strdup(tmp->var);
		tmp = tmp->next;
	}
	return (path);
}

int			ft_get_arg(char **command2)
{
	int		i;

	i = 0;
	while (command2[i])
		i++;
	return (i);
}
