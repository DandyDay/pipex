/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:16:09 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/01/30 16:13:45 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_command
{
	char				**argv;
	int					fd[2];
	int					idx;
	struct s_command	*next;
	struct s_command	*prev;
}				t_command;

char		*get_valid_bin(char **envp, char *binname);
t_command	*new_command(char *raw_cmd, char **envp);
void		add_cmd_back(t_command **list, t_command *cmd);
void		clear_cmds(t_command **list);
void		map_commands(t_command **list, int *fd, char **envp, \
						int (*f)(t_command *, int *, char**));
char		*ft_strsjoin(char *s1, char *s2, char *s3);
int			free_strings(char **strs);
void		perror_exit(char *err);

#endif