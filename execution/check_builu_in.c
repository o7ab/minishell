/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builu_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 03:42:04 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_built_in(char *command)
{
	if (ft_strcmp(command, "echo") == 0)
		return (0);
	else if (ft_strcmp(command, "cd") == 0)
		return (0);
	else if (ft_strcmp(command, "env") == 0)
		return (0);
	else if (ft_strcmp(command, "pwd") == 0)
		return (0);
	else if (ft_strcmp(command, "export") == 0)
		return (0);
	else if (ft_strcmp(command, "unset") == 0)
		return (0);
	else if (ft_strcmp(command, "exit") == 0)
		return (0);
	else
		return (1);
}
