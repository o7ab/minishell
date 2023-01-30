/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excution_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 02:55:14 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	ft_create_fd(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (g_info->cmd->s_cmd == NULL || g_info->cmd->s_cmd[0] == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (g_info->n_cmd > 1)
		g_info->fd = malloc((g_info->n_cmd - 1) * sizeof(int *));
	while (j < g_info->n_cmd - 1)
	{
		g_info->fd[j] = malloc(2 * sizeof(int));
		j++;
	}
	while (i < g_info->n_cmd - 1)
	{
		if (pipe(g_info->fd[i]) < 0)
			ft_error();
		i++;
	}
	return (0);
}

void	excute_command(void)
{
	char	*path;

	if (check_built_in(g_info->cmd->s_cmd[0]) == 1)
	{
		path = ft_getenv("PATH");
		if (path != NULL)
		{
			if (put_cmd_in_path(g_info->cmd->s_cmd[0], path) == NULL)
			{
				if (execve(g_info->cmd->s_cmd[0], g_info->cmd->s_cmd, NULL) < 0)
					ft_error();
			}
			else
				if (execve(put_cmd_in_path(g_info->cmd->s_cmd[0], path),
						g_info->cmd->s_cmd, NULL) < 0)
					ft_error();
		}
	}
	else
		excute_built_in(g_info->cmd->s_cmd[0]);
}

char	*ft_put_path(int len_path, int len_cmd, char *sp, char *cmd)
{
	char	*cmd_with_cmd;
	int		l;
	int		m;

	m = -1;
	l = -1;
	cmd_with_cmd = malloc((len_cmd + len_path + 2) * sizeof(char));
	while (++l < len_path)
		cmd_with_cmd[l] = sp[l];
	cmd_with_cmd[l++] = '/';
	while (++m < len_cmd)
		cmd_with_cmd[l++] = cmd[m];
	cmd_with_cmd[l] = '\0';
	return (cmd_with_cmd);
}

char	*put_cmd_in_path(char *cmd, char *path)
{
	char	**sp;
	int		i;
	char	*cmd_with_cmd;
	int		len_path;
	int		len_cmd;

	i = 0;
	sp = ft_split_set(path, ":");
	len_cmd = ft_strlen(cmd);
	while (sp[i])
	{
		len_path = ft_strlen(sp[i]);
		cmd_with_cmd = ft_put_path(len_path, len_cmd, sp[i], cmd);
		if (access(cmd_with_cmd, F_OK) == 0)
			return (cmd_with_cmd);
		i++;
		free(cmd_with_cmd);
	}
	return (NULL);
}
