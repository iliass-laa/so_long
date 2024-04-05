/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appear_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:17:51 by ilaasri           #+#    #+#             */
/*   Updated: 2024/04/02 20:17:53 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	map_to_img2(t_max *all, int ind)
{
	if (ind == 0)
	{
		mlx_put_image_to_window(all->mlx, all->win, all->img->holdon,
			all->img->img_w, all->img->img_h);
		all->img->p_h = all->img->img_h;
		all->img->p_w = all->img->img_w;
	}
	else if (ind == 'r')
		mlx_put_image_to_window(all->mlx, all->win, all->img->right,
			all->img->p_w, all->img->p_h);
	else if (ind == 'u')
		mlx_put_image_to_window(all->mlx, all->win, all->img->top,
			all->img->p_w, all->img->p_h);
	else if (ind == 'l')
		mlx_put_image_to_window(all->mlx, all->win, all->img->left,
			all->img->p_w, all->img->p_h);
	else if (ind == 'd')
		mlx_put_image_to_window(all->mlx, all->win, all->img->down,
			all->img->p_w, all->img->p_h);
}

void	map_to_img3(t_max *all)
{
	if (all->cord->lkhawi == all->cord->bottles)
		mlx_put_image_to_window(all->mlx, all->win, all->img->oexit,
			all->img->img_w, all->img->img_h);
	else
		mlx_put_image_to_window(all->mlx, all->win, all->img->cexit,
			all->img->img_w, all->img->img_h);
	all->cord->cexit_h = all->img->img_h;
	all->cord->cexit_w = all->img->img_w;
}

int	success_logout(t_max *all, int ind)
{
	if (ind == 2)
		ft_putstr_fd(G "YOU WON!\n", 1);
	if (ind == 0)
		ft_putstr_fd(R"YOU BURNED YOURSELF ! \n", 2);
	mlx_destroy_window(all->mlx, all->win);
	free(all->mlx);
	exit(1);
	return (1);
}

void	sos(t_max *all, int ind)
{
	if (ind == 11)
		mlx_put_image_to_window(all->mlx, all->win, all->img->fire1,
			all->img->img_w, all->img->img_h);
	if (ind == 22)
		mlx_put_image_to_window(all->mlx, all->win, all->img->fire2,
			all->img->img_w, all->img->img_h);
	if (ind == 33)
		mlx_put_image_to_window(all->mlx, all->win, all->img->fire3,
			all->img->img_w, all->img->img_h);
	if (ind == 44)
		mlx_put_image_to_window(all->mlx, all->win, all->img->fire4,
			all->img->img_w, all->img->img_h);
	if (ind == 55)
		mlx_put_image_to_window(all->mlx, all->win, all->img->fire5,
			all->img->img_w, all->img->img_h);
	if (ind == 66)
		mlx_put_image_to_window(all->mlx, all->win, all->img->fire6,
			all->img->img_w, all->img->img_h);
}
