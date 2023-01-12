/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:05:11 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/14 16:46:20 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*join_help(char *ret, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != 0)
		ret[i++] = s2[j++];
	ret[i] = 0;
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		s1 = ft_strdup("");
	ret = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret = join_help(ret, s1, s2);
	free(s1);
	return (ret);
}
