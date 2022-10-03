/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:49:39 by oabushar          #+#    #+#             */
/*   Updated: 2022/03/22 16:36:37 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;
	size_t	result;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	result = (srclen + dstlen);
	if (dstsize <= dstlen)
	{
		result = (dstsize + srclen);
	}
	while (src[i] && dstsize > dstlen + 1)
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = 0;
	return (result);
}
