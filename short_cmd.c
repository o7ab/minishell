/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:02:39 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/24 22:38:29 by oabushar         ###   ########.fr       */
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
	while (ft_isspace(str[*i]) && str[*i])
		(*i)++;
	while (str[*i] && str[*i] != '>' && str[*i] != '<' && !ft_isspace(str[*i]))
	{
		if (str[*i] == 39 || str[*i] == 34)
		{
			c = str[*i++];
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
	while (ft_isspace(input->full_cmd[*i]) && input->full_cmd[*i])
		(*i)++;
	input->new_cmd[m++] = ' ';
	printf("beeeeeeforrreee cmd is (%s) and \n", &input->full_cmd[*i]);
	while (input->full_cmd[*i] && input->full_cmd[*i] != '>' && input->full_cmd[*i] != '<')
	{
		printf("the char is (%c) and i is %d and s is (%s) while new is (%s)\n", input->full_cmd[*i], *i, &input->full_cmd[*i], input->new_cmd);
		if (input->full_cmd[*i] == 39 || input->full_cmd[*i] == 34)
		{
			printf("test\n");
			c = input->full_cmd[*i];
			input->new_cmd[m++] = input->full_cmd[*i++];
			while (input->full_cmd[*i] != c && input->full_cmd[*i])
				input->new_cmd[m++] = input->full_cmd[*i++];
		}
		input->new_cmd[m] = input->full_cmd[*i];
		(*i)++;
		m++;
	}
	printf("the short new cmd is (%s) and \n", input->new_cmd);
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
	i = get_word(input->full_cmd, 0);
	x = 0;
	while (++index < i)
		input->new_cmd[index] = input->full_cmd[index];
	// printf("the new cmd is (%s) and i is %d\n", input->new_cmd, i);
	while (x < n_op) 
	{
		index = skip_til_op(input->full_cmd, index);
		skip_oop(input, &index);
		x++;
		if (x == n_op)
			break;
		i = copy_mid_arg(input, &index, i);
	}
	while (input->full_cmd[index])
		input->new_cmd[i++] = input->full_cmd[index++];
	input->new_cmd[i] = 0;
	printf("the new cmd is (%s) and i is (%d)\n", input->new_cmd, i);
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
	m = get_word(input->full_cmd, 0);
	n_op = number_of_redir(input);
	while(x < n_op && input->full_cmd[i])
	{
		i = get_word(input->full_cmd, i);
		if (ft_isspace(input->full_cmd[i]))
			m++;
		while (ft_isspace(input->full_cmd[i]))
			i++;
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
}