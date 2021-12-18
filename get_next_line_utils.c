#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int    ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return(-1);
    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

size_t  ft_strlen(const char    *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

char    *ft_strdup(const char *src)
{
    int     n;
    char    *dup;
    int     i;

    i = 0;
    n = 0;
    while (src[n])
        n++;
    dup = (char *)malloc(sizeof(char) * (n + 1));
    if (!dup)
        return (NULL);
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *s2;

    i = 0;
    if (!s)
        return (ft_strdup(""));
    if (start >= (ft_strlen(s)) || len == 0)
        return (NULL);
    if (len > ft_strlen(s))
        len = ft_strlen(s);
    s2 = malloc((len + 1) * sizeof(char));
    if (!s2)
        return (NULL);
    while (i < len)
    {
        s2[i] = s[start];
        i++;
        start++;
    }
    s2[i] = '\0';
    return (s2);
}

char    *ft_strjoin(char   *s1, char  *s2)
{
    int     i;
    int     c;
    char    *ft;

    c = 0;
    i = 0;
    if (!s2)
        return (NULL);
    ft = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
    if (!ft)
        return (NULL);
    if (s1)
    {
    while (s1[i] != '\0')
    {
        ft[c++] = s1[i++];
    }
        }
    i = 0;
    while (s2[i] != '\0')
    {
        ft[c++] = s2[i++];
    }
    ft[c] = '\0';
    //free (s1);
    //free (s2);
    return (ft);
}

char *ft_newline(char   *str, int i)
{
    char    *s;
    int     a;

    a = 0;
    s = NULL;
    s = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
    while (str[i] != '\0')
    {
        s[a] = str[i];
        i++;
        a++;
    }
    s[a] = '\0';
    //free(str);
    return (s);
}

char *get_next_line(int fd)
{
    char        *buf;
    static char *lft;
    int         ret;
    char        *line;
    int         i;
    int         fr;

    i = 0;
    fr = fd;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
      return (NULL);
   //if (read(fd, buf, BUFFER_SIZE) == -1)
     //   return (NULL);
    ret = 1;
    if (fd != fr)
        free(lft);
   while ( ret != 0 && ft_strchr(buf, '\n') == 0)
   {
    ret = read(fd, buf, BUFFER_SIZE);
     if (ret == -1)
     {
        return(NULL);
     }
     buf[ret] = '\0';
     lft = ft_strjoin(lft, buf);
    }
    free(buf);
    while (lft[i] != '\n' && lft[i] != '\0')
        i++;
    line = ft_substr(lft, 0, (i + 1));

    lft = ft_newline(lft, i + 1);
    return (line);


}

int main()
{
   // char *c;
    //c = "wettt";
    //c = malloc(sizeof (char) * 5);
    //int r = 0;
    FILE    *v = fopen("test.txt", "r");
    int i = fileno(v);
    FILE    *g = fopen("tr.txt", "r");
    int a = fileno(g);
    printf("%s",get_next_line(i));
    printf("%s",get_next_line(a));
    printf("%s",get_next_line(i));
    printf("%s",get_next_line(a));

}
