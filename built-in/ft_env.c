/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar <omar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:02:24 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/30 03:56:02 by omar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*remove_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
	{
		i++;
	}
	i++;
	return ((char *)&str[i]);
}

char	*ft_env(void)
{
	int	i;

	i = 0;
	while (g_info->env[i])
	{
		printf("%s\n", g_info->env[i]);
		i++;
	}
	return (NULL);
}
