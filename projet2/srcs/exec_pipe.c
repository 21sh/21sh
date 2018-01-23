/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:07:22 by corosteg          #+#    #+#             */
/*   Updated: 2017/12/14 18:49:16 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*static void		first_pipe_exec(t_shell *info, char *command, char **env_tab)
{
	pid_t		father;
	char		*bin_path;
	char		**comm_tab;

	comm_tab = ft_strsplit(command, ' ');
	bin_path = look_for_bin(comm_tab[0], parse_path(info->env));
	pipe(info->pipefd);
	father = fork();
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		dup2(info->pipefd[1], 1);
		close(0);
			if (execve(bin_path, comm_tab, env_tab))
			{
				ft_print("command not found: %s\n", comm_tab[0]);
				exit(father);
			}
	}
}

static void		exec_pipe_bis(t_shell *info, char *command, char **env_tab)
{
	pid_t		father;
	char		*bin_path;
	char		**comm_tab;

	comm_tab = ft_strsplit(command, ' ');
	bin_path = look_for_bin(comm_tab[0], parse_path(info->env));
	pipe(info->pipefd2);
	father = fork();
	dup2(info->pipefd[0], 0);
	close(info->pipefd[1]);
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		if (info->exec_on_stdout == 1)
			dup2(info->save_stdout, 1);
		else
			dup2(info->pipefd2[1], 1);
		close(info->pipefd[1]);
		if (execve(bin_path, comm_tab, env_tab))
		{
			ft_print("command not found: %s\n", comm_tab[0]);
			exit(father);
		}
	}
}

static void		exec_pipe_third(t_shell *info, char *command, char **env_tab)
{
	pid_t		father;
	char		*bin_path;
	char		**comm_tab;

	comm_tab = ft_strsplit(command, ' ');
	bin_path = look_for_bin(comm_tab[0], parse_path(info->env));
	pipe(info->pipefd);
	father = fork();
	dup2(info->pipefd2[0], 0);
	close(info->pipefd2[1]);
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		if (info->exec_on_stdout == 1)
			dup2(info->save_stdout, 1);
		else
			dup2(info->pipefd[1], 1);
		close(info->pipefd2[1]);
		if (execve(bin_path, comm_tab, env_tab))
		{
			ft_print("command not found: %s\n", comm_tab[0]);
			exit(father);
		}
	}
}

void		exec_pipe(t_shell *info, char *command, int a, char **env_tab)
{
	if (a == 0)
		first_pipe_exec(info, command, env_tab);
	else if (a % 2 == 1)
		exec_pipe_bis(info, command, env_tab);
	else if (a % 2 == 0)
		exec_pipe_third(info, command, env_tab);
}*/


void		exec_pipe(t_shell *info, char *command, int a, char **env_tab)
{
	pid_t		father;
	char		*bin_path;
	char		**comm_tab;
	int			tmp_fd[2];

	printf("%s\n", command);
	comm_tab = ft_strsplit(command, ' ');
	bin_path = look_for_bin(comm_tab[0], parse_path(info->env));
	pipe(tmp_fd);
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		if (info->exec_on_stdout == 1)
			dup2(info->save_stdout, 1);
		else if (info->redir)
			dup2(info->fd_out, 1);
		else
			dup2(tmp_fd[1], 1);
		close(info->fd_in);
		if (execve(bin_path, comm_tab, env_tab))
		{
			ft_print("command not found: %s\n", comm_tab[0]);
			exit(father);
		}
	}
	info->fd_in = tmp_fd[0];
	info->fd_out = tmp_fd[1];
}
