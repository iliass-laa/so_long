/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:38:33 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/24 23:38:47 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MY_HEADER_H
# define MY_HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include <fcntl.h>

#define A 0
#define D 2
#define S 1
#define W 13
#define ESC 53

struct		s_my
{
	int		i;
	int		j;
	int		x;
	int		s2len;
	int		s1len;
	char	*res;
};
struct		s_next
{
	int		readed;
	int		nlpos;
	int		len;
	char	*zoom;
	char	*res;
};
typedef struct s_checkmap
{
    int     fd;
	char	**map;
    int     map_l;
    int     map_h;
    int     n_c;
    int     n_p;
    int     n_e;
    int     player_x;
    int     player_y;
    int     sign;

}   t_checkmap;

typedef struct  s_read
{
    char		*res;
	char		*zoom;
	int			readed;
	int			z_len;
	int			nl_p;
}   t_read;
typedef struct  s_rd
{
    int s1len;
    int s2len;
    int reslen;
}   t_rd;

typedef struct  s_img
{
    void    *holdon;
    void    *right;
    void    *left;
    void    *down;
    void    *top;
    void    *brick;
    void    *cexit;
    void    *oexit;
    void    *rouge;
    int     img_h;
    int     img_w;
    int     map_nbrl;
    int     map_line_l;
}   t_img;
typedef struct  s_was
{
    char    **map;
    int     bottles;
    int     py;
    int     px;
    int     map_width;
    int     map_hight;
    int     lkhawi;
    // int     hight_img;
    // int     img_width
} t_was;
typedef struct  s_max
{
    void    *mlx;
    void    *win;
    t_img   *img;
    t_was   *cord;

    int     win_width;
    int     win_hight;
}   t_max;

int     check_map(char  *path ,t_checkmap *str);
void	ft_putstr_fd(char *s, int fd);
int     check_path_name(char *path);
void    free_map(t_checkmap *s);
int     ft_strlen(char  *s);
char	*read_lines(int fd);
int     check_map_content(t_checkmap *s);
void	lmssarndwhile(int i, int j, t_checkmap *s);
int key_hook(int key, t_max *all);
# endif