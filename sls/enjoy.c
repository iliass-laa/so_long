#include "my_header.h"


int key_hook(int key, t_max *all)
{
    // if (key == D)
    // {
    //     right(mlx1);
    //     put_images(mlx1 , 'r');
    // }
    if (key == ESC)
    {
        mlx_clear_window (all->mlx,  all->win);
        mlx_destroy_window(all->mlx, all->win);
        exit(1);
    }
    // if (key == S)
    // {
    //     down(mlx1);
    //     put_images(mlx1, 'd');
    // }
    //  if (key == A)
    // {
    //     left(mlx1);
    //     put_images(mlx1 , 'l');    
    // }
    // if (key == W)
    // {
    //     up(mlx1);
    //     put_images(mlx1, 'u');
    // }
    return(0);
}

// void    right(t_max *all)
// {

// }