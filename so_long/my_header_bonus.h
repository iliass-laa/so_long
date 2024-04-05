/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:38:33 by ilaasri           #+#    #+#             */
/*   Updated: 2024/03/24 23:38:47 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_BONUS_H
# define MY_HEADER_BONUS_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define R "\x1B[31m"
# define B "\x1B[34m"
# define Y "\x1B[33m"
# define G "\x1B[32m"

# define A 0
# define D 2
# define S 1
# define W 13
# define ESC 53

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
	int		fd;
	char	**map;
	int		map_l;
	int		map_h;
	int		n_c;
	int		n_p;
	int		n_e;
	int		player_x;
	int		player_y;
	int		sign;

}			t_checkmap;

typedef struct s_read
{
	char	*res;
	char	*zoom;
	int		readed;
	int		z_len;
	int		nl_p;
}			t_read;
typedef struct s_rd
{
	int		s1len;
	int		s2len;
	int		reslen;
}			t_rd;

typedef struct s_img
{
	void	*holdon;
	void	*right;
	void	*left;
	void	*down;
	void	*top;
	void	*brick;
	void	*cexit;
	void	*oexit;
	void	*rouge;
	void	*fire;
	void	*fire1;
	void	*fire2;
	void	*fire3;
	void	*fire4;
	void	*fire5;
	void	*fire6;
	int		img_h;
	int		img_w;
	int		map_nbrl;
	int		map_line_l;
	int		p_w;
	int		p_h;
}			t_img;
typedef struct s_was
{
	char	**map;
	int		bottles;
	int		py;
	int		px;
	int		map_width;
	int		map_hight;
	int		lkhawi;
	int		player_w;
	int		player_h;
	int		cexit_h;
	int		cexit_w;
}			t_was;
typedef struct s_max
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_was	*cord;
	int		win_width;
	int		win_hight;
	int		nbr_moves;
}			t_max;

char		*ft_substr(char *s, int start, int len);
int			check_map(char *path, t_checkmap *str);
void		ft_putstr_fd(char *s, int fd);
int			check_path_name(char *path);
void		free_map(t_checkmap *s);
int			find_nl(char *s);
void		freedom(char **zoom, char **chyata, char **res, int howmany);
char		*fabor(struct s_next *var, char **chyata, int whichone);
char		*lecture2(struct s_next *var, char **chyata, int fd);
char		*elso2(char *res, char **chyata, int nlpos, char *zoom);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2, int len);
char		*read_lines(int fd);
int			check_map_content(t_checkmap *s);
void		lmssarndwhile(int i, int j, t_checkmap *s);
int			key_hook(int key, t_max *all);
void		intialize_images(t_img *img1, t_max *all);
void		intialize_images2(t_img *img1, t_max *all);
void		map_to_img(t_max *all, int ind1, int ind2);
void		map_to_img2(t_max *all, int ind);
void		map_to_img3(t_max *all);
void		map_to_img4(t_max *all, int y, int x, int ind2);
void		right(t_max *all, int y, int x);
void		left(t_max *all, int y, int x);
void		down(t_max *all, int y, int x);
void		up(t_max *all, int y, int x);
int			nbrlen(int i);
char		*nbr_mv(int i);
char		*moves(t_max *all);
void		show_mv(t_max *all);
int			success_logout(t_max *all, int ind);
int			loop_hook(t_max *all);
void		sos(t_max *all, int ind);
int			ss(t_max *all, int i);
void		step_over_exit(t_max *all, int ind, int y, int x);
#endif
