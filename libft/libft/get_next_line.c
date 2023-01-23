/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:04:54 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/23 14:33:25 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_newline_idx(t_buffer *buf)
{
	int	idx;

	idx = buf->idx;
	while (buf->buf[idx] != '\n' && idx < buf->readbyte)
		idx++;
	return (idx);
}

int	check_readerr(t_string *line, t_buffer *buf)
{
	if (buf->readbyte < 0)
	{
		buf->idx = 0;
		free(line->str);
		free(line);
		return (1);
	}
	else
		return (0);
}

static t_buflist	*init_list(int fd)
{
	t_buflist	*item;

	item = (t_buflist *)malloc(sizeof(t_buflist));
	if (!item)
		return (0);
	item->buf = (t_buffer *)malloc(sizeof(t_buffer));
	if (item->buf == 0)
	{
		free(item);
		return (0);
	}
	item->buf->idx = 0;
	item->buf->readbyte = 0;
	item->fd = fd;
	item->next = NULL;
	return (item);
}

static void	ft_lstdelone(t_buflist **fd_list, int fd)
{
	t_buflist	*fd_item;
	t_buflist	*tmp_item;

	fd_item = *fd_list;
	if (fd_item->fd == fd)
	{
		*fd_list = fd_item->next;
		free(fd_item->buf);
		free(fd_item);
		return ;
	}
	while (fd_item && fd_item->next->fd != fd)
		fd_item = fd_item->next;
	if (fd_item->next->fd == fd)
	{
		tmp_item = fd_item->next;
		fd_item->next = fd_item->next->next;
		free(tmp_item->buf);
		free(tmp_item);
	}
}

char	*get_next_line(int fd)
{
	static t_buflist	*fd_list;
	t_buflist			*fd_item;
	char				*line;

	if (!fd_list)
	{
		fd_list = init_list(fd);
		if (!fd_list)
			return (0);
	}
	fd_item = fd_list;
	while (fd_item && fd_item->fd != fd)
	{
		if (fd_item->next == 0)
		{
			fd_item->next = init_list(fd);
			if (fd_item->next == 0)
				return (0);
		}
		fd_item = fd_item->next;
	}
	line = get_next_line2(fd_item);
	if (!line)
		ft_lstdelone(&fd_list, fd);
	return (line);
}
