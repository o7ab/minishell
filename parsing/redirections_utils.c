/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:49:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/11 16:52:35 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	skip_oop(int *i)
{
	int	j;

	j = 0;
	while (g_info->cmd->full_cmd[*i] && (g_info->cmd->full_cmd[*i] == '>'
			|| g_info->cmd->full_cmd[*i] == '<') && j < 2)
	{
		(*i)++;
		j++;
	}
	j++;
	while (g_info->cmd->full_cmd[*i] && ft_isspace(g_info->cmd->full_cmd[*i]))
		(*i)++;
	j = size_of_op(i, j);
}

int	error_for_size_op(int i)
{
	if (g_info->cmd->full_cmd[i] == '<' || g_info->cmd->full_cmd[i] == '>'
		|| !g_info->cmd->full_cmd[i])
	{
		printf("bash: unexpected token `%c'\n", g_info->cmd->full_cmd[i]);
		rl_on_new_line();
		return (0);
	}
	return (1);
}

int	size_of_op(int *i, int j)
{
	char	tmp;

	while (g_info->cmd->full_cmd[*i] && g_info->cmd->full_cmd[*i] != '>'
		&& g_info->cmd->full_cmd[*i] != '<'
		&& !ft_isspace(g_info->cmd->full_cmd[*i]))
	{
		if (!error_for_size_op(*i))
			return (0);
		if (g_info->cmd->full_cmd[*i] == 39 || g_info->cmd->full_cmd[*i] == 34)
		{
			tmp = g_info->cmd->full_cmd[(*i)++];
			j++;
			while (g_info->cmd->full_cmd[*i]
				&& g_info->cmd->full_cmd[*i] != tmp)
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

int	check_size_of_op(int i)
{
	int	j;

	j = 0;
	while (g_info->cmd->full_cmd[i] && (g_info->cmd->full_cmd[i] == '>'
			|| g_info->cmd->full_cmd[i] == '<') && j < 2)
	{
		if ((g_info->cmd->full_cmd[i] == '>'
				&& g_info->cmd->full_cmd[i + 1] == '<'))
		{
			printf("bash: unexpected token `%c'\n",
				g_info->cmd->full_cmd[i + 1]);
			rl_on_new_line();
			return (0);
		}
		i++;
		j++;
	}
	j++;
	while (g_info->cmd->full_cmd[i] && ft_isspace(g_info->cmd->full_cmd[i]))
		i++;
	if (!error_for_size_op(i))
		return (0);
	j = size_of_op(&i, j);
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
