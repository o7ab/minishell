/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:24:36 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/01 22:15:40 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_op(t_cmd *input, int i, int x)
{
	int	j;
	char c;

	j = 0;
	c = 0;
	while (input->full_cmd[i] && (input->full_cmd[i] == '>' || input->full_cmd[i] == '<'))
		input->full_op[x][j++] = input->full_cmd[i++];
	while (ft_isspace(input->full_cmd[i]) && input->full_cmd[i])
		i++;
	input->full_op[x][j++] = ' ';
	while (!ft_isspace(input->full_cmd[i]) && input->full_cmd[i] != '>' 
		&& input->full_cmd[i] != '<' && input->full_cmd[i])
	{
		if (input->full_cmd[i] == 39 || input->full_cmd[i] == 34)
		{
			c = input->full_cmd[i++];
			while(input->full_cmd[i] != c && input->full_cmd[i])
				input->full_op[x][j++] = input->full_cmd[i++];
		}
		else
			input->full_op[x][j++] = input->full_cmd[i++];	
	}
	input->full_op[x][j] = 0;
}

int	check_redir(t_cmd *input, int n_op)
{
	int	i;
	int	x;
	int	size_of_op;

	x = 0;
	i = 0;
	if (!check_alloc_redir(input, n_op))
		return (0);
	alloc_redir(input, n_op);
	while (x < n_op)
	{
		i = skip_til_op(input->full_cmd, i);
		size_of_op = 0;
		size_of_op = check_size_of_op(input, i);
		// printf("check\n");
		if (size_of_op == 0)
		{
			// printf("error\n");
			return (0);
		}
		input->full_op[x] = ft_calloc(sizeof(char), size_of_op + 1);
		skip_oop(input, &i);
		x++;
	}
	return (1);
}

int	check_copy_redir(t_cmd *input, int n_op)
{
	int	x;
	int	size_of_op;
	int	i;

	x = 0;
	if (!check_redir(input, n_op) || n_op == 0)
	{
		input->full_op = NULL;
		input->files = NULL;
		input->redir = NULL;
		return (0);
	}
	i = 0;
	while (x < n_op)
	{
		i = skip_til_op(input->full_cmd, i);
		copy_op(input, i, x);
		size_of_op = check_size_of_op(input, i);
		if (!size_of_op)
			return (0);
		skip_oop(input, &i);
		x++;
	}
	x = 0;
	return (1);
}

void	get_op_files(t_cmd *input, int n_op)
{
	int	x;

	x = 0;
	while (x < n_op)
	{
		alloc_op_files(input, x);
		copy_op_files(input, x);
		x++;
	}
}

void	get_redir(t_cmd *input)
{
	int	x;
	int	n_op;

	n_op = number_of_redir(input);
	x = 0;
	if (!n_op)
	{
		input->full_op = NULL;
		input->files = NULL;
		input->redir = NULL;
		return;
	}
	if (!check_copy_redir(input, n_op))
		return;
	get_op_files(input, n_op);
	while (x < n_op)
		free (input->full_op[x++]);
	free(input->full_op);
}