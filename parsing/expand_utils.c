/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:24:17 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/10 20:32:54 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*var_error_help(char *str, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = (NULL);
	tmp2 = (NULL);
	if (i == 0)
	{
		tmp = ft_strdup("$");
		tmp2 = ft_strdup(str);
		free (str);
		str = ft_strjoin(tmp, tmp2);
		free (tmp2);
		return (str);
	}
	if (i == 1)
	{
		tmp = ft_substr(str, 1, ft_strlen(str));
		free (str);
		return (tmp);
	}
	if (i == 2)
		free (str);
	return (ft_strdup(""));
}

char	*var_error(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str[i] == '?')
		return (var_error_help(str, 0));
	if (ft_isdigit(str[i]) == 1
		|| (!ft_isalnum(str[i]) && str[i] != '_' && str[i]))
		return (var_error_help(str, 1));
	if (str[i] == '_')
		return (var_error_help(str, 2));
	while (str[i] != '\0' && ft_isalnum(str[i]) == 1 && str[i] != '_')
		i++;
	if (str[i] != 0 && i == 0 && (str[i] == 34 || str[i] == 39))
		return (str);
	if (str[i] != '\0' && ft_isalnum(str[i]) == 0 && str[i] != '_')
	{
		tmp = ft_strdup(str);
		free (str);
		str = ft_substr(tmp, i, ft_strlen(str) - i);
		free (tmp);
		return (str);
	}
	free (str);
	return (ft_strdup(""));
}
