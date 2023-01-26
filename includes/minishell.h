/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/26 06:29:16 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# pragma once

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define RESET "\033[0m"
# define PURPLE "\e[1;95m"

typedef struct s_cmd
{
	char			*flag;
	char			**files;
	char			**redir;
	char			*full_cmd;
	char			**full_op;
	char			**s_cmd;
	char			*new_cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_info
{
	int		open_q;
	char	*line;
	char	**env;
	char	**split;
	int		fd_out_save;
	int		fd_in_save;
	int		n_cmd;
	t_cmd	*cmd;
	t_cmd	*first;
}	t_info;

t_info	*g_info;

void	lst_add(t_cmd **list);
int		num_cmds(void);
void	get_list(void);
int		incrementer(char *s, int i);
char	**ft_split_q(char *s, char c);
void	free_double(char **str);
char	**ft_split_set(char *str, char *charset);
int		get_redir(void);
int		check_size_of_op(int i);
int		size_of_op(int *i, int j);
void	skip_oop(int *i);
int		skip_til_op(char *str, int x);
int		number_of_redir(void);
void	alloc_op_files(int x);
void	copy_op_files(int x);
void	alloc_redir(int n_op);
int		check_alloc_redir(int n_op);
void	get_short_cmd(void);
void	short_help(int i, int m, int n_op);
char	*var_error(char *str);
void	init_input(void);
void	full_copy(int index, int i);
void	copy_short_cmd(int m, int n_op);
int		get_word(char *str, int i);
char	**alloc_env(char **env);
int    one_pipe();
char *ft_env(void);
char	*check_env(char *str);
char	*check_quotes(char *str);
char  *put_cmd_in_path(char *cmd, char *path);
void    redir(void);
void	free_shell(void);
void    ft_echo();
int 	ft_strcmp(char *s1, char *s2);
void    excute_built_in(char *command);
int     check_built_in(char *command);
void    ft_cd();
void    ft_pwd();
void    ft_export();
int     ft_is_inside(char *key);
void    ft_change_value(int i, int m);
void    add_env(char *select, char *value, int i, int j);
char    **ft_create_var(int len, char *key, int m);
void    change_env(char *select, char *value, int j);
char 	*ft_getenv(char *s);
void	free_env(char **env);
char    *ft_var(int i, int j);
void    ft_unset();
#endif