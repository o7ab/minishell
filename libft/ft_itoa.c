/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 00:51:03 by oabushar          #+#    #+#             */
/*   Updated: 2021/12/25 13:34:50 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_digitdet(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char	*ft_place(char *ret, int nbr, int digits)
{
	while (nbr != 0)
	{
		digits--;
		ret[digits] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		digits;

	digits = ft_digitdet(n);
	ret = ft_calloc (digits + 1, 1);
	if (!ret)
		return (0);
	if (n == -2147483648)
	{
		digits--;
		ret[digits] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	if (n == 0)
		ret[0] = '0';
	ret = ft_place(ret, n, digits);
	return (ret);
}
