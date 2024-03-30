#include "my_header.h"


int key_hook(int key, t_max *all)
{
    if (key == D)
        right(all, all->cord->py, all->cord->px + 1);
    if (key == ESC)
    {
        mlx_clear_window (all->mlx,  all->win);
        mlx_destroy_window(all->mlx, all->win);
        exit(1);
    }
    if (key == S)
        down(all);
     if (key == A)
        left(all);
    if (key == W)
        up(all);
    return(0);
}

void    right(t_max *all , int y, int x)
{
    // int x;
    // int y;

    // y = all->cord->py;
    // x = all->cord->px;
    is_it_safe(all, y, x);
    if (all->cord->map[y][x] != '1')
    {
        all->nbr_moves ++;
        if (all->cord->map[y][x] == 'C')
                all->cord->lkhawi ++;
        if (all->cord->map[y][x] == 'E')
        {
            if(all->cord->lkhawi == all->cord->bottles)
                success_logout(all);
            mlx_clear_window(all->mlx, all->win);
            all->cord->map[y][x - 1] = '0';
            map_to_img(all , 'e');
            mlx_put_image_to_window(all->mlx, all->win , all->img->right,  all->cord->cexit_w,  all->cord->cexit_h);
        }
        else
        {
            if (all->cord->map[y][x - 1] != 'E')
            {
                all->cord->map[y][x - 1] = '0';
                all->cord->map[y][x] = 'P';
            }
            else
                all->cord->map[y][x] = 'P'; 
            mlx_clear_window(all->mlx, all->win);
            map_to_img(all , 'r');
        }
        all->cord->px += 1;
    }
    // if (all->cord->map[y][x + 1] != '1')
    // {
    //     all->nbr_moves ++;
    //     if (all->cord->map[y][x + 1] == 'C')
    //             all->cord->lkhawi ++;
    //     if (all->cord->map[y][x + 1] == 'E')
    //     {
    //         if(all->cord->lkhawi == all->cord->bottles)
    //             success_logout(all);
    //         mlx_clear_window(all->mlx, all->win);
    //         all->cord->map[y][x] = '0';
    //         map_to_img(all , 'e');
    //         mlx_put_image_to_window(all->mlx, all->win , all->img->right,  all->cord->cexit_w,  all->cord->cexit_h);
    //     }
    //     else
    //     {
    //         if (all->cord->map[y][x] != 'E')
    //         {
    //             all->cord->map[y][x] = '0';
    //             all->cord->map[y][x + 1] = 'P';
    //         }
    //         else
    //             all->cord->map[y][x + 1] = 'P'; 
    //         mlx_clear_window(all->mlx, all->win);
    //         map_to_img(all , 'r');
    //     }
    //     all->cord->px += 1;
    // }
}

void    left(t_max *all)
{
    int x;
    int y;

    y = all->cord->py;
    x = all->cord->px;
    is_it_safe(all, y, x - 1);
    if (all->cord->map[y][x- 1] != '1')
    {
        all->nbr_moves ++;
        if (all->cord->map[y][x - 1] == 'C')
                all->cord->lkhawi ++;
        if (all->cord->map[y][x - 1] == 'E')
        {
            if(all->cord->lkhawi == all->cord->bottles)
                exit(1);
            mlx_clear_window(all->mlx, all->win);
            all->cord->map[y][x] = '0';
            map_to_img(all , 'e');
            mlx_put_image_to_window(all->mlx, all->win , all->img->left,  all->cord->cexit_w,  all->cord->cexit_h);
        }
        else
        {
            if (all->cord->map[y][x] != 'E')
            {
                all->cord->map[y][x] = '0';
                all->cord->map[y][x - 1] = 'P';
            }
            else
                all->cord->map[y][x - 1] = 'P'; 
            mlx_clear_window(all->mlx, all->win);
            map_to_img(all , 'l');
        }
        all->cord->px-= 1;
    }
}

void    down(t_max *all)
{
    int x;
    int y;

    y = all->cord->py;
    x = all->cord->px;
    is_it_safe(all, y + 1, x);
    if (all->cord->map[y + 1][x] != '1')
    {
        all->nbr_moves ++;
        if (all->cord->map[y + 1][x] == 'E')
        {
            if(all->cord->lkhawi == all->cord->bottles)
                exit(1);
            all->cord->map[y][x] = '0';
            mlx_clear_window(all->mlx, all->win);
            map_to_img(all ,'e');
            mlx_put_image_to_window(all->mlx, all->win , all->img->holdon,  all->cord->cexit_w,  all->cord->cexit_h);
        }
        else
        {
            if (all->cord->map[y + 1][x] == 'C')
                all->cord->lkhawi ++;
            if (all->cord->map[y][x] != 'E')
                all->cord->map[y][x] = '0';
            all->cord->map[y + 1][x] = 'P';
            mlx_clear_window(all->mlx, all->win);
            map_to_img(all ,'d');
        }
        all->cord->py += 1;
    }

}

void    up(t_max *all)
{
    int x;
    int y;

    y = all->cord->py;
    x = all->cord->px;
    is_it_safe(all, y -1, x);
    if (all->cord->map[y - 1][x] != '1')
    {
        all->nbr_moves ++;
        if (all->cord->map[y - 1][x] == 'E' )
        {
            if(all->cord->lkhawi == all->cord->bottles)
                exit(1);
            all->cord->map[y][x] = '0';
            mlx_clear_window(all->mlx, all->win);
            map_to_img(all,'e');
            mlx_put_image_to_window(all->mlx, all->win , all->img->top,  all->cord->cexit_w,  all->cord->cexit_h);
        }
        else
        {
            if (all->cord->map[y - 1][x] == 'C')
                all->cord->lkhawi ++;
            if (all->cord->map[y][x] != 'E')
                all->cord->map[y][x] = '0';
            all->cord->map[y - 1][x] = 'P';
            mlx_clear_window(all->mlx, all->win);
            map_to_img(all,'u');
        }
        all->cord->py -= 1;
    }

}

void    is_it_safe(t_max *all, int y, int x)
{
     if (all->cord->map[y][x] == 'D')
    {
        // mlx_put_image_to_window()
        ft_putstr_fd("YOU BURNED YOURSELF !\n", 2);
        success_logout(all);
    }
}

// void    success_exit(t_max *all)

// void ready_yet(t_max *all, int y, int x)
// {
//     if(all->cord->lkhawi == all->cord->bottles)
//     {
//         exit(1);
//     }
//     else
//     {

//     }
// }