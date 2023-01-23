/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dec_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:34:45 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/03 21:00:08 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_ul_to_a(char *s, unsigned long abs, int strlen)
{
	while (strlen && s[strlen - 1] == 0)
	{
		s[strlen - 1] = abs % 10 + '0';
		abs /= 10;
		strlen--;
	}
}

char	*get_d_string(t_cnv cnv, va_list ap)
{
	char	*s;
	long	n;
	int		sign;
	int		strlen;

	n = (long)va_arg(ap, int);
	sign = 1;
	if (n < 0)
		sign = -1;
	strlen = ft_max(get_numlen_base(n * sign, "0123456789"), cnv.precision);
	if (sign == -1 || cnv.flag.sign || cnv.flag.space)
		strlen++;
	s = ft_calloc(strlen + 1, sizeof(char));
	if (!s)
		return (0);
	if (sign == -1)
		s[0] = '-';
	if (sign == 1 && cnv.flag.space)
		s[0] = ' ';
	if (sign == 1 && cnv.flag.sign)
		s[0] = '+';
	ft_ul_to_a(s, n * sign, strlen);
	return (s);
}

char	*get_u_string(t_cnv cnv, va_list ap)
{
	char			*s;
	unsigned int	n;
	int				strlen;

	n = va_arg(ap, unsigned int);
	strlen = ft_max(get_numlen_base(n, "0123456789"), cnv.precision);
	s = ft_calloc(strlen + 1, sizeof(char));
	if (!s)
		return (0);
	ft_ul_to_a(s, n, strlen);
	return (s);
}
