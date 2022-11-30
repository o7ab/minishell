/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:50:51 by oabushar          #+#    #+#             */
/*   Updated: 2022/11/30 14:47:19 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_rest(t_info *info)
{
	int		i;
	int		count;
	char	*rest;
	int		r;

	i = 0;
	count = 0;
	r = 0;
	while(info->line[i] && info->line[i] != '|')
		i++;
	if (!info->line[i])
		return (NULL);
	if (info->line[i] == '|')
		i++;
	rest = malloc (sizeof(char) * ft_strlen(info->line) - i + 1);
	if (!rest)
		return (NULL);
	while (info->line[i])
		rest[r++] = info->line[i++];
	rest[r] = '\0';
	return (rest);
}

int alloc_quotes(char *line, int index)
{
	int		m;
	char	c;

	m = 0;
	if (!line || !line[index])
		return (0);
	while (line[index])
	{
		if (line[index] == 34 || line[index] == 39)
		{
			c = line[index++];
			while (line[index] != c && line[index])
			{
				index++;
				m++;
			}
		}
		if (line[index] != c && line[index])
			m++;
		index++;
	}
	return (m);
}

char *get_quotes(t_info *info, int index)
{
	char	c;
	int		m;
	char	*ret;
	
	c = 0;
	if (info->line[index] && (info->line[index] == 34 || info->line[index] == 39))
		c = info->line[index];
	m = alloc_quotes(info->line, index);
	if (!m)
		return (NULL);
	ret = malloc(m + 1);
	m = 0;
	while (info->line[index])
	{
		while (info->line[index] != 34 && info->line[index] != 39)
			ret[m++] = info->line[index++];
		if (info->line[index] == 39 || info->line[index] == 34)
			c = info->line[index++];
		while (info->line[index] && info->line[index] != c)
			ret[m++] = info->line[index++];
	}
	return (ret);
}

char	*get_cmd(t_info *info)
{
	int		i;
	int		m;
	char	*str;

	i = 0;
	m = 0;
	if (!info->line[i])
		return NULL;
	while (info->line[i] == 32)
		i++;
	while (info->line[i] && ft_isalpha(info->line[i]))
	{
		m++;
		i++;
	}
	str = malloc (sizeof(char) * m + 1);
	if (!str)
		return (NULL);
	i = 0;
	m = 0;
	while (info->line[i] == 32)
		i++;
	while (info->line[i] && ft_isalpha(info->line[i]))
	{
		str[m++] = info->line[i++];
	}
	str[m] = 0;
	return (str);
}

char	*copy_arg(t_info *info, int i)
{
	char	*ret;
	int		store;

	store = i;
	while(info->line[store] && info->line[store] != '>' && info->line[store] != '|')
	{
		if (info->line[store] == 34 || info->line[store] == 39)
		{
			ret = get_quotes(info, i);
			return (ret);
		}
		store++;
	}
	ret = (char *) malloc(store - i + 1);
	if (!ret)
		return (NULL);
	store = 0;
	while(info->line[i] && info->line[i] != '>' && info->line[i] != '|')
		ret[store++] = info->line[i++];
	ret[store] = '\0';
	return (ret);
}

char *get_arg(t_info *info, t_cmd *input)
{
	int		i;
	char	*arg;

	i = 0;
	while (info->line[i] && info->line[i] == 32)
		i++;
	while (info->line[i] && ft_isalpha(info->line[i]))
		i++;
	if (info->line[i++] != 32)
		return (NULL);
	if (info->line[i] == '-' && info->line[i + 1] == 'n')
	{
		input->flag = "-n";
		i += 2;
	}
	arg = copy_arg(info, i);
	return (arg);
}

void	get_list(t_cmd *input, t_info *info)
{
	int i;

	i = 0;
	input->cmd = get_cmd(info);
	if (input->cmd == NULL)
		return ;
	input->arg = get_arg(info, input);
	info->line = get_rest(info);
	printf(" the cmd is: %s\n", input->cmd);
	printf(" the arg is: %s\n", input->arg);
}

void	lst_add(t_cmd **list, t_info *info)
{
	t_cmd	*new;
	t_cmd	*ptr;

	new = ((t_cmd *) malloc (sizeof(t_cmd)));
	if (!new)
		return ;
	new->next = NULL;
	get_list(new, info);
	// printf("%s \n", new->cmd);
	if (!(*list))
		*list = new;
	else
	{
		ptr = *list;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

int	num_cmds(t_info *info)
{
	int		count;
	int		i;
	char	q;

	i = 0;
	count = 1;
	while (info->line[i])
	{
		if (info->line[i] == '|')
			count++;
		if (info->line[i] == 39 || info->line[i] == 34)
		{
			q = info->line[i++];
			while (info->line[i] != q && info->line[i])
				i++;
			if (info->line[i] != q)
				info->open_q = 1;
		}
		i++;
	}
	return (count);
}