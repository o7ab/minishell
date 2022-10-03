/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:45:16 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/18 10:19:52 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "limits.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*ret;

	ret = (char *)s1;
	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[i]))
		i--;
	ret = ft_substr(s1, 0, i + 1);
	return (ret);
}

// int main()
// { 
// 	char *test = ft_strtrim("11111Hello World321", "123");
// 	printf("%s \n", test);
// 	return (0);
// }