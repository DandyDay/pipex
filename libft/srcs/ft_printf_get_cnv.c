/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cnv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:10:28 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/16 16:13:40 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_flag	get_flag(const char *s)
{
	t_flag	flag;

	flag.left = False;
	flag.prefix = False;
	flag.sign = False;
	flag.space = False;
	flag.zero = False;
	while (ft_strchr("-+ #0", *s) != 0)
	{
		if (*s == '-')
			flag.left = True;
		else if (*s == '+')
			flag.sign = True;
		else if (*s == ' ')
			flag.space = True;
		else if (*s == '#')
			flag.prefix = True;
		else if (*s == '0')
			flag.zero = True;
		s++;
	}
	return (flag);
}

t_cnv	get_cnv(const char *s)
{
	t_cnv	cnv;

	cnv.is_precision = False;
	cnv.precision = 1;
	cnv.flag = get_flag(s);
	while (ft_strchr("-+ #0", *s) != 0)
		s++;
	cnv.width = ft_atoi(s);
	while (ft_strchr("0123456789", *s))
		s++;
	if (*s == '.')
	{
		cnv.is_precision = True;
		cnv.precision = ft_atoi(++s);
	}
	while (ft_strchr("0123456789", *s))
		s++;
	cnv.specifier = *s;
	return (cnv);
}
