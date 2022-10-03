/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:39:17 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/13 20:25:58 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	j;

	i = ft_strlen((char *)str);
	j = (char)c;
	if (c == 0)
	{
		return ((char *)str + ft_strlen((char *)str));
	}
	while (i != INT_MAX)
	{
		if (str[i] == j)
		{
			return ((char *)str + i);
		}
		i--;
	}
	return (0);
}
