/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:43:33 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/07 13:59:14 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include "ft_strlen.c"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = ((unsigned char *)s);
	i = 0;
	while (n > 0)
	{
		if ((unsigned char)c == str[i])
		{
			return (str + i);
		}
		i++;
		n--;
	}
	return (0);
}
