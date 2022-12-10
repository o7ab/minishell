/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:24:36 by oabushar          #+#    #+#             */
/*   Updated: 2022/12/10 22:59:08 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_copy_op(t_info *info, t_cmd *input, t_cmd *output, int i)
{
	int store;

	store = i;
	while (input->full_cmd[i])
	{
		while (!ft_isspace(input->full_cmd[i]) )
	}
}

void	get_redir(t_cmd *input, t_info *info)
{
	int	i;
	char 

	i = 0;
	while (input->full_cmd[i] && input->full_cmd[i] != '<' && input->full_cmd[i] != '>')
		i++;
	if (!input->full_cmd[i])
		return;
	while (input->full_cmd[i])
		i+= ft_copy_op(info, input, i);
}