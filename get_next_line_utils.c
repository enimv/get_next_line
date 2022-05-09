/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 06:53:19 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/30 07:02:08 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strrchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*ft;

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
			ft[c++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
		ft[c++] = s2[i++];
	ft[c] = '\0';
	free (s1);
	return (ft);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!s)
		return (NULL);
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

char	*ft_newline(char *left, int i)
{
	char	*newline;
	int		a;

	a = 0;
	if (left[i] == '\n')
		i++;
	if (!left)
		return (NULL);
	newline = malloc(sizeof(char) * (ft_strlen(left) - i) + 1);
	if (!newline)
		return (NULL);
	while (left[i])
		newline[a++] = left[i++];
	newline[a] = '\0';
	free(left);
	return (newline);
}
