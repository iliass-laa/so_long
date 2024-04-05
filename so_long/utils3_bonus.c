/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:07:09 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/30 03:07:13 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

// void	is_it_safe(t_max *all, int y, int x)
// {
// 	if (all->cord->map[y][x] == 'D')
// 	{
// 		ft_putstr_fd(R"YOU BURNED YOURSELF ! \n", 2);
// 		success_logout(all, 0);
// 	}
// }

void	step_over_exit(t_max *all, int ind, int y, int x)
{
	if (all->cord->lkhawi == all->cord->bottles)
		success_logout(all, 2);
	all->cord->map[y][x] = '0';
	if (ind == 'u')
	{
		all->cord->map[y - 1][x] = 'S';
		map_to_img(all, 44, 'u');
	}
	if (ind == 'l')
	{
		all->cord->map[y][x - 1] = 'S';
		map_to_img(all, 44, 'l');
	}
	if (ind == 'd')
	{
		all->cord->map[y + 1][x] = 'S';
		map_to_img(all, 44, 'd');
	}
	if (ind == 'r')
	{
		all->cord->map[y][x + 1] = 'S';
		map_to_img(all, 44, 'r');
	}
}

void	intialize_images2(t_img *img1, t_max *all)
{
	int	h;
	int	w;

	img1->fire5 = mlx_xpm_file_to_image(all->mlx, "textures/fire55.xpm", &w,
			&h);
	img1->fire6 = mlx_xpm_file_to_image(all->mlx, "textures/fire66.xpm", &w,
			&h);
}

void	map_to_img4(t_max *all, int y, int x, int ind2)
{
	if (all->cord->map[y][x] == '1')
		mlx_put_image_to_window(all->mlx, all->win, all->img->brick,
			all->img->img_w, all->img->img_h);
	if (all->cord->map[y][x] == 'C')
		mlx_put_image_to_window(all->mlx, all->win, all->img->rouge,
			all->img->img_w, all->img->img_h);
	if (all->cord->map[y][x] == 'E')
		map_to_img3(all);
	if (all->cord->map[y][x] == 'S')
	{
		mlx_put_image_to_window(all->mlx, all->win, all->img->cexit,
			all->img->img_w, all->img->img_h);
		map_to_img2(all, ind2);
	}
	if (all->cord->map[y][x] == 'P')
		map_to_img2(all, ind2);
}
