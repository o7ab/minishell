/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:20:32 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/10 20:33:42 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	full_copy(int index, int i)
{
	while (g_info->cmd->full_cmd[index])
	{
		if (g_info->cmd->full_cmd[index] == ' ')
			g_info->cmd->new_cmd[i++] = g_info->cmd->full_cmd[index++];
		while (ft_isspace(g_info->cmd->full_cmd[index])
			&& g_info->cmd->full_cmd[index])
			index++;
		if (g_info->cmd->full_cmd[index])
			g_info->cmd->new_cmd[i++] = g_info->cmd->full_cmd[index++];
	}
	g_info->cmd->new_cmd[i] = 0;
}

void	short_help(int i, int m, int n_op)
{
	while (g_info->cmd->full_cmd[i])
	{
		i++;
		while (ft_isspace(g_info->cmd->full_cmd[i]) && g_info->cmd->full_cmd[i])
			i++;
		m++;
	}
	copy_short_cmd(m, n_op);
}
