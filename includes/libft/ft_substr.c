/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:30:03 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/23 10:51:10 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	srclen;

	i = 0;
	if (s)
		srclen = ft_strlen(s);
	else
		srclen = 0;
	if (len > srclen)
		len = srclen + 1;
	dest = (char *)malloc (sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	if (start < srclen)
	{
		while (i < len)
		{
			dest[i] = s[start];
			start++;
			i++;
		}
	}
	dest[i] = 0;
	return (dest);
}

// int main()
// {
// 	char a[] = "tripouille";
// 	printf("%s \n", ft_substr(a, 0, 42000));
// }