/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 06:56:58 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/28 06:57:03 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	slen;
	size_t	i;

	i = 0;
	if (s)
	{
		slen = ft_strlen(s);
		while (i < slen)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int	check_path_name(char *path)
{
	char	*s;
	int		i;
	int		p_len;

	p_len = ft_strlen(path);
	s = ".ber";
	i = 4;
	while (i >= 0)
	{
		if (path[p_len] != s[i])
			return (-1);
		i--;
		p_len--;
	}
	return (1);
}

void	free_map(t_checkmap *s)
{
	int	i;

	i = 0;
	while (s->map[i])
	{
		free(s->map[i]);
		i++;
	}
	free(s->map);
}

int	check_map_content(t_checkmap *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		if (s->map[i] == 0)
			return (-1);
		while (s->map[i][j])
		{
			if (s->map[i][j] != '1' && s->map[i][j] != '0'
				&& s->map[i][j] != 'C' && s->map[i][j] != 'E'
				&& s->map[i][j] != 'P')
				return (-1);
            lmssarndwhile(i, j, s);
			j++;
		}
		i++;
	}
	if (s->n_e != 1 || s->n_c <= 0 || s->n_p != 1)
		return (-1);
	return (1);
}

void	lmssarndwhile(int i, int j, t_checkmap *s)
{
	if (s->map[i][j] == 'C')
		s->n_c += 1;
	if (s->map[i][j] == 'P')
	{
		s->player_y = i;
		s->player_x = j;
		s->n_p += 1;
	}
	if (s->map[i][j] == 'E')
		s->n_e += 1;
}
