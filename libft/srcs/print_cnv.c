/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cnv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:36:51 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/16 16:36:47 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static void	apply_zero_padding(char *ret, char *s, int location, int len)
{
	ft_strlcpy(ret, s, location + 1);
	ft_memset(ret + location, '0', len - ft_strlen(s));
	ft_strlcat(ret, s + location, len + 1);
}

char	*pad_zero(t_cnv cnv, char *s)
{
	char	*ret;
	size_t	len;
	size_t	strlen;

	strlen = ft_strlen(s);
	len = ft_max(strlen, cnv.width);
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	if (strlen < (size_t)cnv.width)
	{
		if (ft_strchr("Xx", cnv.specifier) && cnv.flag.prefix && strlen > 2)
			apply_zero_padding(ret, s, 2, len);
		else if (ft_strchr("di", cnv.specifier) && ft_strchr("+ -", s[0]))
			apply_zero_padding(ret, s, 1, len);
		else if (ft_strchr("diuxX%", cnv.specifier))
			apply_zero_padding(ret, s, 0, len);
	}
	free(s);
	return (ret);
}

void	print_padding(char c, int len)
{
	while (len)
	{
		write(1, &c, 1);
		len--;
	}
}

int	print_cnv(t_cnv cnv, va_list ap)
{
	char	*s;
	size_t	len;
	size_t	strlen;

	s = get_string(cnv, ap);
	if (!s)
		return (-1);
	strlen = ft_strlen(s);
	if (cnv.specifier == 'c' && *s == '\0')
		strlen = 1;
	len = ft_max(strlen, cnv.width);
	if (cnv.flag.left)
	{
		write(1, s, strlen);
		print_padding(' ', len - strlen);
	}
	else
	{
		print_padding(' ', len - strlen);
		write(1, s, strlen);
	}
	free(s);
	return (len);
}
