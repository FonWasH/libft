/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperez <juperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 04:01:39 by juperez           #+#    #+#             */
/*   Updated: 2025/05/07 00:59:34 by juperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static char	*ft_get_stash(char *stash)
{
	char	*line;

	line = (char *)ft_calloc(GNL_BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	if (*stash)
	{
		ft_strlcpy(line, stash, ft_strlen(stash) + 1);
		ft_bzero((void *)stash, GNL_BUFFER_SIZE + 1);
	}
	return (line);
}

static char	*ft_return_line(char *line, char *stash)
{
	char	*end;
	char	*ret;

	end = ft_strchr(line, '\n');
	if (end++)
	{
		ret = ft_strldup(line, end - line);
		if (!ret)
			return (free(line), NULL);
		ft_strlcpy(stash, end, ft_strlen(end) + 1);
	}
	else
		ret = ft_strdup(line);
	return (free(line), ret);
}

static char	*ft_read_fd(int fd, char *line, char *stash)
{
	char	buffer[GNL_BUFFER_SIZE + 1];
	int		bytes;
	size_t	size;

	size = GNL_BUFFER_SIZE + 1;
	bytes = 1;
	while (bytes > 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffer, GNL_BUFFER_SIZE);
		if ((!*line && bytes == 0) || bytes == -1)
			return (free(line), NULL);
		buffer[bytes] = '\0';
		if (bytes + ft_strlen(line) + 1 > size)
		{
			line = ft_realloc(line, size, size + size);
			if (!line)
				return (NULL);
			size += size;
		}
		ft_strlcat(line, buffer, size);
	}
	return (ft_return_line(line, stash));
}

char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][GNL_BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > FOPEN_MAX || GNL_BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_bzero((void *)stash[fd], GNL_BUFFER_SIZE + 1), NULL);
	line = ft_get_stash(stash[fd]);
	if (!line)
		return (ft_bzero((void *)stash[fd], GNL_BUFFER_SIZE + 1), NULL);
	return (ft_read_fd(fd, line, stash[fd]));
}
