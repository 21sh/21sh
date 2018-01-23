/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:05:21 by corosteg          #+#    #+#             */
/*   Updated: 2017/11/24 18:01:45 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/21sh.h"
#include <string.h>
#include <fcntl.h>

void			ft_test(char *str)
{
	printf("%s", str);
}

int main(int ac, char **av, char **env)
{
	int		cmd_fd[2];
	int		cmd_fd2[2];
	int		father;
	int		father2;
	char	*cmd1[3];
	char	*cmd2[3];
	char	*cmd3[3];
	int		fd;

	cmd1[0] = strdup("/bin/ls");
	cmd1[1] = strdup("-laF");
	cmd1[2] = NULL;

	cmd2[0] = strdup("/bin/cat");
	cmd2[1] = strdup("-e");
	cmd2[2] = NULL;

	cmd3[0] = strdup("/usr/bin/wc");
	cmd3[1] = strdup("-c");
	cmd3[2] = NULL;

	pipe (cmd_fd);
	pipe (cmd_fd2);
	fd = open("testing_output.txt", O_APPEND | O_RDWR, 0644);

	father = fork();
	if (father > 0)
		father = wait(NULL);
	if (father == 0)
	{
		dup2 (cmd_fd[1], 1);
//		close(cmd_fd[0]);
		execve(cmd1[0], cmd1, env);
	}
	father = fork();
	dup2(cmd_fd[0], 0);
	close(cmd_fd[1]);
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		dup2(cmd_fd2[1], 1);
//		close(cmd_fd2[0]);
		execve(cmd2[0], cmd2, env);
	}
	father = fork();
	dup2(cmd_fd2[0], 0);
	close(cmd_fd2[1]);
	if (father > 0)
		wait(NULL);
	if (father == 0)
		execve(cmd3[0], cmd3, env);
	printf("super!!\n");
}
