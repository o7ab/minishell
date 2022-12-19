/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:02:39 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/19 17:27:15 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void get_short_cmd(t_cmd *input)
{
	int	i;
	int	m;
	int	x;
	int n_op;

	i = 0;
	m = 0;
	x = 0;
	m = skip_til_op(input->full_cmd, m);
	n_op = number_of_redir(input);
	while(x < n_op && input->full_cmd[i])
	{
		i = skip_til_op(input->full_cmd, i);
		skip_oop(input, &i);
		printf("loooop    (%s)\n", &input->full_cmd[i]);
		x++;
	}
	if (input->full_cmd[i])
		printf("%s\n", &input->full_cmd[i]);
	// else
	// 	printf("errorrrrrr\n");
}