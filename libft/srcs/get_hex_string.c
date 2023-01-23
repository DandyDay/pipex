/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:34:48 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/03 21:00:04 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	convert_base(char *s, unsigned long abs, int strlen, char *base)
{
	unsigned int	baselen;

	baselen = ft_strlen(base);
	while (strlen && s[strlen - 1] == 0)
	{
		s[strlen - 1] = base[abs % baselen];
		abs /= baselen;
		strlen--;
	}
}

char	get_numlen_base(unsigned long abs, char *base)
{
	unsigned int	baselen;

	baselen = ft_strlen(base);
	if (0 == abs)
		return (0);
	return (get_numlen_base(abs / baselen, base) + 1);
}

char	*get_p_string(t_cnv cnv, va_list ap)
{
	char			*s;
	unsigned long	n;
	void			*p;
	int				strlen;

	p = va_arg(ap, void *);
	n = (unsigned long)p;
	strlen = ft_max(get_numlen_base(n, "0123456789abcdef"), cnv.precision) + 2;
	s = ft_calloc(strlen + 1, sizeof(char));
	if (!s)
		return (0);
	s[0] = '0';
	s[1] = 'x';
	convert_base(s, n, strlen, "0123456789abcdef");
	return (s);
}

char	*get_x_string(t_cnv cnv, va_list ap)
{
	char			*s;
	unsigned int	n;
	int				numlen;
	int				strlen;
	char			*base;

	if (cnv.specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	n = va_arg(ap, unsigned int);
	numlen = get_numlen_base(n, base);
	strlen = ft_max(numlen, cnv.precision);
	if (cnv.flag.prefix && n != 0)
		strlen += 2;
	s = ft_calloc(strlen + 1, sizeof(char));
	if (!s)
		return (0);
	if (cnv.flag.prefix && n != 0)
	{
		s[0] = '0';
		s[1] = cnv.specifier;
	}
	convert_base(s, n, strlen, base);
	return (s);
}
