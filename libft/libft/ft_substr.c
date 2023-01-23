/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinho <jinho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:01:43 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 09:26:18 by jinho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	idx;
	size_t	retlen;

	if (start < ft_strlen(s))
	{
		if (start + len < ft_strlen(s))
			retlen = len;
		else
			retlen = ft_strlen(s) - start;
	}
	else
		retlen = 0;
	ret = (char *)ft_calloc(retlen + 1, sizeof(char));
	if (!ret)
		return (0);
	if (ft_strlen(s) <= start)
		return (ret);
	idx = 0;
	while (idx < len && s[start + idx])
	{
		ret[idx] = s[start + idx];
		idx++;
	}
	return (ret);
}
