/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:49:24 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/27 14:42:05 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_oop(t_cmd *input, int *i)
{
	int	j;

	j = 0;
	while (input->full_cmd[*i] && (input->full_cmd[*i] == '>' || input->full_cmd[*i] == '<') && j < 2)
	{
		(*i)++;
		j++;
	}
	j++;
	while (input->full_cmd[*i] && ft_isspace(input->full_cmd[*i]))
		(*i)++;
	j = size_of_op(input, i, j);
}

int	error_for_size_op(t_cmd *input, int i)
{
	if (input->full_cmd[i] == '<' || input->full_cmd[i] == '>' || !input->full_cmd[i])
	{
		printf("bash: unexpected token `%c'\n", input->full_cmd[i]);
		rl_on_new_line();
		return (0);
	}
	return (1);
}

int	size_of_op(t_cmd *input, int *i, int j)
{
	char	tmp;
	while (input->full_cmd[*i] && input->full_cmd[*i] != '>' && input->full_cmd[*i] != '<' && !ft_isspace(input->full_cmd[*i]))
	{
		if (!error_for_size_op(input, *i))
			return (0);
		if (input->full_cmd[*i] == 39 || input->full_cmd[*i] == 34)
		{
			tmp = input->full_cmd[(*i)++];
			j++;
			while (input->full_cmd[*i] && input->full_cmd[*i] != tmp)
			{
				(*i)++;
				j++;
			}
		}
		(*i)++;
		j++;
	}
	return (j);
}

int	check_size_of_op(t_cmd *input, int i)
{
	int	j;

	j = 0;
	while (input->full_cmd[i] && (input->full_cmd[i] == '>' || input->full_cmd[i] == '<') && j < 2)
	{
		if ((input->full_cmd[i] == '>' && input->full_cmd[i + 1] == '<'))
		{
			printf("bash: unexpected token `%c'\n", input->full_cmd[i + 1]);
			rl_on_new_line();
			return (0);
		}
		i++;
		j++;
	}
	j++;
	while (input->full_cmd[i] && ft_isspace(input->full_cmd[i]))
		i++;
	if (!error_for_size_op(input, i))
		return (0); 
	j = size_of_op(input, &i, j);
	return (j);
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
