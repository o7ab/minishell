/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:49:24 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/14 12:27:52 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_for_size_op(t_cmd *input, int i)
{
	if (input->full_cmd[i] == '<' || input->full_cmd[i] == '>'
		|| input->full_cmd[i] == 0)
	{
		printf("bash: unexpected token `%c'\n", input->full_cmd[i]);
		rl_on_new_line();
		return (0);
	}
	return (1);
}

int	check_size_of_op(t_cmd *input, int i)
{
	int	j;

	j = 0;
	while (input->full_cmd[i] && input->full_cmd[i] == '>' && input->full_cmd[i] == '<' && j < 2)
	{
		if ((input->full_cmd[i] == '>' && input->full_cmd[i + 1] == '<'))
		{
			printf("bash: unexpected token `%c'\n", input->full_cmd[i + 1]);
			rl_on_new_line();
			return (0);
		}
		i++;
		j++;
	}
	j++;
	while (input->full_cmd[i] && ft_isspace(input->full_cmd[i]))
		i++;
	if (!error_for_size_op(input, i))
		return (0);
	j = size_of_op(input, i, j);
	
}