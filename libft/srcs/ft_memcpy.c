/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:50:41 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 14:47:45 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (idx < n)
	{
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		idx++;
	}
	return (dst);
}
