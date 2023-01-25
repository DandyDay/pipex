/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chr_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:34:30 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/03 21:00:00 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*get_c_string(t_cnv cnv, va_list ap)
{
	char	*s;
	char	c;

	(void)cnv;
	c = (char)va_arg(ap, int);
	s = ft_calloc(2, sizeof(char));
	if (!s)
		return (0);
	s[0] = c;
	s[1] = 0;
	return (s);
}

char	*get_s_string(t_cnv cnv, va_list ap)
{
	char	*s;
	char	*param;
	int		paramlen;

	param = va_arg(ap, char *);
	if (param == 0)
	{
		if (cnv.is_precision)
			s = ft_strndup("(null)", cnv.precision);
		else
			s = ft_strdup("(null)");
		return (s);
	}
	paramlen = ft_strlen(param);
	if (cnv.is_precision && cnv.precision < paramlen)
		s = ft_strndup(param, cnv.precision);
	else
		s = ft_strdup(param);
	if (!s)
		return (0);
	return (s);
}

char	*get_percent_string(t_cnv cnv, va_list ap)
{
	char	*s;

	(void)cnv;
	(void)ap;
	s = ft_calloc(2, sizeof(char));
	if (!s)
		return (0);
	s[0] = '%';
	s[1] = 0;
	return (s);
}
