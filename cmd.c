/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:50:51 by oabushar          #+#    #+#             */
/*   Updated: 2022/11/16 17:07:00 by oabushar         ###   ########.fr       */
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
	int r = 0;
	while(info->line[i] && info->line[i] != '|')
		i++;
	if (!info->line[i])
		return (NULL);
	if (info->line[i] == '|')
		i++;
	while (info->line[i])
		rest[r++] = info->line[i++];
	rest[r] = '\0';
	return (rest);
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
	info->line = get_rest();
	return (str);
}

void	get_list(t_cmd *input, t_info *info)
{
	int i;

	i = 0;
	input->cmd = get_cmd(info);
	printf(" the cmd is: %s\n", input->cmd);
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