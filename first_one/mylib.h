#ifndef MYLIB_H
# define MYLIB_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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
typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**mymap;
	void    *brick;
	void	*ice;
    void    *rouge;
    void    *holdon;
    void    *cexit;
	void	*newone;
	void	*down;
	void	*left;
	void	*right;
	void	*to_up;
	void	*oexit;
	char	*ice_path;
	char    *brick_path;
    char    *holdon_path;
    char    *rouge_path ;
    char    *cexit_path ;
    char    *newone_path;
    char    *down_path;
    char    *left_path;
    char    *right_path;
	char	*to_up_path;
	char	*oexit_path;
	int		xp;
	int		yp;
	int		hhp;
    int 	wwp;
	int		hh;
    int 	ww;
	int		coins_tot;
	int		collected;
	int		ready_to_exit;
}				t_vars;
char    *read_next_line(int x);
int     nlp_p(char *s);
int		find_nl(char *s);
char	*ft_strjoin(char *s1, char *s2, int len);
char	*ft_substr(char *s, int start, int len);
void	freedom(char **zoom, char **chyata, char **res, int howmany);
char	*fabor(struct s_next *var, char **chyata, int whichone);
char	*lecture2(struct s_next *var, char **chyata, int fd);
char	*elso2(char *res, char **chyata, int nlpos, char *zoom);
char	*get_next_line(int fd);
int     ft_strlen(char *s);
int     maplen(char *s);
char    **mapy (char *path);
int		put_wall(t_vars *mlx1);
void    right(t_vars *mlx1);
void    up(t_vars *mlx1);
void    down(t_vars *mlx1);
void    left(t_vars *mlx1);
void	put_images(t_vars *mlx1, int ss);
int     success_path(char **s, int x, int y);
int    ready_yet(t_vars *mlx1, int y, int x);
#endif