/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:32:50 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/14 17:54:37 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_if_var(char *var, int i)
{
	if (!var)
		return (0);
	if (ft_isdigit(var[i]) == 1)
		return (0);
	while (var[i] != '\0')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			break ;
		i++;
	}
	if (!ft_isalnum(var[i]) && var[i] != '_')
		return (i);
	return (0);
}

char	*copy_env(char *var, char *tmp, int i)
{
	char	*tmp2;
	char	*test;

	tmp2 = (NULL);
	test = (NULL);
	tmp2 = ft_substr(g_info->env[i], ft_strlen(var),
			ft_strlen(g_info->env[i]) - ft_strlen(var));
	test = ft_strjoin(tmp2, tmp);
	free (tmp);
	return (test);
}

char	*get_env(char *str)
{
	int		i;
	char	*var;
	char	*tmp;

	i = 0;
	i = check_if_var(str, i);
	if (!i)
		return (var_error(str));
	tmp = ft_substr(str, i, ft_strlen(str) - i);
	var = ft_substr(str, 0, i + 1);
	free (str);
	var[i] = '=';
	i = 0;
	while (g_info->env[i])
	{
		if (ft_strncmp(var, g_info->env[i], ft_strlen(var)) == 0)
		{
			tmp = copy_env(var, tmp, i);
			break ;
		}
		i++;
	}
	// if (!g_info->env[i])
	// 	free (tmp);
	free(var);
	return (tmp);
}

int	inc_env(char *str, int i)
{
	if (str[i] == 39)
		i = incrementer(str, i);
	if (str[i] == '$' && str[i + 1] == '?')
		i++;
	if (str[i] && str[i] != '$')
		i++;
	return (i);
}

char	*check_env(char *str)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*var;

	i = 0;
	tmp = NULL;
	tmp2 = NULL;
	var = NULL;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, 0, i);
			tmp2 = ft_substr(str, i + 1, ft_strlen(str) - i);
			free(str);
			var = get_env(tmp2);
			str = ft_strjoin(tmp, var);
			free (var);
		}
		i = inc_env(str, i);
	}
	return (str);
}
