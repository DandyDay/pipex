/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:49:16 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/07 23:38:14 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cursor;

	cursor = (unsigned char *)b;
	while (len > 0)
	{
		*cursor++ = (unsigned char)c;
		len--;
	}
	return (b);
}
