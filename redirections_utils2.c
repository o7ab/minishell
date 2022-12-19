/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:44:02 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/18 01:56:53 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_alloc_redir(t_cmd *input, int n_op)
{
	int	i;
	int	x;
	int	size_of_op;

	i = 0;
	x = 0;
	while (x < n_op)
	{
		i = skip_til_op(input->full_cmd, i);
		size_of_op = check_size_of_op(input, i);
		if (!size_of_op)
			return (0);
		skip_oop(input, &i);
		x++;
	}
	return (1);
}

void	alloc_redir(t_cmd *input, int n_op)
{
	input->full_op = malloc((n_op + 1) * sizeof(char *));
	input->files = malloc((n_op + 1) * sizeof(char *));
	input->redir = malloc((n_op + 1)* sizeof(char *));
	input->full_op[n_op] = 0;
	input->redir[n_op] = 0;
	input->files[n_op] = 0;
}
int	number_of_redir(t_cmd *input)
{
	int		n;
	int		x;
	int		i;

	n = 0;
	x = 0;
	i = 1;
	while (input->full_cmd[x])
	{
		x = incrementer(input->full_cmd, x);
		if ((input->full_cmd[x] == '<' || input->full_cmd[x] == '>') && i)
		{
			i = 0;
			n++;
		}
		else if ((input->full_cmd[x] != '<' && input->full_cmd[x] != '>') && i == 0)
			i = 1;
		x++;
	}
	return (n);
}

void	alloc_op_files(t_cmd *input, int x)
{
	int	i;
	int	op_len;
	int	file_len;

	i = 0;
	op_len = 0;
	file_len = 0;
	while (input->full_op[x][i] && input->full_op[x][i] == '>' && input->full_op[x][i] == '<')
	{
		i++;
		op_len++;
	}
	input->redir[x] = malloc(op_len + 1);
	if (!input->redir[x])
		return ;
	i++;
	while (input->full_op[x][i])
	{
		i++;
		file_len++;
	}
	input->files[x] = malloc(file_len + 1);
	if (!input->files[x])
		return ;
}

void	copy_op_files(t_cmd *input, int x)
{
	int	i;
	int	y;
	int	z;

	y = 0;
	z = 0;
	i = 0;
	
	while ((input->full_op[x][i] == '>' || input->full_op[x][i] == '<') && input->full_op[x][i])
		input->redir[x][y++] = input->full_op[x][i++];
	input->redir[x][y] = 0;
	i++;
	while (input->full_op[x][i] != '\0')
		input->files[x][z++] = input->full_op[x][i++];
	input->files[x][z] = 0;
}