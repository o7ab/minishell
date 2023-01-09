/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:29:51 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/05 15:03:17 by oabushar         ###   ########.fr       */
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

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

char	**alloc_env(char **env)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	while (env[j])
	{
		new_env[j] = ft_strdup(env[j]);
		if (!new_env[j])
		{
			free_env(new_env);
			return (NULL);
		}
		j++;
	}
	new_env[j] = NULL;
	return (new_env);
}

void	init_input(void)
{
	g_info->n_cmd = num_cmds();
	g_info->cmd->flag = NULL;
	g_info->cmd->files = NULL;
	g_info->cmd->redir = NULL;
	g_info->cmd->full_cmd = NULL;
	g_info->cmd->full_op = NULL;
	g_info->cmd->s_cmd = NULL;
	g_info->cmd->new_cmd = NULL;
}
