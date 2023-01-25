/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:51:20 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/07 14:51:31 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	if (dst == 0 && src == 0)
		return (dst);
	idx = 0;
	if (dst < src)
	{
		while (idx < len)
		{
			((char *)dst)[idx] = ((char *)src)[idx];
			idx++;
		}
	}
	else
	{
		while (idx < len)
		{
			((char *)dst)[len - 1 - idx] = ((char *)src)[len - 1 - idx];
			idx++;
		}
	}
	return (dst);
}
