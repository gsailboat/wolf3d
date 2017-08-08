/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/05/19 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <../libft/libft.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <pthread.h>

# define MAPW 24
# define MAPH 24
# define WIN_H 400
# define WIN_W 500
# define RGB_RED 0xff0000;
# define RGB_GREEN 0xff00;
# define RGB_BLUE 0x8b;
# define RGB_WHITE 0xf8f8ff;
# define RGB_YELLOW 0x9acd32;
# define RGB_EARTH 0x774411;
# define RGB_SKY 0x227766;
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef struct		s_look
{
	int				id;
	void			*mlx;
	void			*win;
	void			*img;
	int				s_up;
	int				s_right;
	int				s_down;
	int				s_left;
	double			p_x;
	double			p_y;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			camx;
	double			rayp_x;
	double			rayp_y;
	double			raydx;
	double			raydy;
	int				mapx;
	int				mapy;
	double			side_dx;
	double			side_dy;
	double			deltax;
	double			deltay;
	double			perpwalld;
	int				stepy;
	int				stepx;
	int				drawstart;
	int				drawend;
	int				w_map[MAPW][MAPH];
	int				hit;
	int				map;
	int				in;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			weight;
	double			currentfloorx;
	double			currentfloory;
	char			user[10];
}					t_look;

void				init_struct(t_look *look);
void				verline(int x, int color, t_look *look);
int					keyhooks(int keycode, t_look *look);
unsigned int		color_pixel(int mappoint);
int					exit_hook(t_look *look);
void				all_movements(t_look *look);
void				floor_ceiling(t_look *look);
void				verline(int x, int color, t_look *look);
void				ray_cast_loop(t_look *tmp);

#endif
