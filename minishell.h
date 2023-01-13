/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/13 16:33:00 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# pragma once

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

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
	int		n_cmd;
	t_cmd	*cmd;
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
void	copy_short_cmd(int m, int n_op);
int		get_word(char *str, int i);
char	**alloc_env(char **env);
void	one_pipe(void);
char	*get_path(void);
char	*check_env(char *str);
char	*check_quotes(char *str);
#endif