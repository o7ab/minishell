/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:44:02 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/10 20:33:42 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_alloc_redir(int n_op)
{
	int	i;
	int	x;
	int	size_of_op;

	i = 0;
	x = 0;
	while (x < n_op)
	{
		i = skip_til_op(g_info->cmd->full_cmd, i);
		size_of_op = check_size_of_op(i);
		if (!size_of_op)
			return (0);
		skip_oop(&i);
		x++;
	}
	return (1);
}

void	alloc_redir(int n_op)
{
	g_info->cmd->full_op = malloc((n_op + 1) * sizeof(char *));
	g_info->cmd->files = malloc((n_op + 1) * sizeof(char *));
	g_info->cmd->redir = malloc((n_op + 1) * sizeof(char *));
	g_info->cmd->full_op[n_op] = 0;
	g_info->cmd->redir[n_op] = 0;
	g_info->cmd->files[n_op] = 0;
}

int	number_of_redir(void)
{
	int		n;
	int		x;
	int		i;

	n = 0;
	x = 0;
	i = 1;
	while (g_info->cmd->full_cmd[x])
	{
		x = incrementer(g_info->cmd->full_cmd, x);
		if ((g_info->cmd->full_cmd[x] == '<'
				|| g_info->cmd->full_cmd[x] == '>') && i)
		{
			i = 0;
			n++;
		}
		else if ((g_info->cmd->full_cmd[x] != '<'
				&& g_info->cmd->full_cmd[x] != '>') && i == 0)
			i = 1;
		if (g_info->cmd->full_cmd[x])
			x++;
	}
	return (n);
}

void	alloc_op_files(int x)
{
	int	i;
	int	op_len;
	int	file_len;

	i = 0;
	op_len = 0;
	file_len = 0;
	while (g_info->cmd->full_op[x][i] && (g_info->cmd->full_op[x][i] == '>'
			|| g_info->cmd->full_op[x][i] == '<'))
	{
		i++;
		op_len++;
	}
	g_info->cmd->redir[x] = malloc(op_len + 1);
	if (!g_info->cmd->redir[x])
		return ;
	i++;
	while (g_info->cmd->full_op[x][i])
	{
		i++;
		file_len++;
	}
	g_info->cmd->files[x] = malloc(file_len + 1);
	if (!g_info->cmd->files[x])
		return ;
}

void	copy_op_files(int x)
{
	int	i;
	int	y;
	int	z;

	y = 0;
	z = 0;
	i = 0;
	while ((g_info->cmd->full_op[x][i] == '>'
		|| g_info->cmd->full_op[x][i] == '<') && g_info->cmd->full_op[x][i])
		g_info->cmd->redir[x][y++] = g_info->cmd->full_op[x][i++];
	g_info->cmd->redir[x][y] = 0;
	i++;
	while (g_info->cmd->full_op[x][i] != '\0')
		g_info->cmd->files[x][z++] = g_info->cmd->full_op[x][i++];
	g_info->cmd->files[x][z] = 0;
}
