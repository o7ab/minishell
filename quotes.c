/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:05:02 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/02 13:11:11 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_quotes(char *str, int m)
{
	char	*ret;
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = malloc(m + 1);
	if (!ret)
		return (NULL);
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i++];
			while (str[i] != c && str[i])
				ret[j++] = str[i++];
		}
		if (str[i] && str[i] != 34  && str[i] != 39)
			ret[j++] = str[i];
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*copy_quotes(char *str, int i)
{
	int		j;
	char	c;

	j = 0;
	while (str[i])
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i++];
			while (str[i] != c && str[i])
			{
				i++;
				j++;
			}
		}
		if (str[i] != 34 && str[i] != 39 && str[i])
			j++;
		i++;
	}
	return (get_quotes(str, j));
}

char	*check_quotes(char *str)
{
	int		i;
	int		flag;
	char	*ret;

	i = 0;
	flag = 0;
	while (str[i] != 0)
	{
		if (str[i] == 34 || str[i] == 39)
		{
			flag = 1;
			i = incrementer(str, i);
		}
		if (str[i] != 0 && str[i] != 34 && str[i] != 39)
			i++;
	}
	i = 0;
	if (!flag)
		return (str);
	else
		ret = copy_quotes(str, i);
	return (ret);
}