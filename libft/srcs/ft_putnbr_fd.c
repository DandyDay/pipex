/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinho <jinho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:03:42 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 00:53:23 by jinho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putabs_fd(unsigned int abs, int fd)
{
	if (abs >= 10)
		ft_putabs_fd(abs / 10, fd);
	ft_putchar_fd(abs % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs;

	abs = n * ((n > 0) - (n < 0));
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putabs_fd(abs, fd);
}
