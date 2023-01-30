/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 03:51:01 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	change_flag(void)
{
	g_info->flag_long = 1;
	return (1);
}

int	ag_atoi(char *str)
{
	int				i;
	int				pon;
	unsigned int	num;

	num = 0;
	i = 0;
	pon = 1;
	if (str[i] == '-' || str[i] == '+')
		pon *= 1 - 2 * (str[i++] == '-');
	if (!ft_isdigit(str[i]))
		return (change_flag());
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		if (num > 2147483648 && pon == -1)
			return (change_flag());
		else if (num > 2147483647 && pon == 1)
			return (change_flag());
		i++;
	}
	return ((int)(pon * num));
}

int	check_first_arg(char *arg)
{
	int	i;
	int	max;
	int	check;

	check = 0;
	i = 0;
	max = ag_atoi(arg);
	if (max == 1 && g_info->flag_long == 1)
		return (1);
	while (arg[i])
	{
		if (ft_isalpha(arg[i]))
			check++;
		i++;
	}
	if (check)
		return (1);
	return (0);
}

void	free_and_exit(void)
{
	printf("exit \nbash: exit: numeric argument required\n");
	exit (255);
}

void	ft_exit(void)
{
	int	i;

	i = 1;
	if (g_info->cmd->s_cmd[1])
	{
		if (check_first_arg(g_info->cmd->s_cmd[i++]) == 0)
		{
			while (g_info->cmd->s_cmd[i])
				i++;
			if (i == 2)
			{
				g_info->return_code = ag_atoi(g_info->cmd->s_cmd[1]) % 256;
				exit(g_info->return_code);
			}
			if (i > 2)
			{
				ft_putstr_fd("exit\ntoo many arguments\n", 1);
				g_info->return_code = 1;
			}
		}
		else
			free_and_exit();
	}
	else
		exit(0);
}
