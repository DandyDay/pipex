/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:15:54 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/23 14:19:54 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static char	**get_paths(char	**envp)
{
	char	*raw_path;
	char	**ret;

	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			raw_path = *envp;
		envp++;
	}
	ret = ft_split(raw_path + 5, ':');
	if (!ret)
		exit(-1);
	return (ret);
}

char	*get_valid_bin(char **envp, char *binname)
{
	char	**paths;
	char	*tmp;

	paths = get_paths(envp);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		tmp = ft_strjoin(tmp, binname);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		paths++;
	}
	return (0);
}