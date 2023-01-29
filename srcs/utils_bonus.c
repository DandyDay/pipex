/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:30:35 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/29 23:15:29 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strsjoin(char *s1, char *s2, char *s3)
{
	const int	strsize = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	char		*str;

	str = ft_calloc(strsize, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, strsize);
	ft_strlcat(str, s2, strsize);
	ft_strlcat(str, s3, strsize);
	return (str);
}

int	free_strings(char **strs)
{
	char	**tmp;

	tmp = strs;
	while (*strs)
	{
		free(*strs);
		strs++;
	}
	free(tmp);
	return (0);
}

void	perror_exit(char *err)
{
	perror(err);
	exit(1);
}
