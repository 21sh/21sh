/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:20:38 by corosteg          #+#    #+#             */
/*   Updated: 2017/10/12 22:27:20 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_get_cd(char **command2)
{
	int		cd;

	cd = 0;
	if (command2[1])
	{
		if ((ft_strcmp(command2[1], "~")) == 0 ||
				(ft_strcmp(command2[1], "~/")) == 0)
			cd = 1;
		else if ((ft_strcmp(command2[1], "-")) == 0)
			cd = 2;
		else if ((ft_strcmp(command2[1], "--")) == 0)
			cd = 1;
	}
	return (cd);
}

t_env		*ft_cd_home(char **command2, t_env *env)
{
	char	*oldpwd;
	char	*path;
	char	*tmp;
	char	cwd[1024];

	oldpwd = NULL;
	path = NULL;
	oldpwd = getcwd(cwd, sizeof(cwd));
	env = set_env(oldpwd, env, "OLDPWD", 2);
	if ((path = findhome(env)) != NULL)
	{
		tmp = ft_strdup(&path[5]);
		if (chdir(tmp) != 0 && command2[1])
			ft_print("cd: no such file or directory : %s\n", command2[1]);
		free(path);
		free(tmp);
		getcwd(cwd, sizeof(cwd));
		env = set_env(cwd, env, "PWD", 1);
	}
	else
		ft_print("HOME not set\n");
	return (env);
}

t_env		*ft_cd_oldpwd(char **command2, t_env *env)
{
	char	*oldpwd;
	char	*path;
	char	*tmp;
	char	cwd[1024];

	oldpwd = NULL;
	path = NULL;
	if ((path = findoldpwd(env)) != NULL)
	{
		oldpwd = getcwd(cwd, sizeof(cwd));
		env = set_env(oldpwd, env, "OLDPWD", 2);
		tmp = path;
		path = ft_strdup(&path[7]);
		free(tmp);
		ft_print("%s\n", path);
		if (chdir(path) != 0)
			ft_print("cd: no such file or directory : %s\n", command2[1]);
		free(path);
		getcwd(cwd, sizeof(cwd));
		env = set_env(cwd, env, "PWD", 1);
	}
	else
		ft_print("OLDPWD not set\n");
	return (env);
}

t_env		*ft_cd(char **command2, t_env *env)
{
	char	*oldpwd;
	char	*path;
	char	cwd[1024];

	oldpwd = NULL;
	path = NULL;
	oldpwd = getcwd(cwd, sizeof(cwd));
	env = set_env(oldpwd, env, "OLDPWD", 2);
	path = ft_strdup(command2[1]);
	if (chdir(path) != 0)
		ft_print("cd: no such file or directory : %s\n", command2[1]);
	getcwd(cwd, sizeof(cwd));
	free(path);
	env = set_env(cwd, env, "PWD", 1);
	return (env);
}

t_env		*ft_cd_pars(char **command2, t_env *env, int i)
{
	int		arg;
	int		cd;

	arg = ft_get_arg(command2);
	cd = ft_get_cd(command2);
	if (arg > 3)
		ft_print("cd: too many arguments\n");
	else if (arg == 3)
		ft_print("cd: string not in pwd: %s\n", command2[1]);
	else
	{
		if (cd == 1 || arg < 2)
			env = ft_cd_home(command2, env);
		else if (cd == 2)
			env = ft_cd_oldpwd(command2, env);
		else if ((command2[1] != NULL && cd != 1 && cd != 2) || i != 0)
			env = ft_cd(command2, env);
	}
	return (env);
}
