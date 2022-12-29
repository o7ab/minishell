/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:32:50 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/28 22:36:46 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *str, t_cmd *input)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	(void) input;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != ' ' && str[i] != 34 && str[i] != 39)
		i++;
	tmp = ft_substr(str, 0, i);
	tmp2 = get_env_value(tmp, input);
	free(tmp);
	return (tmp2);
}

void	check_env(char *str, t_cmd *input)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, 0, i);
			tmp2 = ft_substr(str, i + 1, ft_strlen(str) - i);
			free(str);
			str = ft_strjoin(tmp, get_env(tmp2, input));
			free(tmp);
			free(tmp2);
			i = 0;
		}
		i++;
	}
}