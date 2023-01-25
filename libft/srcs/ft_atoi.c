/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:59:02 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/10 12:58:18 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		if (result < 0 && sign > 0)
			return (-1);
		else if (result < 0 && sign < 0)
			return (0);
	}
	return ((int)sign * result);
}
