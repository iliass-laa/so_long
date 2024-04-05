/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:49:35 by ilaasri           #+#    #+#             */
/*   Updated: 2024/04/02 04:51:24 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

int	nbrlen(int i)
{
	int	res;

	res = 1;
	if (i < 10)
		return (1);
	res += nbrlen(i / 10);
	return (res);
}

char	*nbr_mv(int i)
{
	char	*base;
	char	*res;
	int		l;
	int		y;

	base = "0123456789";
	l = nbrlen(i);
	y = nbrlen(i);
	res = (char *)malloc(l + 1);
	if (!res)
		return (NULL);
	if (i == 0)
		res[0] = '0';
	else
	{
		while (i > 0)
		{
			res[l - 1] = base[i % 10];
			i = i / 10;
			l--;
		}
	}
	res[y] = 0;
	return (res);
}

char	*moves(t_max *all)
{
	char	*res;
	char	*mv;
	int		i;
	int		mvl;

	res = NULL;
	i = ft_strlen("MOVES : ");
	mv = nbr_mv(all->nbr_moves);
	mvl = ft_strlen(mv);
	res = ft_strjoin(res, "MOVES: ", i);
	res = ft_strjoin(res, mv, mvl);
	free(mv);
	return (res);
}

void	show_mv(t_max *all)
{
	char	*s;

	s = moves(all);
	mlx_string_put(all->mlx, all->win, 5, 6, 0xEAEDED, s);
	free(s);
}
