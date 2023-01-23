/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:33:23 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/03 21:00:30 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_max(int a, int b)
{
	return (a * (a > b) + b * (a <= b));
}

char	*ft_strndup(const char *s1, size_t n)
{
	const size_t	srcsize = n + 1;
	char			*dest;
	size_t			idx;

	dest = (char *)ft_calloc(srcsize, sizeof(char));
	if (!dest)
		return (0);
	idx = 0;
	while (idx < n && s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	return (dest);
}
