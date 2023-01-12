/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabushar <oabushar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:58:31 by oabushar          #+#    #+#             */
/*   Updated: 2021/12/21 08:12:24 by oabushar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_lst;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		new_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new_lst;
	}
	*lst = 0;
}
