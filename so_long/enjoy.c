/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enjoy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:44:23 by ilaasri           #+#    #+#             */
/*   Updated: 2024/04/02 04:44:25 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	key_hook(int key, t_max *all)
{
	if (key == D)
		right(all, all->cord->py, all->cord->px);
	if (key == ESC)
	{
		mlx_clear_window(all->mlx, all->win);
		mlx_destroy_window(all->mlx, all->win);
		exit(1);
	}
	if (key == S)
		down(all, all->cord->py, all->cord->px);
	if (key == A)
		left(all, all->cord->py, all->cord->px);
	if (key == W)
		up(all, all->cord->py, all->cord->px);
	return (0);
}

void	right(t_max *all, int y, int x)
{
	if (all->cord->map[y][x + 1] == 'D')
		success_logout(all, 0);
	if (all->cord->map[y][x + 1] != '1')
	{
		all->img->p_w += 32;
		all->nbr_moves++;
		if (all->cord->map[y][x + 1] == 'C')
			all->cord->lkhawi++;
		if (all->cord->map[y][x + 1] == 'E')
			step_over_exit(all, 'r', y, x);
		else if (all->cord->map[y][x] == 'S')
		{
			all->cord->map[y][x] = 'E';
			all->cord->map[y][x + 1] = 'P';
		}
		else
		{
			all->cord->map[y][x] = '0';
			all->cord->map[y][x + 1] = 'P';
		}
		mlx_clear_window(all->mlx, all->win);
		map_to_img(all, 'r');
		all->cord->px += 1;
	}
}

void	left(t_max *all, int y, int x)
{
	if (all->cord->map[y][x - 1] == 'D')
		success_logout(all, 0);
	if (all->cord->map[y][x - 1] != '1')
	{
		all->img->p_w -= 32;
		all->nbr_moves++;
		if (all->cord->map[y][x - 1] == 'C')
			all->cord->lkhawi++;
		if (all->cord->map[y][x - 1] == 'E')
			step_over_exit(all, 'l', y, x);
		else if (all->cord->map[y][x] == 'S')
		{
			all->cord->map[y][x] = 'E';
			all->cord->map[y][x - 1] = 'P';
		}
		else
		{
			all->cord->map[y][x] = '0';
			all->cord->map[y][x - 1] = 'P';
		}
		mlx_clear_window(all->mlx, all->win);
		map_to_img(all, 'l');
		all->cord->px -= 1;
	}
}

void	down(t_max *all, int y, int x)
{
	if (all->cord->map[y + 1][x] == 'D')
		success_logout(all, 0);
	if (all->cord->map[y + 1][x] != '1')
	{
		all->img->p_h += 36;
		all->nbr_moves++;
		if (all->cord->map[y + 1][x] == 'C')
			all->cord->lkhawi++;
		if (all->cord->map[y + 1][x] == 'E')
			step_over_exit(all, 'd', y, x);
		else if (all->cord->map[y][x] == 'S')
		{
			all->cord->map[y][x] = 'E';
			all->cord->map[y + 1][x] = 'P';
		}
		else
		{
			all->cord->map[y][x] = '0';
			all->cord->map[y + 1][x] = 'P';
		}
		mlx_clear_window(all->mlx, all->win);
		map_to_img(all, 'd');
		all->cord->py += 1;
	}
}

void	up(t_max *all, int y, int x)
{
	if (all->cord->map[y - 1][x] == 'D')
		success_logout(all, 0);
	if (all->cord->map[y - 1][x] != '1')
	{
		all->img->p_h -= 36;
		all->nbr_moves++;
		if (all->cord->map[y - 1][x] == 'C')
			all->cord->lkhawi++;
		if (all->cord->map[y - 1][x] == 'E')
			step_over_exit(all, 'u', y, x);
		else if (all->cord->map[y][x] == 'S')
		{
			all->cord->map[y][x] = 'E';
			all->cord->map[y - 1][x] = 'P';
		}
		else
		{
			all->cord->map[y][x] = '0';
			all->cord->map[y - 1][x] = 'P';
			mlx_clear_window(all->mlx, all->win);
			map_to_img(all, 'u');
		}
		all->cord->py -= 1;
	}
}
