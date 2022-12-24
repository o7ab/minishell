/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:29:51 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/22 20:48:33 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_word(char *str, int i)
{
	char	c;

	c = 0;
	while (str[i] && !ft_isspace(str[i]) && str[i] != '>' && str[i] != '<')
	{
		if (str[i] == 34 || str[i] == 39)
		{
			c = str[i++];
			while (str[i] != c)
				i++;
		}
		i++;
	}
	return (i);
}