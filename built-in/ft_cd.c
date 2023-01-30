/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 03:53:26 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	change_env("OLDPWD", cwd, 0);
	if (chdir(g_info->cmd->s_cmd[1]) != 0)
		perror("cd");
	cwd = getcwd(NULL, 0);
	change_env("PWD", cwd, 0);
}
