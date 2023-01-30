/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utilties.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 02:48:23 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_is_inside(char *key)
{
	int	i;

	i = 0;
	while (g_info->env[i])
	{
		if ((ft_strncmp(g_info->env[i], key, ft_strlen(key))) == 0)
			return (i);
		i++;
	}
	return (0);
}

void	ft_change_value(int i, int m)
{
	int	j;

	j = 0;
	while (g_info->cmd->s_cmd[m][j])
		j++;
	g_info->env[i] = malloc((j + 1) * sizeof(char));
	j = 0;
	while (g_info->cmd->s_cmd[m][j])
	{
		g_info->env[i][j] = g_info->cmd->s_cmd[m][j];
		j++;
	}
	g_info->env[i][j] = '\0';
}

char	**ft_create_var(int len, char *key, int m)
{
	char	**new_envi;
	int		i;
	int		index;

	i = 0;
	new_envi = NULL;
	index = ft_is_inside(key);
	if (index == 0)
	{
		new_envi = malloc(sizeof(char *) * (len + 2));
		if (!new_envi)
			return (NULL);
		while (g_info->env[i])
		{
			new_envi[i] = g_info->env[i];
			i++;
		}
		new_envi[i] = ft_strdup(g_info->cmd->s_cmd[m]);
		i++;
		new_envi[i] = NULL;
		g_info->env = new_envi;
	}
	else
		ft_change_value(index, m);
	return (new_envi);
}

void	change_env(char *select, char *value, int j)
{
	int	i;

	i = 0;
	while (g_info->env[i])
	{
		if ((ft_strncmp(g_info->env[i], select, ft_strlen(select))) == 0)
		{
			add_env(select, value, i, j);
			break ;
		}
		i++;
	}
	add_env(select, value, i, j);
}
