/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinho <jinho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:01:19 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 13:24:35 by jinho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const size_t	srcsize = ft_strlen(s1) + 1;
	char			*dest;

	dest = (char *)ft_calloc(srcsize, sizeof(char));
	if (!dest)
		return (0);
	ft_memcpy(dest, s1, srcsize);
	return (dest);
}
