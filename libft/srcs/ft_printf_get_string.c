/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:11:03 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/16 16:38:58 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*check_zeropad(char *s, t_cnv cnv)
{
	size_t	strlen;
	size_t	len;

	strlen = ft_strlen(s);
	len = ft_max(strlen, cnv.width);
	if (!cnv.flag.left)
		if (len != strlen && cnv.flag.zero && !cnv.is_precision)
			s = pad_zero(cnv, s);
	return (s);
}

char	*get_string(t_cnv cnv, va_list ap)
{
	char	*s;

	if (cnv.specifier == 'c')
		s = get_c_string(cnv, ap);
	else if (cnv.specifier == 's')
		s = get_s_string(cnv, ap);
	else if (cnv.specifier == 'p')
		s = get_p_string(cnv, ap);
	else if (cnv.specifier == 'd' || cnv.specifier == 'i')
		s = get_d_string(cnv, ap);
	else if (cnv.specifier == 'u')
		s = get_u_string(cnv, ap);
	else if (cnv.specifier == 'x' || cnv.specifier == 'X')
		s = get_x_string(cnv, ap);
	else if (cnv.specifier == '%')
		s = get_percent_string(cnv, ap);
	else
		s = NULL;
	if (!s)
		return (NULL);
	s = check_zeropad(s, cnv);
	return (s);
}
