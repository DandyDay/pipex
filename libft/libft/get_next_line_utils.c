/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:24:00 by jinhchoi          #+#    #+#             */
/*   Updated: 2022/12/23 14:33:38 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;

	idx = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (idx < n)
	{
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		idx++;
	}
	return (dst);
}

static t_string	*append_line(t_string *line, t_buffer *buf)
{
	const size_t	newline_idx = get_newline_idx(buf);
	char			*str;
	size_t			cpylen;

	if (buf->buf[newline_idx] == '\n' && newline_idx < (size_t)buf->readbyte)
		cpylen = newline_idx - buf->idx + 1;
	else
		cpylen = newline_idx - buf->idx;
	if ((size_t)line->size < line->len + cpylen + 1)
	{
		str = (char *)malloc(line->size * 10);
		if (!str)
			return (0);
		ft_memcpy(str, line->str, line->size);
		free(line->str);
		line->str = str;
		line->size = line->size * 10;
	}
	ft_memcpy(line->str + line->len, buf->buf + buf->idx, cpylen);
	buf->idx = (buf->idx + cpylen) % BUFFER_SIZE;
	line->len += cpylen;
	line->str[line->len] = '\0';
	return (line);
}

static char	*fit_string(t_string *line)
{
	char	*ret;

	if (line->len == 0)
	{
		free(line->str);
		free(line);
		return (0);
	}
	ret = (char *)malloc(line->len + 1);
	if (!ret)
	{
		free(line->str);
		free(line);
		return (0);
	}
	ft_memcpy(ret, line->str, line->len + 1);
	free(line->str);
	free(line);
	return (ret);
}

static t_string	*init_string(void)
{
	t_string	*str;

	str = (t_string *)malloc(sizeof(t_string));
	if (!str)
		return (0);
	str->str = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (str->str == 0)
	{
		free(str);
		return (0);
	}
	str->size = BUFFER_SIZE;
	str->len = 0;
	return (str);
}

char	*get_next_line2(t_buflist *item)
{
	t_string		*line;

	line = init_string();
	if (!line)
		return (0);
	if (item->buf->readbyte == 0 || item->buf->idx == 0)
		item->buf->readbyte = read(item->fd, item->buf->buf, BUFFER_SIZE);
	if (check_readerr(line, item->buf))
		return (0);
	while (item->buf->readbyte > 0)
	{
		if (!append_line(line, item->buf))
		{
			free(line->str);
			free(line);
			return (0);
		}
		if (line->len != 0 && line->str[line->len - 1] == '\n')
			break ;
		item->buf->readbyte = read(item->fd, item->buf->buf, BUFFER_SIZE);
		item->buf->idx = 0;
	}
	if (check_readerr(line, item->buf))
		return (0);
	return (fit_string(line));
}
