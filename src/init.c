/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/05/19 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/wolf.h>

void	xandy_coordtwo(t_look *look, int x, int y)
{
	if ((x >= 7 && y == MAPH - 4) || (y == 3 && x >= 9))
		look->w_map[y][x] = 3;
	else if (x >= 12 && x <= MAPW - 4 && y == MAPH - 7)
		look->w_map[y][x] = 3;
	else if (y == 14 && (x == 13 || x == 14 || x == MAPW - 2 || x == MAPW - 3))
		look->w_map[y][x] = 3;
	else if (y == 6 && (x == 15 || x == 16 || x == MAPW - 4 || x == MAPW - 5))
		look->w_map[y][x] = 3;
	else if ((y <= MAPH - 4 && x == 3) || (x == 6 && 3 <= y && y <= MAPH - 4))
		look->w_map[y][x] = 2;
	else if ((x == 9 && 4 <= y && y <= MAPH - 7) || (x == MAPW - 4 && MAPH - 6
		<= y && y <= MAPH - 4))
		look->w_map[y][x] = 2;
	else if (x == 12 && 6 <= y && y <= MAPH - 7)
		look->w_map[y][x] = 2;
	else if ((x == MAPW - 4 || x == MAPW - 9) && (7 <= y && y <= 14))
		look->w_map[y][x] = 2;
	else if (x == MAPW - 1 && y == 19)
		look->w_map[y][x] = 4;
}

void	xandy_coordone(t_look *look, int x, int y)
{
	if ((x >= 6 && x <= 10 && (y == 4 || y == 8)) ||
			(y >= 5 && y <= 7 && (x == 6 || x == 10)))
		look->w_map[y][x] = 2;
	else if ((x == 15 || x == 17 || x == 19) && (y == 4 || y == 8))
		look->w_map[y][x] = 3;
	else if ((x == 15 || x == 19) && y == 6)
		look->w_map[y][x] = 3;
	else if ((x >= 1 && x <= 8) && (y == MAPH - 2 || y == MAPH - 8))
		look->w_map[y][x] = 4;
	else if (x == 1 && (y <= MAPH - 2 && y >= MAPH - 8))
		look->w_map[y][x] = 4;
	else if (x == 8 && (y >= MAPH - 7 && y <= MAPH - 4))
		look->w_map[y][x] = 4;
	else if (y == MAPH - 4 && (x >= 4 && x <= 7))
		look->w_map[y][x] = 4;
	else if (x == 4 && (y == MAPH - 7 || y == MAPH - 5))
		look->w_map[y][x] = 4;
	else if (x == 6 && y == MAPH - 6)
		look->w_map[y][x] = 5;
}

void	map_setup(t_look *look)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAPH)
	{
		x = 0;
		while (x < MAPW)
		{
			if (x == 0 || y == 0 || y == MAPH - 1 || x == MAPW - 1)
				look->w_map[y][x] = 1;
			else
				look->w_map[y][x] = 0;
			if (look->map == 1)
				xandy_coordone(look, x, y);
			else
				xandy_coordtwo(look, x, y);
			x++;
		}
		y++;
	}
}

void	init_extra(t_look *look)
{
	look->planx = 0;
	look->plany = .66;
	look->side_dx = 0;
	look->side_dy = 0;
	look->deltax = 0;
	look->deltay = 0;
	look->perpwalld = 0;
	look->stepy = 0;
	look->stepx = 0;
	look->drawstart = 0;
	look->drawend = 0;
	look->floorxwall = 0;
	look->floorywall = 0;
	look->distwall = 0;
	look->distplayer = 0;
	look->currentdist = 0;
	look->weight = 0;
	look->currentfloorx = 0;
	look->currentfloory = 0;
	look->hit = 0;
}

void	init_struct(t_look *look)
{
	if (look->in == 0)
	{
		look->mlx = mlx_init();
		look->win = mlx_new_window(look->mlx, WIN_W, WIN_H, "Raycaster");
	}
	look->s_up = 0;
	look->s_down = 0;
	look->s_left = 0;
	look->s_right = 0;
	look->p_x = 1.5;
	look->p_y = 2.5;
	look->camx = 0;
	look->rayp_x = 0;
	look->rayp_y = 0;
	look->raydx = 0;
	look->raydy = 0;
	look->mapx = 50;
	look->mapy = 50;
	look->dirx = -1;
	look->diry = 0;
	map_setup(look);
	init_extra(look);
}
