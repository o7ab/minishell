/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/04 10:27:08 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

# define RESET "\033[0m"
# define PURPLE "\e[1;95m"

typedef struct s_generl
{
	char **enviro;
}	t_generl;

extern t_generl globalStruct;
typedef struct s_info
{
	int		open_q;
	char	*line;
	char	*cmd;
	char	**env;
	char	**split;
	int		n_cmd;
}	t_info;

typedef struct s_node
{
	int		type;
	char	*str;
	struct s_node *next;
}	t_node;

typedef struct s_cmd
{
	char			*cmd;
	char			*arg;
	char			*flag;
	char			**files;
	char			**redir;
	char			*full_cmd;
	char			**full_op;
	char			**s_cmd;
	char			*new_cmd;
	struct s_cmd	*next;
} t_cmd;

void	lst_add(t_cmd **list);
int		num_cmds(t_info *info);
void	get_list(t_cmd *input, t_info *info);
int		incrementer(char *s, int i);
char	**ft_split_q(char *s, char c);
void	free_double(char **str);
char	**ft_split_set(char *str, char *charset);
void	get_redir(t_cmd *input);
int		check_size_of_op(t_cmd *input, int i);
int		size_of_op(t_cmd *input, int *i, int j);
void	skip_oop(t_cmd *input, int *i);
int		skip_til_op(char *str, int x);
int		number_of_redir(t_cmd *input);
void	alloc_op_files(t_cmd *input, int x);
void	copy_op_files(t_cmd *input, int x);
void	alloc_redir(t_cmd *input, int n_op);
int		check_alloc_redir(t_cmd *input, int n_op);
char	*get_cmd(t_info *info);
void	get_short_cmd(t_cmd *input);
int		get_word(char *str, int i);
char	**alloc_env(char **env);
void	check_env(char *str, t_cmd *input);
void    one_pipe(t_cmd **input, t_info **info);
char *get_path(void);
#endif