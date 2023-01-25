/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:11:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/25 16:11:37 by jinhchoi         ###   ########.fr       */
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
	if (!ret)
	{
		perror(command);
		exit(1);
	}
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	fprintf(stderr, "pid=%d, command=%s\n", getpid(), command);
	execve(ret, command_argv, envp);
}

void	leak()
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		file_fd[2];
	pid_t	pid;
	int		status;

	// atexit(leak);
	if (argc != 5)
		return (1);
	if (access(argv[1], R_OK) || access(argv[argc - 1], W_OK))
		exit(1);
	file_fd[0] = open(argv[1], O_RDONLY);
	file_fd[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0666);

	pipe(fd);

	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		execute_command(file_fd[0], fd[1], argv[2], envp);
	}
	waitpid(0, &status, WNOHANG);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		execute_command(fd[0], file_fd[1], argv[3], envp);
	}
	waitpid(0, &status, WNOHANG);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (WEXITSTATUS(status));
	close(fd[0]);
	close(fd[1]);
	return (0);
}
