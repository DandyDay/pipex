/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:23:11 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/22 19:00:44 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char		*get_next_line(int fd);

typedef struct s_buffer
{
	char	buf[BUFFER_SIZE];
	int		idx;
	int		readbyte;
}				t_buffer;

typedef struct s_string
{
	char	*str;
	int		len;
	int		size;
}				t_string;

typedef struct s_buflist
{
	int					fd;
	struct s_buflist	*next;
	t_buffer			*buf;
}				t_buflist;

int			check_readerr(t_string *line, t_buffer *buf);
int			get_newline_idx(t_buffer *buf);
char		*get_next_line2(t_buflist *fd_item);

#endif
