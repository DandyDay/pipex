/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:11:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/27 17:15:45 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "pipex.h"

int	execute_command(t_command *cmd, int *fd, char **envp)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	if (pid == 0)
	{
		if (cmd->prev)
		{
			dup2(cmd->prev->fd[0], STDIN_FILENO);
			close(cmd->prev->fd[1]);
		}
		else
			dup2(fd[0], STDIN_FILENO);
		if (cmd->next)
		{
			dup2(cmd->fd[1], STDOUT_FILENO);
			close(cmd->fd[0]);
		}
		else
			dup2(fd[1], STDOUT_FILENO);
		if (execve(cmd->argv[0], cmd->argv, envp) < 0)
			exit(1);
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
		if (cmd->prev)
		{
			close(cmd->prev->fd[0]);
			close(cmd->prev->fd[1]);
		}
		if (!cmd->next)
		{
			close(cmd->fd[0]);
			close(cmd->fd[1]);
		}
		if (WIFEXITED(status))
			ret = WEXITSTATUS(status);
	}
	return (ret);
}

int	main(int argc, char **argv, char **envp)
{
	int			fd[2];
	int			idx;
	t_command	*list;

	// if (argc != 5)
	// 	return (1);
	if (access(argv[1], R_OK) || (access(argv[argc - 1], W_OK) && !access(argv[argc - 1], F_OK)))
		exit(1);
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	idx = 1;
	list = NULL;
	while (++idx < argc - 1)
		add_cmd_back(&list, new_command(argv[idx], envp));
	while (list)
	{
		execute_command(list, fd, envp);
		list = list->next;
	}
	return (0);
}
