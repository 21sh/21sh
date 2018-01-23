/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corosteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:37:55 by corosteg          #+#    #+#             */
/*   Updated: 2017/12/14 17:26:44 by corosteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H
# include <fcntl.h>
# include <termios.h>
# include <dirent.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termcap.h>
# include "../libft/libft.h"
# include "../libft/keys.h"
# define STOP		"\033[0m"
# define VERT		"\033[32m"
# define CYAN		"\033[36m"
# define RED		"\033[31m"
# define GRAS		"\033[1m"

typedef struct			s_env
{
	char				*var;
	struct s_env		*next;
}						t_env;

typedef struct			s_shell
{
	int					x;
	int					y;
	int					len;
	int					is_his;
	int					no_move_his;
	int					quote;
	int					dquote;
	int					quote_len;
	int					pipefd[2];
	int					pipefd2[2];
	int					exec_on_stdout;
	int					save_stdin;
	int					save_stdout;
	int					exec_sign;
	int					redir;
	int					fd_out;
	int					fd_in;
	struct s_his		*his;
	struct s_env		*env;
	char				*command;
	char				*command2;
}						t_shell;

typedef struct			s_his
{
	char				*command;
	int					first;
	int					last;
	struct s_his		*next;
	struct s_his		*prev;
}						t_his;

typedef struct			s_path
{
	char				*path;
	struct s_path		*next;
}						t_path;

void					p_home(t_shell *info);
void					core(t_shell *info);
void					p_end(t_shell *info);
void					press_string(t_shell *info);
void					p_quote_delete(t_shell *info);
void					init_term(void);
void					p_ascii_emulation(char *str, t_shell *info);
void					p_backspace(t_shell *info, int a);
void					p_quote_backspace(t_shell *info);
void					p_delete(t_shell *info);
void					p_right(t_shell *info);
void					p_ascii(t_shell *info, char *str, int buf);
void					p_space(t_shell *info, char *str);
void					p_s_left(t_shell *info);
void					p_s_right(t_shell *info);
void					p_s_down(t_shell *info);
void					p_s_up(t_shell *info);
void					free_c_tab(char **array);
void					manage_squote(t_shell *info);
void					manage_dquote(t_shell *info);
void					check_quotes(t_shell *info);
void					print_cpy(int buf, t_shell *info);
void					press_quote_string(t_shell *info);
void					p_quote_home(t_shell *info);
void					p_quote_space(t_shell *info, char *str);
void					p_s_quote_left(t_shell *info);
void					exec_pipe(t_shell *info, char *command,
							int a, char **env_tab);
char					**alloc_tab(t_env *list);
char					*look_for_bin(char *co, t_path *e_path);
int						insert_quote_ascii(t_shell *info, char *str);
int						p_left(t_shell *info);
int						check_press(int buf, t_shell *info, t_his *his);
int						insert_ascii(t_shell *info, char *str);
int						exec_simpl_comm(t_shell *info, char *command);
int						exec_pipe_comm(t_shell *info, char *str,
							int i, int fd);
int						quote_n(t_shell *info);
int						check_copy(int buf);
int						check_press_quote(int buf, t_shell *info);
int						parse_command(char *str);
//t_shell					*init_info_list(t_shell *info);
t_env					*copy_env(char **env, t_env *list);
t_path					*parse_path(t_env *list);
t_his					*p_up(t_shell *info, t_his *his);
t_his					*check_entry(t_shell *info, t_his *his);
t_his					*manage_his_list(t_his *his, t_shell *info);
t_his					*p_down(t_shell *info, t_his *his);

#endif
