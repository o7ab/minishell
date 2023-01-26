/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:03:02 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/26 06:50:21 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse_cmds(void)
{
	int		i;
	t_cmd	*tmp;

	i = 0;
	tmp = g_info->cmd;
	g_info->first = g_info->cmd;
	while (i < g_info->n_cmd && g_info->split[i] && g_info->cmd)
	{
		init_input();
		g_info->cmd->full_cmd = ft_strdup(g_info->split[i++]);
		get_list();
		g_info->cmd = g_info->cmd->next;
	}
	g_info->cmd = tmp;
	i = 0;
	while (g_info->cmd && g_info->cmd->s_cmd)
	{ 
		while (g_info->cmd && g_info->cmd->s_cmd[i]) // in this line
		{
			printf("the s_cmd is (%s)\n", g_info->cmd->s_cmd[i]);
			i++;
		}
		i = 0;
		if (g_info->cmd->redir)
		{
			while (g_info->cmd && g_info->cmd->redir[i])
			{
				printf("the redir is (%s) and files is (%s)\n", g_info->cmd->redir[i], g_info->cmd->files[i]);
				i++;
			}
			i = 0;
		}
		g_info->cmd = g_info->cmd->next;
	}
	g_info->cmd = tmp;
}

void	get_list(void)
{
	int	i;

	i = 0;
	if (!get_redir())
	{
		free(g_info->cmd->full_cmd);
		return ;
	}
	get_short_cmd();
	if (!g_info->cmd->new_cmd)
		g_info->cmd->new_cmd = ft_strdup(g_info->cmd->full_cmd);
	free(g_info->cmd->full_cmd);
	g_info->cmd->s_cmd = ft_split_q(g_info->cmd->new_cmd, ' ');
	free(g_info->cmd->new_cmd);
	while (g_info->cmd->s_cmd[i])
	{
		g_info->cmd->s_cmd[i] = check_env(g_info->cmd->s_cmd[i]);
		g_info->cmd->s_cmd[i] = check_quotes(g_info->cmd->s_cmd[i]);
		i++;
	}
}

void	parse_line(void)
{
	int	i;

	i = 0;
	g_info->open_q = 0;
	g_info->split = ft_split_q(g_info->line, '|');
	g_info->n_cmd = num_cmds();
	while (i < g_info->n_cmd)
	{
		lst_add(&g_info->cmd);
		i++;
	}
	parse_cmds();
}

void	init_info(char **env)
{
	(void)env;
	// g_info->env = alloc_env(env);
	g_info->line = NULL;
	g_info->split = NULL;
	g_info->n_cmd = 0;
	g_info->open_q = 0;


}

void	excute()
{
	g_info->fd_out_save = dup(STDOUT_FILENO);
	g_info->fd_in_save = dup(STDIN_FILENO);
	one_pipe();
	if (dup2(g_info->fd_out_save, STDOUT_FILENO) < 0)
		ft_putstr_fd("Error",2);
	if (dup2(g_info->fd_in_save, STDIN_FILENO) < 0)
		ft_putstr_fd("Error",2);
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	g_info = ft_calloc(1, sizeof(t_info));
	g_info->env = alloc_env(env);
	while (1)
	{
		init_info(env);
		printf("%s", PURPLE);
		g_info->line = readline("minishell> \033[0m");
		if (g_info->line == NULL)
		{
			exit(1);
		}
		if (g_info->line == NULL)
			return (0);
		if (g_info->line[0] == 0)
			return (0);
		add_history(g_info->line);
		parse_line();
		excute();
		free_shell();
	}
	if (g_info->env)
		free_double(g_info->env);
	free (g_info);

	return (0);
}
