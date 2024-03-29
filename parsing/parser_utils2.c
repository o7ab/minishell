/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:29:51 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/29 21:04:08 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

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

void	init_info(char **env)
	{
	(void)env;
	// g_info->env = alloc_env(env);
	// g_info->pid = 1;
	g_info->line = NULL;
	g_info->split = NULL;
	g_info->n_cmd = 0;
	g_info->open_q = 0;
}

void	free_info()
{
	if (g_info->env)
		free_double(g_info->env);
	if (g_info->split)
		free_double(g_info->split);
	free (g_info);
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
			free_double(new_env);
			return (NULL);
		}
		j++;
	}
	new_env[j] = NULL;
	return(new_env);
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
