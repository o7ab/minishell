/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:36:18 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/04 10:36:27 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	incrementer(char *s, int i)
{
	char	c;

	if ((s[i] == 39 || s[i] == 34))
	{
		c = s[i];
		i++;
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return;
	while (str[i])
		free(str[i++]);
	free (str);
}

int	num_cmds(t_info *g_info)
{
	int		count;
	int		i;
	char	q;

	i = 0;
	count = 1;
	while (g_info->line[i])
	{
		if (g_info->line[i] == '|')
			count++;
		if (g_info->line[i] == 39 || g_info->line[i] == 34)
		{
			q = g_info->line[i++];
			while (g_info->line[i] != q && g_info->line[i])
				i++;
			if (g_info->line[i] != q)
				g_info->open_q = 1;
		}
		if (info->line[i])
			i++;
	}
	return (count);
}

void	lst_add(t_cmd **list)
{
	t_cmd	*new;
	t_cmd	*ptr;

	new = ((t_cmd *) malloc (sizeof(t_cmd)));
	if (!new)
		return ;
	new->next = NULL;
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