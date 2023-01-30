/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:55:42 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/30 16:13:48 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex.h"
#include "libft.h"

t_command	*new_command(char *raw_cmd, char **envp)
{
	t_command	*cmd;
	char		*valid_bin;

	cmd = ft_calloc(1, sizeof(t_command));
	if (!cmd)
		exit(1);
	cmd->argv = ft_split(raw_cmd, ' ');
	if (!cmd->argv)
		exit(1);
	valid_bin = get_valid_bin(envp, cmd->argv[0]);
	if (!valid_bin)
		exit(1);
	if (ft_strncmp(valid_bin, cmd->argv[0], ft_strlen(valid_bin)) != 0)
		free(cmd->argv[0]);
	cmd->argv[0] = valid_bin;
	if (pipe(cmd->fd) != 0)
		exit(1);
	return (cmd);
}

void	add_cmd_back(t_command **list, t_command *cmd)
{
	t_command	*tmp;

	if (!(*list))
		*list = cmd;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		cmd->idx = tmp->idx + 1;
		tmp->next = cmd;
		cmd->prev = tmp;
	}
}

void	clear_cmds(t_command **list)
{
	t_command	*cmd;
	t_command	*next;

	cmd = *list;
	while (cmd)
	{
		next = cmd->next;
		free_strings(cmd->argv);
		free(cmd);
		cmd = next;
	}
}

void	map_commands(t_command **list, int *fd, char **envp, \
					int (*f)(t_command *, int *, char**))
{
	t_command	*cmd;

	cmd = *list;
	while (cmd)
	{
		f(cmd, fd, envp);
		cmd = cmd->next;
	}
}
