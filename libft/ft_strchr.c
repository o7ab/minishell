/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:23:01 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/13 20:25:31 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	j;

	j = (char) c;
	i = 0;
	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	while (s[i])
	{
		if (s[i] == j)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char a[] = "Hello";
// 	printf("%s \n", ft_strchr(a, 'l'));
// }