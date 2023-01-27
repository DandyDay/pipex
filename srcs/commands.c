/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:55:42 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/27 16:02:57 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex.h"
#include "libft.h"

t_command	*new_command(char *raw_cmd, char **envp)
{
	t_command	*cmd;

	cmd = ft_calloc(1, sizeof(t_command));
	if (!cmd)
		exit(1);
	cmd->argv = ft_split(raw_cmd, ' ');
	cmd->argv[0] = get_valid_bin(envp, cmd->argv[0]);
	if (!cmd->argv)
		exit(1);
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
