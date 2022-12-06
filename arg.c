/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:45:07 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/06 02:44:52 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (info->line[i] && ft_isspace(info->line[i]))
		i++;
	while (info->line[i] && !ft_isspace(info->line[i]))
		i++;
	if (info->line[i] == '-' && info->line[i + 1] == 'n')
	{
		input->flag = "-n";
		i += 2;
	}
	arg = copy_arg(info, i);
	// printf("the args is (%s) and its length is (%d) \n", arg, (int)ft_strlen(arg));
	return (arg);
}
