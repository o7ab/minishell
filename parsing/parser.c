/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghazi <aghazi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:03:02 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/29 21:04:49 by aghazi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

void parse_cmds(void)
{
	int i;
	t_cmd *tmp;

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
}

void get_list(void)
{
	int i;

	i = 0;
	if (!get_redir())
	{
		free(g_info->cmd->full_cmd);
		return;
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

void parse_line(void)
{
	int i;

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

// void	init_info(char **env)
// {
// 	(void)env;
// 	g_info->line = NULL;
// 	g_info->split = NULL;
// 	g_info->n_cmd = 0;
// 	g_info->open_q = 0;
// 	g_info->return_code = 0;
// 	g_info->flag_long = 0;
// 	g_info->flag_expor = 0;
// }

void	excute()
{
	g_info->fd_out_save = dup(STDOUT_FILENO);
	g_info->fd_in_save = dup(STDIN_FILENO);
	one_pipe();
	if (dup2(g_info->fd_out_save, STDOUT_FILENO) < 0)
		ft_putstr_fd("Error", 2);
	if (dup2(g_info->fd_in_save, STDIN_FILENO) < 0)
		ft_putstr_fd("Error", 2);
	free_shell();
}

void sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		write(STDERR_FILENO, "  \n", 4);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	g_info = ft_calloc(1, sizeof(t_info));
	g_info->env = alloc_env(env);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	alloc_export();
	while (1)
	{
		init_info(env);
		printf("%s", PURPLE);
		g_info->line = readline("minishell> \033[0m");
		if (g_info->line == NULL)
		{
			free_shell();
			break;
		}
		if (g_info->line[0] == 0)
			continue;
		add_history(g_info->line);
		parse_line();
		excute();
	}
	free_info();
	return (0);
}
