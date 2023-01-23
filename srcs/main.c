/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:11:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/23 15:01:09 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "pipex.h"

void	execute_command(int fd_in, int fd_out, char *command, char **envp)
{
	char	**command_argv;
	char	*ret;

	command_argv = ft_split(command, ' ');
	ret = get_valid_bin(envp, command_argv[0]);
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	execve(ret, command_argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	/*
	open_file
	execve
	pipe
	execve
	open_file
	*/
	int		fd1[2];
	pid_t	pid;
	int		count;
	int		*status;

	count = 1;
	while (count <= 2)
	{
		if (pipe(fd1) < 0)
			return (1);
		pid = fork();
		if (pid < 0)
			return (1);
		else if (pid == 0)
		{
			if (count == 1)
			{
				close(fd1[0]);
				execute_command(0, fd1[1], argv[count], envp);
				close(fd1[1]);
			}
			else if (count == 2)
			{
				close(fd1[1]);
				execute_command(fd1[0], 1, argv[count], envp);
				close(fd1[0]);
			}
		}
		else
		{
			if (count == 1)
			{
				waitpid(pid, status, 0);
				printf("count1 %d\n", pid);
			}
			else if (count == 2)
			{
				waitpid(pid, status, 0);
				printf("count2 %d\n", pid);
			}
		}
		count++;
	}
	return (0);
}
