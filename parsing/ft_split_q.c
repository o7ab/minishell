/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_q.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 04:46:39 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/10 20:33:42 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	wordscount_og(char *s, char c)
{
	int		i;
	int		words;
	int		flag;

	i = 0;
	words = 0;
	flag = 1;
	while (s[i])
	{
		i = incrementer(s, i);
		if (s[i] == c && !flag)
			flag = 1;
		else if (s[i] != c && flag)
		{
			words++;
			flag = 0;
		}
		if (s[i])
			i++;
	}
	return (words);
}

char	*wordscut_og(char *s, int len, int start)
{
	char	*c;
	int		i;

	i = 0;
	c = (char *)malloc(len + 1);
	if (!c)
		return (0);
	while (len > 0)
	{
		c[i++] = s[start - len];
		len--;
	}
	c[i] = '\0';
	return (c);
}

int	incrementer_2(char *s, int i, char c)
{
	char	cc;
	int		strl;

	strl = 0;
	while (s[i] != c && s[i])
	{
		if ((s[i] == 39 || s[i] == 34))
		{
			cc = s[i];
			strl++;
			i++;
			while (s[i] != cc && s[i])
			{
				i++;
				strl++;
			}
		}
		if (s[i] && s[i] != c)
		{
			strl++;
			i++;
		}
	}
	return (strl);
}

void	wordsplit_og(char **strs, char c, char *s, int words)
{
	int		i;
	int		strl;
	int		word;

	i = 0;
	word = 0;
	strl = 0;
	while (word < words)
	{
		while (s[i] && s[i] == c)
			++i;
		strl = incrementer_2(s, i, c);
		i += strl;
		strs[word++] = wordscut_og(s, strl, i);
		strl = 0;
	}
	strs[word] = 0;
}

char	**ft_split_q(char *s, char c)
{
	char	**a;
	int		words;

	if (!s)
		return (0);
	words = wordscount_og(s, c);
	a = (char **)malloc((words + 1) * sizeof(char *));
	if (!a)
		return (0);
	wordsplit_og(a, c, s, words);
	return (a);
}
