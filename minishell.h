/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/09 09:51:12 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

# define RESET "\033[0m"
# define PURPLE "\e[1;95m"

typedef struct s_node
{
	int		type;
	char	*str;
	struct s_node *next;
}	t_node;

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
} t_cmd;

typedef struct s_info
{
	int		open_q;
	char	*line;
	char	**env;
	char	**split;
	int		n_cmd;
	t_cmd	*cmd;
}	t_info;

t_info *g_info;


void	lst_add(t_cmd **list);
int		num_cmds();
void	get_list(void);
int		incrementer(char *s, int i);
char	**ft_split_q(char *s, char c);
void	free_double(char **str);
char	**ft_split_set(char *str, char *charset);
void	get_redir(void);
int		check_size_of_op(int i);
int		size_of_op(int *i, int j);
void	skip_oop(int *i);
int		skip_til_op(char *str, int x);
int		number_of_redir(void);
void	alloc_op_files(int x);
void	copy_op_files(int x);
void	alloc_redir(int n_op);
int		check_alloc_redir(int n_op);
char	*get_cmd(void);
void	get_short_cmd(void);
int		get_word(char *str, int i);
char	**alloc_env(char **env);
// void    one_pipe(t_cmd **input, t_info **g_info);
void    one_pipe(void);
char 	*get_path(void);
char	*check_env(char *str);
char	*check_quotes(char *str);
void    redir(void);
void    ft_echo();
void    ft_pwd();
void    ft_cd();
char  *put_cmd_in_path(char *cmd, char *path);
#endif