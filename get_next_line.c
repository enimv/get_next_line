/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 03:00:12 by aoueldma          #+#    #+#             */
/*   Updated: 2022/01/06 03:00:37 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
char    *get_next_line(int   fd)
{
    static char *left;
    char        *buf;
    int         i;
    int         ret;
    char        *line;

    i = 0;
    ret = 1;
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    while (!ft_strrchr(buf, '\n') && ret != 0)
    {
        ret = read(fd,  buf, BUFFER_SIZE);
        if (ret == -1)
            return (NULL);
        buf[ret] = '\0';
        left = ft_strjoin(left, buf); 
    }
    free(buf);
    buf = NULL;
    while (left[i] != '\n')
        i++;
    line = ft_substr(left, 0, (i + 1));
    left = ft_newline(left, i + 1);
    return (line);
}

