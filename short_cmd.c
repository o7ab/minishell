/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:02:39 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/04 17:13:51 by oabushar         ###   ########.fr       */
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

int	copy_mid_arg(int *i, int m)
{
	char	c;

	c = 0;
	if (!g_info->cmd->full_cmd[*i])
		return (m);
	while (g_info->cmd->full_cmd[*i] && g_info->cmd->full_cmd[*i] != '>' && g_info->cmd->full_cmd[*i] != '<')
	{
		if (g_info->cmd->full_cmd[*i] == 39 || g_info->cmd->full_cmd[*i] == 34)
		{
			c = g_info->cmd->full_cmd[*i];
			g_info->cmd->new_cmd[m++] = g_info->cmd->full_cmd[(*i)++];
			while (g_info->cmd->full_cmd[*i] != c && g_info->cmd->full_cmd[*i])
				g_info->cmd->new_cmd[m++] = g_info->cmd->full_cmd[(*i)++];
		}
		g_info->cmd->new_cmd[m] = g_info->cmd->full_cmd[*i];
		(*i)++;
		m++;
	}
	return (m);
	
}

void	copy_short_cmd(int m, int n_op)
{
	int	i;
	int index;
	int	x;

	index = -1;
	g_info->cmd->new_cmd = malloc(m + 1);
	if (!g_info->cmd->new_cmd)
		return;
	i = skip_til_op(g_info->cmd->full_cmd, 0);
	x = 0;
	while (++index < i)
		g_info->cmd->new_cmd[index] = g_info->cmd->full_cmd[index];
	while (x < n_op) 
	{
		skip_oop(&index);
		x++;
		if (x == n_op)
			break;
		i = copy_mid_arg(&index, i);
	}
	while (g_info->cmd->full_cmd[index])
	{
		if (g_info->cmd->full_cmd[index] == ' ')
			g_info->cmd->new_cmd[i++] = g_info->cmd->full_cmd[index++];
		while (ft_isspace(g_info->cmd->full_cmd[index]) && g_info->cmd->full_cmd[index])
			index++;
		if (g_info->cmd->full_cmd[index])
			g_info->cmd->new_cmd[i++] = g_info->cmd->full_cmd[index++];
	}
	g_info->cmd->new_cmd[i] = 0;
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

void get_short_cmd(void)
{
	int	i;
	int	m;
	int	x;
	int n_op;

	i = 0;
	m = 0;
	x = 0;
	n_op = number_of_redir();
	if (!n_op)
		return ;
	i = skip_til_op(g_info->cmd->full_cmd, i);
	m = i;
	while(x < n_op && g_info->cmd->full_cmd[i])
	{
		skip_oop(&i);
		m += check_mid_arg(g_info->cmd->full_cmd, &i);
		x++;
	}
	while (g_info->cmd->full_cmd[i])
	{
		i++;
		while(ft_isspace(g_info->cmd->full_cmd[i]) && g_info->cmd->full_cmd[i])
			i++;
		m++;
	}
	copy_short_cmd(m, n_op);
	free(g_info->cmd->full_cmd);
}