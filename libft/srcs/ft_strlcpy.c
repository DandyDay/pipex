/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinho <jinho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:51:57 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 01:01:10 by jinho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	idx;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	idx = 0;
	while (idx < dstsize - 1 && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (srclen);
}
