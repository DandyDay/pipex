/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:11:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/23 02:02:55 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid = 1;
	int		status;

	pid = fork();
	printf("%d\n", pid);
	if (pid == 0)
		printf("child\n");
	else
	{
		waitpid(0, &status, 0);
		printf("parent\n");
	}
	// execve("/bin/cat", argv, envp);
}
