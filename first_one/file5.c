#include "mylib.h"

void    right(t_vars *mlx1)
{
    mlx_destroy_image(mlx1->mlx, mlx1->holdon);
    mlx_clear_window (mlx1->mlx,  mlx1->win);
    if (mlx1->mymap[mlx1->yp][mlx1->xp + 1] != '1')
    {
        int x = mlx1->xp ;
        int y = mlx1->yp;
        if (ready_yet(mlx1, mlx1->yp, mlx1->xp + 1) == -1)
        {
            mlx1->mymap[y][x] = 'E';
        }
        else
            mlx1->mymap[y][x] = '0';
        mlx1->mymap[y][x + 1] = 'P';
        
        mlx1->xp += 1;
    }
}
void    up(t_vars *mlx1)
{
    mlx_destroy_image(mlx1->mlx, mlx1->holdon);
    mlx_clear_window (mlx1->mlx,  mlx1->win);
     if (mlx1->mymap[mlx1->yp - 1][mlx1->xp] != '1')
    {
        mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->to_up, mlx1->ww, mlx1->hh);
        int x = mlx1->xp ;
        int y = mlx1->yp;
        if (ready_yet(mlx1, mlx1->yp - 1, mlx1->xp) == -1)
        {
            mlx1->mymap[y][x] = 'E';
        }
        else
            mlx1->mymap[y][x] = '0';
        mlx1->mymap[y - 1][x] = 'P';
        mlx1->yp -= 1;
        
    }
}
void    down(t_vars *mlx1)
{
    mlx_destroy_image(mlx1->mlx, mlx1->holdon);
    mlx_clear_window (mlx1->mlx,  mlx1->win);
    if (mlx1->mymap[mlx1->yp + 1][mlx1->xp] != '1')
    {
        mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->down, mlx1->ww, mlx1->hh);
        int x = mlx1->xp ;
        int y = mlx1->yp;
        if (ready_yet(mlx1, mlx1->yp + 1, mlx1->xp) == -1)
        {
            mlx1->mymap[y][x] = 'E';
        }
        else
            mlx1->mymap[y][x] = '0';
        mlx1->mymap[y + 1][x] = 'P';
        
        mlx1->yp += 1;
    }
}
void    left(t_vars *mlx1)
{
    mlx_destroy_image(mlx1->mlx, mlx1->holdon);
    mlx_clear_window (mlx1->mlx,  mlx1->win);
     if (mlx1->mymap[mlx1->yp][mlx1->xp - 1] != '1')
    {
        mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->left, mlx1->ww, mlx1->hh);
        int x = mlx1->xp ;
        int y = mlx1->yp;
        if (ready_yet(mlx1, mlx1->yp, mlx1->xp - 1) == -1)
        {
            mlx1->mymap[y][x] = 'E';
        }
        else
            mlx1->mymap[y][x] = '0';
        mlx1->mymap[y][x - 1] = 'P';
       
        mlx1->xp -= 1;
       
    }
}

int    ready_yet(t_vars *mlx1, int y, int x)
{
    if (mlx1->mymap[y][x] == 'C')
    {
        mlx1->collected += 1;
        if (mlx1->collected == mlx1->coins_tot)
            mlx1->ready_to_exit = 1;
    }
    else if (mlx1->mymap[y][x] == 'E' )
    {
        if (mlx1->ready_to_exit == 1)
        {
            printf("YOU WON !\n");
            mlx_clear_window (mlx1->mlx,  mlx1->win);
            mlx_destroy_window(mlx1->mlx, mlx1->win);
            exit(1);
        }
        else
            return (-1);
    }
    return (0);
}