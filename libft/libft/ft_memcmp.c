/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:57:19 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/07 14:57:31 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (((unsigned char *)s1)[idx] != ((unsigned char *)s2)[idx])
			return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
		idx++;
	}
	return (0);
}
