/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 02:37:17 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	excute_built_in(char *command)
{
	if (ft_strcmp(command, "echo") == 0)
		ft_echo();
	else if (ft_strcmp(command, "cd") == 0)
		ft_cd();
	else if (ft_strcmp(command, "env") == 0)
		ft_env();
	else if (ft_strcmp(command, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(command, "export") == 0)
		ft_export();
	else if (ft_strcmp(command, "unset") == 0)
		ft_unset();
	else if (ft_strcmp(command, "exit") == 0)
		ft_exit();
}
