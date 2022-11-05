/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:03:02 by oabushar          #+#    #+#             */
/*   Updated: 2022/11/05 18:17:00 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit()
{
	printf("There was an error in the arguements\n");
	exit(1);
}

void	lst_add(t_node **list, int t, char *str)
{
	t_node	*new;
	t_node	*ptr;

	new = ((t_node *) malloc (sizeof(t_node)));
	if (!new)
		return ;
	new->type = t;
	new->next = NULL;
	if (!(*list))
		*list = new;
	else
	{
		ptr = *list;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}

// int	check_valid(t_info *info)
// {
// 	int		i;
// 	char	*words;

// 	i = 0;
// 	words = "echo cd pwd unset exit export env";
// 	if (!ft_strnstr(words, info->split[i], 34))
// 		return (0);
// 	if (!ft_strnstr(words, info->split[i], 34))
// 		return (0);
// 	if (!ft_strnstr(words, info->split[i], 34))
// 		return (0);
// 	if (!ft_strnstr(words, info->split[i], 34))
// 		return (0);
// 	if (!ft_strnstr(words, info->split[i], 34))
// 		return (0);
// 	if (!ft_strnstr(words, info->split[i], 34))
// 		return (0);
// 	if (!ft_strnstr(words, info->split[i], 34))
// 		return (0);
// 	return (1);
// }

void	parse_space(t_node *list)
{
	lst_add(&list, SPC, " ");
}

void parse_pipe(t_node *list)
{
	lst_add(&list, PIPE, "|");
}

char	*get_str(t_info *info, int index)
{
	char	*str;
	int		i;
	int		store;

	i = 0;
	store = index;
	while (info->line[index] != 39 && info->line[index])
	{
		i++;
		index++;
	}
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (info->line[store] != 39 && info->line[store])
		str[i++] = info->line[store++];
	
}

void	parse_quotes(t_node *list, t_info *info, int index)
{
	char *str;

	if (info->line[index] == 39)
	{
		if (info->line[index] + 1 != 39)
		{
			str = get_str(info, index + 1);
			lst_add(&list, QUOTES, str);
		}
			return;
	}
	else if (info->line[index] == '"')
	{
		if (info->line[index] + 1 != '"')
		{
			info->line[index];
		}
	}
}
// int	parse_line(t_info *info, t_node *list)
// {
// 	int		i;	
// 	i = 0;
// 	while (info->line[i])
// 	{
// 		if (info->line[i] == ' ')
// 			parse_space(list);
// 		else if (info->line[i] == '|')
// 			parse_pipe(list);
// 		else if (info->line[i] == 34 || info->line[i] == 39)
// 			parse_quotes(list, info, i);
// 		else if (ft_isprint(info->line[i]))
// 			parse_word(info);
// 		i++;
// 	}
// 	return (1);
// }

int	parse_line(t_info *info, t_cmd *input)
{
	int i;

	i = 0;
	input->cmd
}

int main(void)
{
	// char buf[1024];
	t_info	info;
	t_cmd	input;
	// t_node list;
	while (1)
	{
		printf("%s", PURPLE);
		info.line = readline("minishell> \033[0m");
		parse_line(&info, &cmd);
	}
}