/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:59:27 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/14 17:30:01 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*ret;

	len = count * size;
	if (count == 0 || size == 0 || len == 0)
		return (malloc(0));
	if (len / size != count)
		return (0);
	ret = malloc(len);
	if (!ret)
		return (0);
	ft_bzero(ret, len);
	return (ret);
}
