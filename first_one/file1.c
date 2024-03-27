#include "mylib.h"

int key_hook(int key, t_vars *mlx1)
{
    if (key == D)
    {
        right(mlx1);
        put_images(mlx1 , 'r');
    }
    if (key == ESC)
    {
        mlx_clear_window (mlx1->mlx,  mlx1->win);
        mlx_destroy_window(mlx1->mlx, mlx1->win);
        exit(1);
    }
    if (key == S)
    {
        down(mlx1);
        put_images(mlx1, 'd');
    }
     if (key == A)
    {
        left(mlx1);
        put_images(mlx1 , 'l');    
    }
    if (key == W)
    {
        up(mlx1);
        put_images(mlx1, 'u');
    }
    printf("%d, %d\n", mlx1->coins_tot, mlx1->collected);
    return(0);
}

void    put_images(t_vars *mlx1, int ss)
{
    int h;
    int w;
    mlx1->holdon = mlx_xpm_file_to_image(mlx1->mlx, mlx1->holdon_path, &w, &h);
    mlx1->brick = mlx_xpm_file_to_image(mlx1->mlx,mlx1->brick_path, &w, &h);
    mlx1->rouge = mlx_xpm_file_to_image(mlx1->mlx, mlx1->rouge_path, &w, &h);
    mlx1->cexit = mlx_xpm_file_to_image(mlx1->mlx, mlx1->cexit_path, &w, &h);
    // mlx1->newone = mlx_xpm_file_to_image(mlx1->mlx, mlx1->newone_path, &w, &h);
    mlx1->down = mlx_xpm_file_to_image(mlx1->mlx, mlx1->down_path, &w, &h);
    mlx1->left = mlx_xpm_file_to_image(mlx1->mlx, mlx1->left_path, &w, &h);
    mlx1->right = mlx_xpm_file_to_image(mlx1->mlx, mlx1->right_path, &w, &h);
    mlx1->to_up = mlx_xpm_file_to_image(mlx1->mlx, mlx1->to_up_path, &w, &h);
    mlx1->oexit = mlx_xpm_file_to_image(mlx1->mlx, mlx1->oexit_path, &w, &h);
    mlx1->hh = 0;
    mlx1->ww = 0;
    int x= 0;
    int y = 0;
    int map_hight = maplen("maps/map.ber");
    int map_width = ft_strlen(mlx1->mymap[0]) ;
    while(y < map_hight)
    {
        x = 0;
        mlx1->ww = 0;
        while(x < map_width )
        {
            if(mlx1->mymap[y][x] == '1')
                mlx_put_image_to_window(mlx1->mlx, mlx1->win,  mlx1->brick, mlx1->ww, mlx1->hh);
            if(mlx1->mymap[y][x]  == 'P')
            {
                if (ss == 0)
                    mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->holdon, mlx1->ww, mlx1->hh);
                if (ss == 'r')
                    mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->right, mlx1->ww, mlx1->hh);
                if (ss == 'd')
                    mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->down, mlx1->ww, mlx1->hh);
                if (ss == 'l')
                    mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->left, mlx1->ww, mlx1->hh);
                if (ss == 'u')
                    mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->to_up, mlx1->ww, mlx1->hh);    
                mlx1->wwp = mlx1->ww;
                mlx1->hhp = mlx1->hh;
                mlx1->yp = y;
                mlx1->xp = x;
            }  
            if(mlx1->mymap[y][x]  == 'C')
            {
                if (ss == 0 )
                    mlx1->coins_tot += 1;
                mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->rouge, mlx1->ww, mlx1->hh);
            }             
            if(mlx1->mymap[y][x] == 'E')
            {                
                mlx_put_image_to_window(mlx1->mlx, mlx1->win, mlx1->cexit, mlx1->ww, mlx1->hh);
            }           
            x++;
            mlx1->ww += 32;
        }
        y++;
        mlx1->hh +=36;
    }
}

int    put_wall(t_vars *mlx1)
{
    mlx1->brick_path = "xpm/agadir.xpm";
    mlx1->holdon_path = "xpm/holdstill2.xpm";
    mlx1->rouge_path = "xpm/rouge.xpm";
    mlx1->cexit_path = "xpm/closexit.xpm";
    mlx1->down_path = "xpm/down.xpm";
    mlx1->left_path = "xpm/left2.xpm";
    mlx1->right_path = "xpm/right .xpm";
    mlx1->ice_path = "xpm/ice.xpm";
    mlx1->to_up_path = "xpm/upp.xpm";
    mlx1->oexit_path = "xpm/openexit.xpm";

    mlx1->wwp = 0;
    mlx1->ready_to_exit = 0;
    mlx1->coins_tot = 0;
    mlx1->collected = 0;

    put_images(mlx1 , 0);
    // if (mlx1->coins_tot != success_path( mlx1->xp, mlx1->yp))
    //     return 0;
    return(1);
}

int mouse_hook(t_vars *mlx1)
{
    mlx_clear_window (mlx1->mlx,  mlx1->win);
    mlx_destroy_window(mlx1->mlx, mlx1->win);
    exit(1);
    
    return(1);
}

int    window_appear(t_vars	*mlx1 , char    *path_map)
{
    int     x ;
    int     y ;

    mlx1->mymap = mapy(path_map);
   
    y = maplen(path_map) * 36;
    x = (ft_strlen(mlx1->mymap[0]) - 1) * 32;

    mlx1->mlx = mlx_init();
    mlx1->win =  mlx_new_window(mlx1->mlx, x, y,"tillas!");
    // if (mlx1->coins_tot != success_path( mlx1->xp, mlx1->yp, path_map))
    //     return 0;

    if (!mlx1->mymap || put_wall(mlx1) != 1 )
    {
        dprintf(2, "ERROR 404!\n");
        return 0;
    }
    put_wall(mlx1);
    mlx_key_hook(mlx1->win, key_hook, mlx1);
    //mlx_mouse_hook ( mlx1->win, mouse_hook, mlx1 );
    mlx_hook(mlx1->win, 17, 0, mouse_hook, mlx1);

    mlx_loop(mlx1->mlx);
    return(1);
}
 
int main()
{
    t_vars	mlx1;
    window_appear(&mlx1, "maps/map.ber");
}  