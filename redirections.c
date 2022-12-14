/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:24:36 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/14 11:49:07 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	ft_copy_op(t_info *info, t_cmd *input, t_cmd *output, int i)
// {
// 	int store;

// 	store = i;
// 	while (input->full_cmd[i])
// 	{
// 		while (&& input->full_cmd[i])
// 	}
// }

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

int	skip_til_op(char *str, int x)
{
	char	c;

	c = 0;
	while (str[x] != '>' && str[x] != '<' && str[x])
	{
		if (str[x] == 39 || str[x] == 34)
		{
			c = str[x++];
			while (str[x] != c)
				x++;
		}
		x++;
	}
	return (x);
}

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
	}
}

int	check_redir(t_cmd *input, int n_op)
{
	int	i;
	int	x;

	x = 0;
	if (!check_alloc_redir(input, n_op))
		return (0);
	while (x < n_op)
	{
		
	}
}

void	get_redir(t_cmd *input)
{
	int	i;
	int	x;
	int	n_op;

	i = 0;

	n_op = number_of_redir(input);
	x = 0;
	check_redir(input, n_op);
	while (x < n_op)
	{
		i = skip_til_op(input->full_cmd, x);
		copy_op(input, i, x);
	}
}