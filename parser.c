/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:03:02 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/04 17:19:14 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_exit()
{
	printf("There was an error in the arguements\n");
	exit(1);
}

void init_input()
{
	g_info->cmd->flag = NULL;
	g_info->cmd->files = NULL;
	g_info->cmd->redir = NULL;
	g_info->cmd->full_cmd = NULL;
	g_info->cmd->full_op = NULL;
	g_info->cmd->s_cmd = NULL;
	g_info->cmd->new_cmd = NULL;
}

void parse_cmds()
{
	int i;
	t_cmd *tmp;

	i = 0;
	tmp = g_info->cmd;
	while (i < g_info->n_cmd && g_info->split[i] && g_info->cmd)
	{
		init_input();
		g_info->cmd->full_cmd = ft_strdup(g_info->split[i++]);
		get_list();
		g_info->cmd = g_info->cmd->next;
	}
	g_info->cmd = tmp;
}

void get_list()
{
	int i;

	i = 0;
	if (!g_info->cmd)
		return;
	get_redir();
	if (!g_info->cmd->new_cmd)
		g_info->cmd->new_cmd = ft_strdup(g_info->cmd->full_cmd);
	g_info->cmd->s_cmd = ft_split_q(g_info->cmd->new_cmd, ' ');
	while (g_info->cmd->s_cmd[i])
	{
		g_info->cmd->s_cmd[i] = check_env(g_info->cmd->s_cmd[i]);
		g_info->cmd->s_cmd[i] = check_quotes(g_info->cmd->s_cmd[i]);
		i++;
	}
	// free_double(g_info->cmd->s_cmd);
	free_double(g_info->cmd->files);
	free_double(g_info->cmd->redir);
}

void parse_line()
{
	int i;

	i = 0;
	g_info->open_q = 0;
	g_info->cmd = (NULL);
	g_info->n_cmd = num_cmds();
	g_info->split = ft_split_q(g_info->line, '|');
	while (i < g_info->n_cmd)
	{
		lst_add(&g_info->cmd);
		i++;
	}
	parse_cmds();
}

void init_info(char **env)
{
	g_info->env = alloc_env(env);
	g_info->line = NULL;
	g_info->split = NULL;
	g_info->n_cmd = 0;
	g_info->open_q = 0;
}

// int test_fun(g_info->cmd)
// {
// 	int count = 0;
// 	while (in[count] != NULL)
// 		count++;
// 	return count;
// }

int main(int ac, char **av, char **env)
{
	t_cmd *input;

	(void)ac;
	(void)av;
	g_info = ft_calloc(1, sizeof(t_info));
	input = ft_calloc(1, sizeof(t_cmd));
	init_info(env);
	g_info->cmd = input;
	while (1)
	{
		printf("%s", PURPLE);
		g_info->line = readline("minishell> \033[0m");
		if (g_info->line == NULL)
			return 0;
		if (g_info->line[0] == 0)
			continue;
		add_history(g_info->line);
		parse_line();
		// test_fun(&input);
		get_path();
		one_pipe();
	}
	return 0;
}