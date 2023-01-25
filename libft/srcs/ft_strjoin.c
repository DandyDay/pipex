/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinho <jinho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:02:01 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/11/09 00:59:21 by jinho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	const size_t	retsize = ft_strlen(s1) + ft_strlen(s2) + 1;

	ret = (char *)ft_calloc(retsize, sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, retsize);
	ft_strlcat(ret, s2, retsize);
	return (ret);
}
