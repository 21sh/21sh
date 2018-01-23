/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simpl_comm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 23:30:39 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/22 00:18:30 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

static int		exec_bin_comm(t_shell *info, char *command, t_path *var_path)
{
	pid_t		father;
	int			status;
	char		**comm_tab;
	char		**env_tab;
	char		*bin_path;

	env_tab = alloc_tab(info->env);
	comm_tab = ft_strsplit(command, ' ');
	bin_path = look_for_bin(comm_tab[0], var_path);
	father = fork();
	if (father > 0)
		wait(&status);
	if (!(father))
	{
		if (execve(bin_path, comm_tab, env_tab))
		{
			ft_print("command not found: %s\n", comm_tab[0]);
			exit(father);
		}
	}
	free(command);
	free(bin_path);
	free_c_tab(env_tab);
	free_c_tab(comm_tab);
//	free_path_list(var_path);
	return (WEXITSTATUS(status));
}

int				exec_simpl_comm(t_shell *info, char *command)
{
	t_path		*var_path;

	var_path = parse_path(info->env);
	if (var_path == NULL)
		;
//	if (check_builtin)
//		;
	else
		return (exec_bin_comm(info, command, var_path));
	return (0);
}
