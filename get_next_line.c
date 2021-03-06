/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:00:12 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/30 07:08:19 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_free(char **left, char *line)
{
	if (line == NULL)
	{
		free(*left);
		*left = NULL;
	}
	return (line);
}

char	*error(char *buf)
{
	free(buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buf;
	int			ret;
	char		*line;

	ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 2));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (!ft_strrchr(buf, '\n') && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (error(buf));
		buf[ret] = '\0';
		left = ft_strjoin(left, buf);
	}
	free(buf);
	ret = 0;
	while (left[ret] != '\n' && left[ret])
		ret++;
	line = ft_substr(left, 0, (ret + 1));
	left = ft_newline(left, ret);
	return (ft_free(&left, line));
}
