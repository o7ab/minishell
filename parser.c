/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:03:02 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/29 14:40:11 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit()
{
	printf("There was an error in the arguements\n");
	exit(1);
}

void	init_input(t_cmd *input)
{
	input->cmd = NULL;
	input->arg = NULL;
	input->flag = NULL;
	input->files = NULL;
	input->redir = NULL;
	input->full_cmd = NULL;
	input->full_op = NULL;
	input->s_cmd = NULL;
	input->new_cmd = NULL;
}

void	parse_cmds(t_cmd **input, t_info **info)
{
	int	i;
	t_cmd *tmp;

	i = 0;
	tmp = *input;
	while (i < (*info)->n_cmd && (*info)->split[i] && *input)
	{
		init_input(*input);
		(*input)->full_cmd = (*info)->split[i++];
		get_list(*input, *info);
		*input = (*input)->next;
	}
	*input = tmp;
}

void	get_list(t_cmd *input, t_info *info)
{
	int i;

	i = 0;
	if (!input)
		return;
	(void)info;
	get_redir(input);
	get_short_cmd(input);
	input->s_cmd = ft_split_q(input->new_cmd, ' ');
	while (input->s_cmd[i])
	{
		check_env(input->s_cmd[i], input);
		i++;
	}
	
	// input->cmd = get_cmd(info);
	// if (input->cmd == NULL)
	// 	return ;
	free_double(input->files);
	free_double(input->redir);
}

void	parse_line(t_info **info, t_cmd **input)
{
	int i;

	i = 0;
	(*info)->open_q = 0;
	(*input) = (NULL);
	(*info)->n_cmd = num_cmds(*info);
	(*info)->split = ft_split_q((*info)->line, '|');
	while (i < (*info)->n_cmd)
	{
		lst_add(input);
		i++;
	}
	parse_cmds(input, info);
	i = 0;
	while (*input)
	{
		while ((*input)->s_cmd[i])
		{
			printf(" the s is (%s)\n", (*input)->s_cmd[i++]);
		}
		i = 0;
		(*input) = (*input)->next;
	}
}

void	init_info(t_info *info, char **env)
{
	info->env = alloc_env(env);
	info->line = NULL;
	info->split = NULL;
	info->n_cmd = 0;
	info->open_q = 0;
}

int	main(int ac, char **av, char **env)
{
	// char buf[1024];
	t_info	*info;
	t_cmd	*input;

	(void)ac;
	(void)av;
	info = ft_calloc(1, sizeof(t_info));
	input = ft_calloc(1, sizeof(t_cmd));
	init_info(info, env);
	while (1)
	{
		printf("%s", PURPLE);
		info->line = readline("minishell> \033[0m");
		add_history(info->line);
		parse_line(&info, &input);
	}
	return 0;
}