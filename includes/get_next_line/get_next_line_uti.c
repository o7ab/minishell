/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_uti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:18:15 by oabushar          #+#    #+#             */
/*   Updated: 2023/01/25 15:22:59 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*gnl_helper(char *store, int fd)
{
	int		bytes;
	char	*str;

	bytes = 1;
	while (bytes != 0 && !ft_strchr(store, '\n'))
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return(NULL);
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		str[bytes] = 0;
		store = ft_strjoin(store, str);
		free(str);
		str = NULL;
	}
	return (store);
}