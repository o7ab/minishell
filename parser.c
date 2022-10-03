/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:03:02 by oabushar          #+#    #+#             */
/*   Updated: 2022/10/03 09:53:44 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit()
{
	printf("There was an error in the arguements\n");
	exit(1);
}

// int	my_cmp(char *s1, char *s2, size_t n)
// {
// 	while (*s1 && *s2 && n > 0)
// 	{
// 		if (*s1 != *s2)
// 		{
// 			break ;
// 		}
// 		s1++;
// 		s2++;
// 		n--;
// 	}
// 	if (n <= 0)
// 		return (0);
// 	if ((unsigned char)*s1 - (unsigned char)*s2)
// 	{
// 		// printf("error %d, 1 is '%c', 2 is '%s'", (unsigned char)*s1 - (unsigned char)*s2, *s1, s2);
// 		return(-420);
// 	}
// 	return ((unsigned char)*s1 - (unsigned char)*s2);
// }

int	check_valid(t_info *info)
{
	int		i;
	char	*words;

	i = 0;
	words = "echo cd pwd unset exit export env";
	if (!ft_strnstr(words, info->split[i], 34))
		return (0);
	if (!ft_strnstr(words, info->split[i], 34))
		return (0);
	if (!ft_strnstr(words, info->split[i], 34))
		return (0);
	if (!ft_strnstr(words, info->split[i], 34))
		return (0);
	if (!ft_strnstr(words, info->split[i], 34))
		return (0);
	if (!ft_strnstr(words, info->split[i], 34))
		return (0);
	if (!ft_strnstr(words, info->split[i], 34))
		return (0);
	return (1);
}

int	parse_line(t_info *info)
{
	info->split = ft_split(info->line, ' ');
	if (!check_valid(info))
	{
		return (0);
	}
	return (1);
}

int main(void)
{
	// char buf[1024];
	t_info info;
	while (1)
	{
		printf("%s", PURPLE);
		info.line = readline("minishell> \033[0m");
		if (parse_line(&info))
		{
			
		}
	}
}