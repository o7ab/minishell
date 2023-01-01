/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:02:39 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/01 22:39:25 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_mid_arg(char *str, int *i)
{
	int		m;
	char	c;

	m = 0;
	c = 0;
	if (!str[*i])
		return (0);
	while (str[*i] && str[*i] != '>' && str[*i] != '<')
	{
		if (str[*i] == 39 || str[*i] == 34)
		{
			c = str[*i];
			(*i)++;
			m++;
			while (str[*i] != c && str[*i])
			{
				(*i)++;
				m++;
			}
		}
		m++;
		(*i)++;
	}
	return (m);
}

int	copy_mid_arg(t_cmd *input, int *i, int m)
{
	char	c;

	c = 0;
	if (!input->full_cmd[*i])
		return (m);
	while (input->full_cmd[*i] && input->full_cmd[*i] != '>' && input->full_cmd[*i] != '<')
	{
		if (input->full_cmd[*i] == 39 || input->full_cmd[*i] == 34)
		{
			c = input->full_cmd[*i];
			input->new_cmd[m++] = input->full_cmd[(*i)++];
			while (input->full_cmd[*i] != c && input->full_cmd[*i])
				input->new_cmd[m++] = input->full_cmd[(*i)++];
		}
		input->new_cmd[m] = input->full_cmd[*i];
		(*i)++;
		m++;
	}
	return (m);
	
}

void	copy_short_cmd(t_cmd *input, int m, int n_op)
{
	int	i;
	int index;
	int	x;

	index = -1;
	input->new_cmd = malloc(m + 1);
	if (!input->new_cmd)
		return;
	i = skip_til_op(input->full_cmd, 0);
	x = 0;
	while (++index < i)
		input->new_cmd[index] = input->full_cmd[index];
	while (x < n_op) 
	{
		skip_oop(input, &index);
		x++;
		if (x == n_op)
			break;
		i = copy_mid_arg(input, &index, i);
	}
	while (input->full_cmd[index])
	{
		if (input->full_cmd[index] == ' ')
			input->new_cmd[i++] = input->full_cmd[index++];
		while (ft_isspace(input->full_cmd[index]) && input->full_cmd[index])
			index++;
		if (input->full_cmd[index])
			input->new_cmd[i++] = input->full_cmd[index++];
	}
	input->new_cmd[i] = 0;
}

int	skip_words(char *str, int *i)
{
	char	c;
	int		m;

	m = 0;
	if (str[*i] == 0)
		return (0);
	while (str[*i] && str[*i] != '>' && str[*i] != '<')
	{
		m++;
		while (str[*i] && ft_isspace(str[*i]))
			(*i)++;
		if (str[*i] == 39 || str[*i] == 34)
		{
			c = str[*i++];
			m++;
			while(str[*i] && str[*i] != c)
			{
				(*i)++;
				m++;
			}
		}
		(*i)++;
	}
	return (m);
}

void get_short_cmd(t_cmd *input)
{
	int	i;
	int	m;
	int	x;
	int n_op;

	i = 0;
	m = 0;
	x = 0;
	n_op = number_of_redir(input);
	if (!n_op)
		return ;
	i = skip_til_op(input->full_cmd, i);
	m = i;
	while(x < n_op && input->full_cmd[i])
	{
		skip_oop(input, &i);
		m += check_mid_arg(input->full_cmd, &i);
		x++;
	}
	while (input->full_cmd[i])
	{
		i++;
		while(ft_isspace(input->full_cmd[i]) && input->full_cmd[i])
			i++;
		m++;
	}
	copy_short_cmd(input, m, n_op);
	free(input->full_cmd);
}