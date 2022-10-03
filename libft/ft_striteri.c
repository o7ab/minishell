/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:46:10 by oabushar          #+#    #+#             */
/*   Updated: 2021/10/19 09:52:55 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// void	funct(unsigned int i, char *c)
// {
// 	i = 32;
// 	*c += i;
// }

// int main()
// {
// 	char a[] = "hello";
// 	printf("%s \n", a);
// 	ft_striteri(a, funct);
// 	printf("%s \n", a);
// }