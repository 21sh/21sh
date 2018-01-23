/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_comm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 22:09:42 by corosteg          #+#    #+#             */
/*   Updated: 2017/12/14 18:49:13 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int				check_com(char c, char c2)
{
	if (c == '|')
		return (0);
	if (c == ';')
		return (0);
	if (c == '&')
		return (0);
	if (c == '>')
		return (0);
	if (c == '<')
		return (0);
	else
		return (1);
}

static int		check_pipe(char *str)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (1);
		if (str[i] == '>')
			return (2);
		if (str[i] == '>' && str[i + 1] == '>')
			return (3);
		if (str[i] == '<')
			return (4);
		if (str[i] == ';')
			return (5);
		i++;
	}
	return (5);
}

void			redir_simpl2(t_shell *info, char *file)
{
	int		i;
	int		a;
	char	*final;

	i = 0;
	a = 0;
	while (file[i])
	{
		while (file[i] == ' ')
			i++;
		while (file[i] && file[i] != ' ')
		{
			final = ft_strnew(ft_strlen(file));
			final[a] = file[i];
			i++;
		}
		while (file[i] == ' ')
			i++;
		i++;
	}
	free(file);
	if ((final[0] != '/') || (final[0] != '.' && final[1] != '/') ||
			(final[0] != '.' && final[1] != '.' && final[2] != '/'))
	final = ft_strfreejoin("./", final, 0);
	info->fd_out = open(final, O_CREAT | O_TRUNC | O_RDWR, 0644);
	info->redir = 1;
}

static int		redir_simpl(t_shell *info, int i)
{
	char	*file;
	int		a;

	a = 0;
	file = ft_strnew(ft_strlen(info->command));
	while (info->command[i] && info->command[i] != '>' &&
			info->command[i] != '<' && info->command[i] != '|' &&
			info->command[i] != ';')
	{
		file[a] = (char)info->command[i];
		i++;
		a++;
	}
	if (info->command[i] == '\0')
	{
		free(info->command);
		info->command = ft_strdup("\0");
	}
	redir_simpl2(info, file);
	return (1);
}

int				check_arrow(t_shell *info)
{
	int			i;

	i = 0;
	while (info->command[i] && info->command[i] != '>' &&
			info->command[i] != '<' && info->command[i] != '|' &&
			info->command[i] != ';')
	i++;
	if (info->command[i] == '>' && info->command[i + 1] != '>')
		return (redir_simpl(info, i + 1));
//	if (info->command[i] == '>' && info->command[i] === '>')
//		return (redir_at_end(info));
//	if (info->command[i] == '<' && info->command[i] != '<')
//		return (redir_simpl(info));
		return (0);
}

static char		*next_command(char *str, t_shell *info, char *comm)
{
	char		*result;
	int			i;

	i = 0;
	if (check_arrow(info))
		return (comm);
	result = ft_strnew(ft_strlen(str));
	while (str[i] && str[i] != '|' && str[i] != ';' && str[i] != '<' &&
			str[i] != '>')
	{
		result[i] = str[i];
		i++;
	}
	if (str[i] == ';' || str[i] == '\0')
		info->exec_on_stdout = 1;
	if (str[i])
	{
		info->exec_sign = check_pipe(info->command);
		info->command = ft_strdup(&info->command[i + 1]);
	}
	else
		info->command = ft_strdup("\0");
	return (result);
}


int				exec_pipe_comm(t_shell *info, char *str, int i, int fd)
{
	int			ret;
	pid_t		father;
	int			status;
	char		**comm_tab;
	char		**env_tab;
	char		*bin_path;
	char		*command;
	int			save_fd[2];
	int			a;

	a = 0;
	env_tab = alloc_tab(info->env);
	info->save_stdin = dup(0);
	info->save_stdout = dup(1);
	info->fd_in = dup(0);
	info->fd_out = dup(1);
	while ((ret = check_pipe(info->command)))
	{
		command = next_command(info->command, info, command);
		if (info->exec_sign == 1)
			exec_pipe(info, command, a, env_tab);
//		if (info->exec_sign == 2)
//			exec_arrow(info, command, a, env_tab);

		if (ret == 5)
			break ;
		a++;
	}
	dup2(info->save_stdin, 0);
	dup2(info->save_stdout, 1);
	return (0);
}
