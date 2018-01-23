/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:23:59 by corosteg          #+#    #+#             */
/*   Updated: 2017/12/14 15:49:41 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./21sh.h"

/*void				core(t_shell *info)
{
	int		run;
	int		i;
	int		ret;
	char	*str;

	i = 0;
	run = 0;
	ret = 1;
	while (info->command[run])
	{
		if (info->command[run] == ';' || (info->command[run + 1] == '\0'))
		{
			if (info->command[run + 1] == '\0')
				exec_simpl_comm(info, ft_strndup(info->command, (run + 1)));
			else
				exec_simpl_comm(info, ft_strndup(info->command, (run)));
			//str = ft_strnew(ft_strlen(info->command));
			info->command = ft_strdup(&info->command[run + 1]);
			run = -1;
		}
		if (run != -1 && info->command[run] && (info->command[run] == '|' ||
				info->command[run] == '>'))
		{
			exec_pipe_comm(info, info->command, i, 0);
//			str = ft_strnew(ft_strlen(info->command));
			run = -1;
		}
		run++;
//		if (info->command[run] == '|')
//		{
//			ret = exec_pipe_comm(info, i, run);
//			i = run + 1;
//		}
	}
}*/

int					check_operador(char c)
{
	if (c == ';')
		return (1);
	if (c == '>')
		return (1);
	if (c == '<')
		return (1);
	if (c == '|')
		return (1);
	return (0);
}

int					check_redir(char *command, int run)
{
	return(0);
}

int					redir(char *command, int run)
{
	return(0);
}

int					check_final(t_shell *info, int run)
{
	int		tmp;

	if (info->command[run]  == '\0')
	{
		tmp = info->fd_out;
		info->fd_out = info->save_stdout;
		close(tmp);
		return (1);
	}
	return(0);
}

static void				exec(t_shell *info, int run, char **env_tab)
{
	pid_t			father;
	char			*bin_path;
	char			**comm_tab;
	int				i;

	i = run;
	while (run > 0 && info->command[run - 1] != '|'
			&& info->command[run - 1] != ';')
		run--;
	comm_tab = ft_strnsplit(&info->command[run], ' ', (i - run));
	bin_path = look_for_bin(comm_tab[0], parse_path(info->env));
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		dup2(info->fd_out, 1);
		close(info->fd_in);
		if (execve(bin_path, comm_tab, env_tab))
		{
			ft_print("command not found: %s\n", comm_tab[0]);
			exit(father);
		}
	}
}

static void			exec_with_pipe(t_shell *info, int run, char **env_tab)
{
	pid_t			father;
	char			*bin_path;
	char			**comm_tab;
	int				tmp_fd[2];
	int				i;

	i = run;
	while (run > 0 && info->command[run - 1] != '|'
			&& info->command[run - 1] != ';')
		run--;
	comm_tab = ft_strnsplit(&info->command[run], ' ', ((i - run)));
	bin_path = look_for_bin(comm_tab[0], parse_path(info->env));
	pipe(tmp_fd);
	father = fork();
	dup2(info->fd_in, 0);
	close(info->fd_out);
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
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

void				core(t_shell *info)
{
	int		run;
	int		i;
	char	*str;
	char	**env_tab = alloc_tab(info->env);

	i = 0;
	run = 0;
	info->fd_in = dup(0);
	info->fd_out = dup(1);
	info->save_stdin = dup(0);
	info->save_stdout = dup(1);
	while (info->command[run])
	{
		run++;
		if (check_operador(info->command[run]) || info->command[run] == '\0')
		{
			if ((check_redir(info->command, run) && redir(info->command, run))
				|| (check_final(info, run)))
				exec(info, run, env_tab);
			if (info->command[run] == '|')
				exec_with_pipe(info, run,  env_tab);
		}
	}
	dup2(info->save_stdin, 0);
}
