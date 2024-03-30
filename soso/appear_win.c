#include "my_header.h"


void    map_to_img2(t_max *all, int ind)
{
    if (ind == 0)
        mlx_put_image_to_window(all->mlx, all->win , all->img->holdon, all->img->img_w, all->img->img_h);
    if (ind == 'r')
        mlx_put_image_to_window(all->mlx, all->win , all->img->right, all->img->img_w, all->img->img_h);
    if (ind == 'u')
        mlx_put_image_to_window(all->mlx, all->win , all->img->top, all->img->img_w, all->img->img_h);
    if (ind == 'l')
        mlx_put_image_to_window(all->mlx, all->win , all->img->left, all->img->img_w, all->img->img_h);
    if (ind == 'd')
        mlx_put_image_to_window(all->mlx, all->win , all->img->down, all->img->img_w, all->img->img_h);
    if (ind == 'e')
    {
        mlx_put_image_to_window(all->mlx, all->win , all->img->cexit, all->img->img_w, all->img->img_h);
        // mlx_put_image_to_window(all->mlx, all->win , all->img->holdon, all->img->img_w, all->img->img_h);
    }
}

void    map_to_img3(t_max *all)
{
    if(all->cord->lkhawi == all->cord->bottles)
        mlx_put_image_to_window(all->mlx, all->win , all->img->oexit, all->img->img_w, all->img->img_h);
    else
        mlx_put_image_to_window(all->mlx, all->win , all->img->cexit, all->img->img_w, all->img->img_h);
    all->cord->cexit_h = all->img->img_h;
    all->cord->cexit_w =  all->img->img_w;
}
int nbrlen(int i)
{
    int res;

    res = 1;
    if (i < 10)
        return 1;
    res += nbrlen(i/10); 
    return(res);
}

char    *nbr_mv(int i)
{
    char    *base;
    char    *res;
    int     l;
    int     y;

    base = "0123456789";
    l = nbrlen(i);
    y = nbrlen(i);
    res = (char *)malloc(l + 1);

    if (!res)
        return(NULL);
    if (i == 0)
        res[0] = '0';
    else
    {
         while(i > 0)
        {
            res[l-1] = base[i%10];
            i = i/10;
            l--;
        }
    }
    res[y] = 0;
    return (res);
}

char    *moves(t_max *all)
{
    char    *res;
    char    *mv;
    int     i;
    int     mvl;

    res = NULL;
    i = ft_strlen("MOVES : ");
    mv = nbr_mv(all->nbr_moves);
    mvl = ft_strlen(mv);
    res = ft_strjoin(res, "MOVES: ", i);
    res = ft_strjoin(res, mv , mvl);
    free(mv);
    return (res);
}

void    show_mv(t_max *all)
{
    char    *s;

    s = moves(all);
    mlx_string_put(all->mlx, all->win, 5, 6, 0xEAEDED, s);
    free(s);
}


int    success_logout(t_max *all)
{
    mlx_destroy_window(all->mlx, all->win);
    free(all->mlx);
    exit(1);
    return(1);
}