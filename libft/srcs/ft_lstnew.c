/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:03:57 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/07 15:03:58 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
		return (0);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
