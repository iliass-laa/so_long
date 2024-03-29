/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:38:45 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/25 00:38:56 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	fin_nl(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (i);
			i++;
		}
	}
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*res;
	int		i;
	t_rd	lol;

	i = 0;
	lol.reslen = len;
	lol.s1len = ft_strlen(s);
	if (len + start > lol.s1len)
		lol.reslen = lol.s1len - start;
	if (start >= lol.s1len || !s)
		return (free(s), NULL);
	res = (char *)malloc(lol.reslen + 1);
	if (!res)
		return (free(s), NULL);
	while (i < lol.reslen)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = 0;
	return (free(s), res);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	char	*res;
	t_rd	lol;
	int		i;
	int		j;

	lol.s1len = ft_strlen(s1);
	lol.s2len = ft_strlen(s2);
	lol.reslen = len + lol.s1len;
	if (len > lol.s2len)
		lol.reslen = lol.s1len + lol.s2len;
	res = (char *)malloc(lol.reslen + 1);
	if (!res)
		return (free(s1), NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (i < lol.reslen)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[lol.reslen] = '\0';
	return (free(s1), res);
}

char	*read_lines(int fd)
{
	static char	*chyata;
	t_read      str;

	if (fd < 0)
		return (free(chyata), NULL);
	str.res = NULL;
	if (ft_strlen(chyata))
	{
		str.nl_p = fin_nl(chyata);
		str.z_len = ft_strlen(chyata);
		if (str.nl_p < str.z_len)
		{
			str.res = ft_strjoin(str.res, chyata, str.nl_p);
			chyata = ft_substr(chyata, str.nl_p + 1, (str.z_len - (str.nl_p + 1)));
			if (ft_strlen(chyata) == 0)
				free(chyata);
			return (str.res);
		}
		else
		{
			str.res = ft_strjoin(str.res, chyata, str.z_len);
			free(chyata);
		}
	}
	str.zoom = (char *)malloc(51);
	str.readed = read(fd, str.zoom, 50);
	str.zoom[str.readed] = 0;
	while (str.readed)
	{
		str.nl_p = fin_nl(str.zoom);
		str.z_len = ft_strlen(str.zoom);
		if (str.nl_p < str.z_len)
		{
			str.res = ft_strjoin(str.res, str.zoom, str.nl_p);
			chyata = ft_substr(str.zoom, str.nl_p + 1, (str.z_len - (str.nl_p + 1)));
			return (str.res);
		}
		str.res = ft_strjoin(str.res, str.zoom, str.z_len);
		str.readed = read(fd, str.zoom, 50);
		str.zoom[str.readed] = 0;
	}
	if (ft_strlen(str.res))
	{
		free(str.zoom);
		return (str.res);
	}
	return (free(str.zoom), NULL);
}

// int main ()
// {
//     int fd = open("idols.ber", O_RDONLY);
//     char    *s= read_lines(fd);
//     while (s)
//     {
//         printf("%s", s);
//         free(s);
//         s = read_lines(fd);
//     }
//  // s = read_lines(fd);
//     free(s);
//     system("leaks a.out");
// }