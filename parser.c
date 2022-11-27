/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:03:02 by oabushar          #+#    #+#             */
/*   Updated: 2022/11/21 23:34:53 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit()
{
	printf("There was an error in the arguements\n");
	exit(1);
}

void	parse_line(t_info *info, t_cmd *input)
{
	int i;

	i = 0;
	info->open_q = 0;
	input = (NULL);
	info->n_cmd = num_cmds(info);
	while (i < info->n_cmd)
	{
		lst_add(&input, info);
		i++;
	}
	// printf("%s \n", input->cmd);
	// input = input->next;
	// printf("%s \n", input->cmd);

}

int	main(void)
{
	// char buf[1024];
	t_info	info;
	t_cmd	input;
	while (1)
	{
		printf("%s", PURPLE);
		info.line = readline("minishell> \033[0m");
		parse_line(&info, &input);
	}
	return 0;
}