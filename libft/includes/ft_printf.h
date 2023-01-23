/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:35:59 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/16 16:09:01 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef enum e_bool
{
	False,
	True
}			t_bool;

typedef struct s_flag
{
	t_bool	left;
	t_bool	sign;
	t_bool	space;
	t_bool	prefix;
	t_bool	zero;
}				t_flag;

typedef struct s_cnv
{
	t_flag	flag;
	int		width;
	t_bool	is_precision;
	int		precision;
	char	specifier;
}				t_cnv;

int		ft_max(int a, int b);
char	*ft_strndup(const char *s1, size_t n);

char	*get_c_string(t_cnv cnv, va_list ap);
char	*get_s_string(t_cnv cnv, va_list ap);
char	*get_percent_string(t_cnv cnv, va_list ap);

void	ft_ul_to_a(char *s, unsigned long abs, int strlen);
char	*get_d_string(t_cnv cnv, va_list ap);
char	*get_u_string(t_cnv cnv, va_list ap);

void	convert_base(char *s, unsigned long abs, int strlen, char *base);
char	get_numlen_base(unsigned long abs, char *base);
char	*get_p_string(t_cnv cnv, va_list ap);
char	*get_x_string(t_cnv cnv, va_list ap);

char	*pad_zero(t_cnv cnv, char *s);
void	print_padding(char c, int len);
char	*get_string(t_cnv cnv, va_list ap);
int		print_cnv(t_cnv cnv, va_list ap);

t_flag	get_flag(const char *s);
t_cnv	get_cnv(const char *s);
int		ft_printf(const char *fmt, ...);

#endif
