/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:28 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/07 15:04:28 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*tmp_node;

	cur_node = *lst;
	while (cur_node)
	{
		tmp_node = cur_node;
		cur_node = cur_node->next;
		del(tmp_node->content);
		free(tmp_node);
	}
	*lst = 0;
}
