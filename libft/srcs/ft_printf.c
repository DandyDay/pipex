/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:35:01 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/16 16:22:59 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_cnv	cnv;
	int		len;
	int		templen;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			cnv = get_cnv(++fmt);
			fmt = ft_strchr(fmt, cnv.specifier) + 1;
			templen = print_cnv(cnv, ap);
		}
		else
			templen = write(1, fmt++, 1);
		if (templen < 0)
			return (-1);
		len += templen;
	}
	va_end(ap);
	return (len);
}
