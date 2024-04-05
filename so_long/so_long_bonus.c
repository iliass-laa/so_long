/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:56:32 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/30 06:56:34 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

void	map_to_img(t_max *all, int ind1, int ind2)
{
	int	x;
	int	y;

	y = 0;
	all->img->img_h = 0;
	mlx_clear_window(all->mlx, all->win);
	while (all->cord->map[y])
	{
		x = 0;
		all->img->img_w = 0;
		while (all->cord->map[y][x])
		{
			map_to_img4(all, y, x, ind2);
			if (all->cord->map[y][x] == 'D')
				sos(all, ind1);
			x++;
			all->img->img_w += 32;
		}
		y++;
		all->img->img_h += 36;
	}
	show_mv(all);
}

void	intialize_images(t_img *img1, t_max *all)
{
	int	h;
	int	w;

	img1->brick = mlx_xpm_file_to_image(all->mlx, "textures/agadir.xpm", &w,
			&h);
	img1->holdon = mlx_xpm_file_to_image(all->mlx, "textures/holdstill2.xpm",
			&w, &h);
	img1->rouge = mlx_xpm_file_to_image(all->mlx, "textures/rouge.xpm", &w, &h);
	img1->cexit = mlx_xpm_file_to_image(all->mlx, "textures/cexit.xpm", &w, &h);
	img1->down = mlx_xpm_file_to_image(all->mlx, "textures/down.xpm", &w, &h);
	img1->left = mlx_xpm_file_to_image(all->mlx, "textures/left.xpm", &w, &h);
	img1->right = mlx_xpm_file_to_image(all->mlx, "textures/right.xpm", &w, &h);
	img1->top = mlx_xpm_file_to_image(all->mlx, "textures/upp.xpm", &w, &h);
	img1->oexit = mlx_xpm_file_to_image(all->mlx, "textures/openexit.xpm", &w,
			&h);
	img1->fire = mlx_xpm_file_to_image(all->mlx, "textures/fire.xpm", &w, &h);
	img1->fire1 = mlx_xpm_file_to_image(all->mlx, "textures/fire11.xpm", &w,
			&h);
	img1->fire2 = mlx_xpm_file_to_image(all->mlx, "textures/fire22.xpm", &w,
			&h);
	img1->fire3 = mlx_xpm_file_to_image(all->mlx, "textures/fire33.xpm", &w,
			&h);
	img1->fire4 = mlx_xpm_file_to_image(all->mlx, "textures/fire44.xpm", &w,
			&h);
}

int	read_map(t_max *all, t_img *s, char *path, t_checkmap *c)
{
	int	fd;
	int	i;

	fd = open(path, O_RDONLY);
	s->map_nbrl = c->map_h;
	s->map_line_l = c->map_l;
	all->cord->map = (char **)malloc(sizeof(char *) * (s->map_nbrl + 1));
	i = 0;
	while (i < s->map_nbrl)
	{
		all->cord->map[i++] = read_lines(fd);
	}
	all->cord->map[i] = 0;
	close(fd);
	return (1);
}

void	intialize_and_run(t_max *all, t_checkmap *s, char *path)
{
	all->win_hight = 36 * s->map_h;
	all->win_width = 32 * s->map_l;
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->win_width, all->win_hight,
			"so_long");
	all->cord->py = s->player_y;
	all->cord->px = s->player_x;
	all->cord->bottles = s->n_c;
	all->cord->lkhawi = 0;
	all->nbr_moves = 0;
	intialize_images(all->img, all);
	intialize_images2(all->img, all);
	read_map(all, all->img, path, s);
	map_to_img(all, 11, 0);
}

int	main(int ac, char **av)
{
	t_max		all;
	t_was		cord1;
	t_img		img1;
	t_checkmap	str;

	if (ac != 2)
		return (ft_putstr_fd(R"Error \nneed one argument !\n", 2), 0);
	if (check_map(av[1], &str) != 1)
		return (ft_putstr_fd(R"Error \nMap is not Valid !\n", 2), 0);
	all.cord = &cord1;
	all.img = &img1;
	intialize_and_run(&all, &str, av[1]);
	mlx_hook(all.win, 17, 0, success_logout, &all);
	mlx_hook(all.win, 2, 1, key_hook, &all);
	mlx_loop_hook(all.mlx, loop_hook, &all);
	mlx_loop(all.mlx);
}
