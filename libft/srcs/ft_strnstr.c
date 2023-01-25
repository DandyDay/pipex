/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinho <jinho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:57:45 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 01:10:42 by jinho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	needlelen;

	idx = 0;
	needlelen = ft_strlen(needle);
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[idx] && idx + needlelen <= len)
	{
		if (ft_strncmp(&haystack[idx], needle, needlelen) == 0)
			return ((char *)&haystack[idx]);
		idx++;
	}
	return (0);
}
