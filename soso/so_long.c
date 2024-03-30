/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 06:56:32 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/30 06:56:34 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void    map_to_img(t_max *all, int ind)
{
    int x;
    int y;

    y = 0;
    all->img->img_h = 0;
    while(all->cord->map[y])
    {
        x = 0;
        all->img->img_w = 0;
        while(all->cord->map[y][x])
        {
            if (all->cord->map[y][x] == 'P')
                map_to_img2(all, ind);
            if (all->cord->map[y][x] == '1')
                mlx_put_image_to_window(all->mlx, all->win , all->img->brick, all->img->img_w, all->img->img_h);
            if (all->cord->map[y][x] == 'E')
                map_to_img3(all);
            if (all->cord->map[y][x] == 'C')
                mlx_put_image_to_window(all->mlx, all->win , all->img->rouge, all->img->img_w, all->img->img_h);
            if (all->cord->map[y][x] == 'D')
                mlx_put_image_to_window(all->mlx, all->win , all->img->fire, all->img->img_w, all->img->img_h);
            x++;
            all->img->img_w += 32;
        }
        y++;
        all->img->img_h += 36;
    }
    show_mv(all);
}

void    intialize_images(t_img *img1 , t_max *all)
{
    int h = 0;
    int w = 0;
    
    img1->brick = mlx_xpm_file_to_image(all->mlx,"textures/agadir.xpm", &w, &h);
    img1->holdon = mlx_xpm_file_to_image(all->mlx,"textures/holdstill2.xpm", &w, &h);
    img1->rouge = mlx_xpm_file_to_image(all->mlx, "textures/rouge.xpm", &w, &h);
    img1->cexit =mlx_xpm_file_to_image(all->mlx,"textures/cexit.xpm", &w, &h);
    img1->down = mlx_xpm_file_to_image(all->mlx,"textures/down.xpm", &w, &h); 
    img1->left = mlx_xpm_file_to_image(all->mlx,"textures/left.xpm", &w, &h); 
    img1->right = mlx_xpm_file_to_image(all->mlx, "textures/right.xpm", &w, &h);
    img1->top = mlx_xpm_file_to_image(all->mlx, "textures/upp.xpm", &w, &h);
    img1->oexit =  mlx_xpm_file_to_image(all->mlx,"textures/openexit.xpm", &w, &h);
    img1->fire =  mlx_xpm_file_to_image(all->mlx,"textures/fire.xpm", &w, &h);
}

int read_map(t_max *all, t_img *s, char *path , t_checkmap *c)
{
    int fd;
    int i;
    
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
    return(1);
}

void intialize_and_run(t_max *all,  t_checkmap *s, char *path)
{
    all->win_hight = 36 * s->map_h;
    all->win_width = 32 * s->map_l;
    all->mlx = mlx_init();
    all->win = mlx_new_window(all->mlx, all->win_width, all->win_hight, "so_long");
    all->cord->py = s->player_y;
    all->cord->px = s->player_x;
    all->cord->bottles = s->n_c;
    all->cord->lkhawi = 0;
    all->nbr_moves = 0;
    intialize_images(all->img , all);
    read_map(all, all->img ,path, s);
    map_to_img(all, 0);
}

int main(int ac, char **av)
{
    t_max   all;
    t_was   cord1;
    t_img  img1;
    t_checkmap str;

    if (ac != 2)
        return (0);
    if (check_map(av[1], &str) != 1)
        return(ft_putstr_fd("Map is not Valid !\n", 2),0);
    all.cord = &cord1;
    all.img = &img1;
    intialize_and_run(&all, &str, av[1]);
    // mlx_key_hook(all.win, key_hook, &all);
    mlx_hook(all.win, 17, 1L<<1, success_logout, &all);
    mlx_hook(all.win, 3, 0, key_hook, &all);
    // system("leaks exec");     
    mlx_loop(all.mlx);
   
}
