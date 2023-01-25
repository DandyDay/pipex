/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:02:57 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/08 22:25:15 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_numlen(int n)
{
	if (0 <= n && n <= 9)
		return (1);
	return (get_numlen(n / 10) + 1);
}

static void	itoa_recursive(char *ret, int n)
{
	*ret-- = '0' + n % 10 * ((n > 0) - (n < 0));
	if (-10 < n && n < 0)
		*ret = '-';
	if (-9 > n || n > 9)
		itoa_recursive(ret, n / 10);
}

char	*ft_itoa(int n)
{
	char	*ret;

	ret = (char *)ft_calloc((get_numlen(n) + 1), sizeof(char));
	if (!ret)
		return (0);
	itoa_recursive(ret + get_numlen(n) - 1, n);
	return (ret);
}
