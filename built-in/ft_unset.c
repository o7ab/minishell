/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 04:01:51 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**del_key(int index)
{
	char	**new;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (g_info->env[len])
		len++;
	len = len - 1;
	new = malloc(sizeof(char *) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i == index)
			new[i] = ft_strdup(g_info->env[i + 1]);
		else
			new[i] = ft_strdup(g_info->env[i]);
		i++;
	}
	new[i] = NULL;
	free_double(g_info->env);
	g_info->env = new;
	return (new);
}

void	ft_unset_env(void)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 1;
	index = 0;
	while (g_info->cmd->s_cmd[j])
	{
		while (g_info->cmd->s_cmd[j][i] != '=' && g_info->cmd->s_cmd[j][i])
			i++;
		i = 0;
		while (g_info->env[i])
		{
			if ((ft_strncmp(g_info->env[i], ft_var(i, j),
						ft_strlen(ft_var(i, j)))) == 0)
			{
				index = i;
				break ;
			}
			i++;
		}
		del_key(index);
		j++;
	}
}

void	ft_unset(void)
{
	if (g_info->cmd->s_cmd[1])
		ft_unset_env();
}
