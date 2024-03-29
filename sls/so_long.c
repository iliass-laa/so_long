#include "my_header.h"

void    map_to_img(t_max *all, t_was *cord, t_img *img)
{
    int x;
    int y;

    y = 0;
    img->img_h = 0;
   
    while(cord->map[y])
    {
        x = 0;
        img->img_w = 0;
        printf("ss %s\n", cord->map[y]);
        while(cord->map[y][x])
        {
            if (cord->map[y][x] == '1')
                mlx_put_image_to_window(all->mlx, all->win , img->brick, img->img_w, img->img_h);
            if (cord->map[y][x] == 'E')
                mlx_put_image_to_window(all->mlx, all->win , img->cexit, img->img_w, img->img_h);
            if (cord->map[y][x] == 'C')
                mlx_put_image_to_window(all->mlx, all->win , img->rouge, img->img_w, img->img_h);
            if (cord->map[y][x] == 'P')
                mlx_put_image_to_window(all->mlx, all->win , img->holdon, img->img_w, img->img_h);
            x++;
            img->img_w += 32;
        }
        y++;
        img->img_h += 36;
    }
}

void    intialize_images(t_img *img , t_max *mlx1)
{
    int h = 0;
    int w = 0;
    
    img->brick = mlx_xpm_file_to_image(mlx1->mlx,"xpm/brick.xpm", &w, &h);
    img->holdon = mlx_xpm_file_to_image(mlx1->mlx,"xpm/holdstill2.xpm", &w, &h);
    img->rouge = mlx_xpm_file_to_image(mlx1->mlx, "xpm/rouge.xpm ", &w, &h);
    img->cexit =mlx_xpm_file_to_image(mlx1->mlx," xpm/closexit.xpm ", &w, &h);
    img->down = mlx_xpm_file_to_image(mlx1->mlx,"xpm/down.xpm", &w, &h); 
    img->left = mlx_xpm_file_to_image(mlx1->mlx,"xpm/left.xpm", &w, &h); 
    img->right = mlx_xpm_file_to_image(mlx1->mlx, "xpm/right.xpm", &w, &h);
    img->top = mlx_xpm_file_to_image(mlx1->mlx, "xpm/upp.xpm", &w, &h);
    img->oexit =  mlx_xpm_file_to_image(mlx1->mlx,"xpm/openexit.xpm", &w, &h);
}

int read_map(t_was *cord, t_img *s, char *path , t_checkmap *c)
{
    int fd;
    int i;
    
    fd = open(path, O_RDONLY);
    s->map_nbrl = c->map_h;
    s->map_line_l = c->map_l;
    cord->map = (char **)malloc(sizeof(char *) * (s->map_nbrl + 1));
    i = 0;
    while (i < s->map_nbrl)
    {
        cord->map[i] = read_lines(fd);
        i++;
    }
    cord->map[i] = 0;
    close(fd);
    return(1);
}
void intialize_and_run(t_max *all,  t_checkmap *s, char *path)
{
    t_was   cord1;
    t_img  img1;
    int     h;
    int     w;

    all->cord = (t_was *)malloc(sizeof(t_was));
    all->cord = &cord1;
    all->img = (t_img *)malloc(sizeof(t_img));
    all->img = &img1;
    all->mlx = mlx_init();
    all->win = mlx_new_window(all->mlx, all->win_width, all->win_hight, "so_long");
    img1.brick = mlx_xpm_file_to_image(all->mlx,"xpm/agadir.xpm", &w, &h);
    img1.holdon = mlx_xpm_file_to_image(all->mlx,"xpm/holdstill2.xpm", &w, &h);
    img1.rouge = mlx_xpm_file_to_image(all->mlx, "xpm/rouge.xpm", &w, &h);
    img1.cexit =mlx_xpm_file_to_image(all->mlx,"xpm/cexit.xpm", &w, &h);
    img1.down = mlx_xpm_file_to_image(all->mlx,"xpm/down.xpm", &w, &h); 
    img1.left = mlx_xpm_file_to_image(all->mlx,"xpm/left.xpm", &w, &h); 
    img1.right = mlx_xpm_file_to_image(all->mlx, "xpm/right.xpm", &w, &h);
    img1.top = mlx_xpm_file_to_image(all->mlx, "xpm/upp.xpm", &w, &h);
    img1.oexit =  mlx_xpm_file_to_image(all->mlx,"xpm/openexit.xpm", &w, &h);
    read_map(all->cord, all->img ,path, s);
    map_to_img(all, &cord1, &img1);
}

int main(int ac, char **av)
{
    t_max   all;
    t_checkmap str;
    if (ac != 2)
        return (0);
    if (check_map(av[1], &str) != 1)
    {
        ft_putstr_fd("Map is not Valid !\n", 2);
        return(0);
    }
    all.win_hight = 36 * str.map_h;
    all.win_width = 32 * str.map_l;
    intialize_and_run(&all, &str, av[1]);
    mlx_key_hook(all.win, key_hook, &all);    
    mlx_loop(all.mlx);
}