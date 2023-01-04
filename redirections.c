/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:24:36 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/04 17:13:10 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_op(int i, int x)
{
	int	j;
	char c;

	j = 0;
	c = 0;
	while (g_info->cmd->full_cmd[i] && (g_info->cmd->full_cmd[i] == '>' || g_info->cmd->full_cmd[i] == '<'))
		g_info->cmd->full_op[x][j++] = g_info->cmd->full_cmd[i++];
	while (ft_isspace(g_info->cmd->full_cmd[i]) && g_info->cmd->full_cmd[i])
		i++;
	g_info->cmd->full_op[x][j++] = ' ';
	while (!ft_isspace(g_info->cmd->full_cmd[i]) && g_info->cmd->full_cmd[i] != '>' 
		&& g_info->cmd->full_cmd[i] != '<' && g_info->cmd->full_cmd[i])
	{
		if (g_info->cmd->full_cmd[i] == 39 || g_info->cmd->full_cmd[i] == 34)
		{
			c = g_info->cmd->full_cmd[i++];
			while(g_info->cmd->full_cmd[i] != c && g_info->cmd->full_cmd[i])
				g_info->cmd->full_op[x][j++] = g_info->cmd->full_cmd[i++];
		}
		else
			g_info->cmd->full_op[x][j++] = g_info->cmd->full_cmd[i++];	
	}
	g_info->cmd->full_op[x][j] = 0;
}

int	check_redir(int n_op)
{
	int	i;
	int	x;
	int	size_of_op;

	x = 0;
	i = 0;
	if (!check_alloc_redir(n_op))
		return (0);
	alloc_redir(n_op);
	while (x < n_op)
	{
		i = skip_til_op(g_info->cmd->full_cmd, i);
		size_of_op = 0;
		size_of_op = check_size_of_op(i);
		if (size_of_op == 0)
			return (0);
		g_info->cmd->full_op[x] = ft_calloc(sizeof(char), size_of_op + 1);
		skip_oop(&i);
		x++;
	}
	return (1);
}

int	check_copy_redir(int n_op)
{
	int	x;
	int	size_of_op;
	int	i;

	x = 0;
	if (!check_redir(n_op) || n_op == 0)
	{
		g_info->cmd->full_op = NULL;
		g_info->cmd->files = NULL;
		g_info->cmd->redir = NULL;
		return (0);
	}
	i = 0;
	while (x < n_op)
	{
		i = skip_til_op(g_info->cmd->full_cmd, i);
		copy_op(i, x);
		size_of_op = check_size_of_op(i);
		if (!size_of_op)
			return (0);
		skip_oop(&i);
		x++;
	}
	x = 0;
	return (1);
}

void	get_op_files(int n_op)
{
	int	x;

	x = 0;
	while (x < n_op)
	{
		alloc_op_files(x);
		copy_op_files(x);
		x++;
	}
}

void	get_redir()
{
	int	x;
	int	n_op;

	n_op = number_of_redir();
	x = 0;
	if (!n_op)
	{
		g_info->cmd->full_op = NULL;
		g_info->cmd->files = NULL;
		g_info->cmd->redir = NULL;
		return;
	}
	if (!check_copy_redir(n_op))
		return;
	get_op_files(n_op);
	while (x < n_op)
		free (g_info->cmd->full_op[x++]);
	free(g_info->cmd->full_op);
}