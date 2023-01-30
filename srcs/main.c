/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:11:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/30 16:22:41 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "pipex.h"

void	__execute_command(t_command *cmd, int *fd, char **envp)
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
		perror_exit(cmd->argv[0]);
}

int	execute_command(t_command *cmd, int *fd, char **envp)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	if (pid == 0)
		__execute_command(cmd, fd, envp);
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

void	check_files(char *infile, char *outfile)
{
	if (access(infile, R_OK))
		perror_exit(infile);
	if (!access(outfile, F_OK) && access(outfile, W_OK))
		perror_exit(outfile);
}

int	*open_files(char *infile, char *outfile)
{
	int	*fd;

	fd = ft_calloc(2, sizeof(int));
	fd[0] = open(infile, O_RDONLY);
	if (fd[0] < 0)
		perror_exit(infile);
	fd[1] = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd[1] < 0)
		perror_exit(outfile);
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	int			*fd;
	int			idx;
	int			ret;
	t_command	*list;

	if (argc != 5)
		return (1);
	idx = 1;
	list = NULL;
	check_files(argv[1], argv[argc - 1]);
	fd = open_files(argv[1], argv[argc - 1]);
	while (++idx < argc - 1)
		add_cmd_back(&list, new_command(argv[idx], envp));
	map_commands(&list, fd, envp, execute_command);
	clear_cmds(&list);
	free(fd);
	return (ret);
}
