#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

int    ft_strrchr(char *s, int c);
size_t ft_strlen(char  *str);
char    *ft_strjoin(char   *s1, char  *s2);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_newline(char *left, int  i);
char    *get_next_line(int   fd);

#endif