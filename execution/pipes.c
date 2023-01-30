/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 02:34:19 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_quit(int signal)
{
	(void)signal;
	write(1, "Quit: 3\n", 9);
}

int	check_builtin(void)
{
	if (g_info->n_cmd == 1 && !check_built_in(g_info->cmd->s_cmd[0]))
	{
		redir();
		excute_built_in(g_info->cmd->s_cmd[0]);
		return (0);
	}
	return (1);
}

void	ft_child(int i)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (g_info->n_cmd > 1)
	{
		if (i != 0)
		{
			dup2(g_info->fd[i - 1][0], STDIN_FILENO);
			close(g_info->fd[i - 1][0]);
		}
		if (i + 1 < g_info->n_cmd)
		{
			dup2(g_info->fd[i][1], STDOUT_FILENO);
			close(g_info->fd[i][1]);
			close(g_info->fd[i][0]);
		}
	}
	redir();
	excute_command();
}

void	ft_parent(int i)
{
	if (i < g_info->n_cmd - 1)
		close(g_info->fd[i][1]);
	if (i > 0)
		close(g_info->fd[i - 1][0]);
}

int	one_pipe(void)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	if (ft_create_fd())
		return (1);
	if (check_builtin() == 0)
		return (0);
	while (i < g_info->n_cmd)
	{
		ft_start_sign();
		pid = fork();
		if (pid == 0)
			ft_child(i);
		else if (pid > 0)
			ft_parent(i);
		i++;
		g_info->cmd = g_info->cmd->next;
	}
	i = -1;
	while (++i < g_info->n_cmd)
		wait(NULL);
	sign();
	return (0);
}
