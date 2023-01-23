/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:02:19 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/13 20:20:26 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_retsize(char const *s1, char const *set)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (s1[idx] && ft_strchr(set, s1[idx]))
	{
		count++;
		idx++;
	}
	if (s1[idx] == 0)
		return (1);
	idx = ft_strlen(s1) - 1;
	while (s1[idx] && ft_strchr(set, s1[idx]))
	{
		count++;
		idx--;
	}
	return (ft_strlen(s1) - count + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ret;
	const size_t	retsize = get_retsize(s1, set);

	ret = (char *)ft_calloc(retsize, sizeof(char));
	if (!ret)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	ft_memcpy(ret, s1, retsize - 1);
	return (ret);
}
