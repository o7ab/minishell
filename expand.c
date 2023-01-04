/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:32:50 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/04 17:16:37 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_var(char *var, int i)
{
	if (!var)
		return (0);
	if (ft_isdigit(var[i]) == 1 || var[i] == '_')
		return (0);
	while (var[i] != '\0')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			break;
		i++;
	}
	if (var[i] == '\0' || var[i] == 34 || ft_isspace(var[i]) == 1 
		|| var[i] == 39 || var[i] == '>' || var[i] == '<')
			return (i);
	return (0);
}

char	*var_error(char *str)
{
	int		i;
	char	*tmp;
	char 	*tmp2;

	i = 0;
	if (ft_isdigit(str[i]) == 1)
		return (ft_substr(str, 1, ft_strlen(str)));
	if (str[i] == '_')
		return (ft_strdup(""));
	while (str[i] != '\0' && ft_isalnum(str[i]) == 1 && str[i] != '_')
		i++;
	if (str[i] != 0 && i == 0 && (str[i] == 34 || str[i] == 39))
		return (str);
	if (str[i] != 0 && i == 0 && ft_isalnum(str[i]) == 0 && str[i] != '_')
	{
		tmp2 = ft_strdup("$");
		tmp = ft_substr(str, 0, ft_strlen(str));
		tmp = ft_strjoin(tmp2, tmp);
		return (tmp);	
	}
	if (str[i] != '\0' && ft_isalnum(str[i]) == 0 && str[i] != '_')
		return (ft_substr(str, i, ft_strlen(str) - i));
	return (ft_strdup(""));
}

char	*get_env(char *str)
{
	int		i;
	char	*var;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp2 = NULL;
	if (!str)
		return (NULL);
	i = check_if_var(str, i);
	if (!i)
		return (var_error(str));
	tmp = ft_substr(str, i, ft_strlen(str) - i);
	var = ft_substr(str, 0, i + 1);
	var[i] = '=';
	i = 0;
	while (g_info->env[i])
	{
		if (ft_strncmp(var, g_info->env[i], ft_strlen(var)) == 0)
		{
			tmp2 = ft_substr(g_info->env[i], ft_strlen(var), ft_strlen(g_info->env[i]) - ft_strlen(var));
			tmp = ft_strjoin(tmp2, tmp);
			break ;
		}
		i++;
	}
	free(var);
	return (tmp);
}

char	*check_env(char *str)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, 0, i);
			tmp2 = ft_substr(str, i + 1, ft_strlen(str) - i);
			free(str);
			str = ft_strjoin(tmp, get_env(tmp2));
		}
		if (str[i] && str[i] != '$')
			i++;
	}
	return (str);
}