/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/06 05:00:50 by oabushar         ###   ########.fr       */
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
# define WORD 0
# define PIPE 1
# define SPC 2
# define QUOTES 3
# define DQUOTES 4

typedef struct s_info
{
	int		open_q;
	char	*line;
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
	char			*outfile;
	char			*infile;
	char			*full_cmd;
	struct s_cmd	*next;
} t_cmd;

void	lst_add(t_cmd **list, t_info *info);
int		num_cmds(t_info *info);
char	*get_arg(t_info *info, t_cmd *input);
char	*get_quotes(t_info *info, int index);
void	get_list(t_cmd *input, t_info *info);
int		incrementer(char *s, int i);
#endif