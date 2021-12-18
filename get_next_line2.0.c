int strrchr(char    *buf, char  c)
{
    int i;

    i = 0;
    if(!buf)
        return (-1);
    while (buf[i])
    {
        if (buf[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char    *get_next_line(int   fd)
{
    static char *left;
    char    *buf;
    int     ret;
    int     BUFFER_SIZE = 10;
    char    *line;
    int     i;

    ret = 0;
    i = 0;
    buf = malloc(sizeof(char) * BUFFER_SIZE)
    if (!buf)
        return (NULL);
    while (strrchr(buf,'\n') == 0)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret == -1)
            return (NULL);
        left = ft_strjoin(left, buf)
    }
    while (left[i] != '\n')
        i++;
    line = substr(left, 0, i);
    left = ft_newline(left, i + 1);
    return (line);
}



    
}