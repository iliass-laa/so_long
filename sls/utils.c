/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:26:55 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/28 07:26:59 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	succes_path(t_checkmap *s, int y, int x)
{
	int	tot;

	tot = 0;
	if (s->map[y][x] == '1' || s->map[y][x] == 'V')
		return (0);
	if (s->map[y][x] == 'C')
		tot += 1;
	if (s->map[y][x] == 'E')
		s->sign = -1;
	s->map[y][x] = 'V';
	tot += succes_path(s, y, x + 1);
	tot += succes_path(s, y, x - 1);
	tot += succes_path(s, y + 1, x);
	tot += succes_path(s, y - 1, x);
	return (tot);
}

int	check_borders(t_checkmap *s)
{
	int	i;

	s->map_l = ft_strlen(s->map[0]);
	i = 0;
	while (s->map[0][i])
	{
		if (s->map[0][i] != '1' || s->map[s->map_h - 1][i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < s->map_h)
	{
		if (s->map[i][0] != '1' || s->map[i][s->map_l - 1] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	map_len_hi(t_checkmap *s)
{
	char	*string;
	int		i;
	int		line_len;

	i = 0;
	string = read_lines(s->fd);
	while (string)
	{
		line_len = ft_strlen(string);
		free(string);
		i++;
		string = read_lines(s->fd);
		if (string)
		{
			if (line_len != ft_strlen(string))
				return (free(string), -1);
		}
	}
	s->map_h = i;
	return (1);
}

void	read_1_map(t_checkmap *s)
{
	int	i;

	i = 0;
	s->map = (char **)malloc(sizeof(char *) * (s->map_h + 1));
	while (i < s->map_h)
		s->map[i++] = read_lines(s->fd);
	s->map[i] = 0;
	s->n_c = 0;
	s->n_p = 0;
	s->n_e = 0;
}

int	check_map(char *path, t_checkmap *str)
{
	int	s_path;

	if (check_path_name(path) != 1)
		return (-1);
	str->fd = open(path, O_RDONLY);
	if (str->fd < 0)
		return (-1);
	if (map_len_hi(str) != 1)
		return (-1);
	close(str->fd);
	str->fd = open(path, O_RDONLY);
	read_1_map(str);
	if (check_map_content(str) != 1 || check_borders(str) != 1)
		return (free_map(str), -1);
	str->sign = 1;
	s_path = succes_path(str, str->player_y, str->player_x) * str->sign;
	if (s_path != (str->n_c * -1))
		return (free_map(str), 89);
	free_map(str);
	return (1);
}
