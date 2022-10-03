/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:02:41 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/19 09:52:58 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	i = 0;
	if (!s)
		return (0);
	dest = ((char *) malloc (sizeof(char) * ft_strlen(s) + 1));
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// char	funct(unsigned int i, char c)
// {
// 	i = 32;
// 	return (c - i);
// }
// int main()
// {
// 	char a[] = "hello";
// 	printf("%s \n", ft_strmapi(a, funct));
// }