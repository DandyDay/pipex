/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_valid_bin_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:15:54 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/29 23:16:20 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "pipex_bonus.h"

static char	**get_paths(char **envp)
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
		exit(1);
	return (ret);
}

char	*get_valid_bin(char **envp, char *binname)
{
	char	**paths;
	char	**path;
	char	*command;

	if (binname[0] == '/' && access(binname, X_OK) == 0)
		return (binname);
	else if (binname[0] == '/')
		return (binname);
	paths = get_paths(envp);
	path = paths;
	while (*path)
	{
		command = ft_strsjoin(*path, "/", binname);
		if (access(command, X_OK) == 0)
		{
			free_strings(paths);
			return (command);
		}
		free(command);
		path++;
	}
	free_strings(paths);
	return (binname);
}
