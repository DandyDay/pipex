/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinho <jinho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:03:13 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 01:09:58 by jinho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	idx;
	const size_t	retsize = ft_strlen(s) + 1;

	ret = (char *)ft_calloc(retsize, sizeof(char));
	if (!ret)
		return (0);
	idx = 0;
	while (s[idx])
	{
		ret[idx] = f(idx, s[idx]);
		idx++;
	}
	return (ret);
}
