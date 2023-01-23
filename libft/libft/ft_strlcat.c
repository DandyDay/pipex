/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinho <jinho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:53:48 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 01:08:22 by jinho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_idx;
	size_t	s_idx;
	size_t	dest_src_len;

	d_idx = 0;
	s_idx = 0;
	dest_src_len = ft_strlen(dst) + ft_strlen(src);
	if ((size_t)ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	while (dst[d_idx])
		d_idx++;
	while (src[s_idx] && d_idx < dstsize - 1)
		dst[d_idx++] = src[s_idx++];
	dst[d_idx] = 0;
	return (dest_src_len);
}
