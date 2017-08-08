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

void	side_d(t_look *look)
{
	if (look->raydx < 0)
	{
		look->stepx = -1;
		look->side_dx = (look->rayp_x - look->mapx) * look->deltax;
	}
	else
	{
		look->stepx = 1;
		look->side_dx = (look->mapx + 1 - look->rayp_x) * look->deltax;
	}
	if (look->raydy < 0)
	{
		look->stepy = -1;
		look->side_dy = (look->rayp_y - look->mapy) * look->deltay;
	}
	else
	{
		look->stepy = 1;
		look->side_dy = (look->mapy + 1 - look->rayp_y) * look->deltay;
	}
}

int		hit_loop(t_look *look)
{
	int	side;

	while (look->hit == 0)
	{
		if (look->side_dx < look->side_dy)
		{
			look->side_dx += look->deltax;
			look->mapx += look->stepx;
			side = 0;
		}
		else
		{
			look->side_dy += look->deltay;
			look->mapy += look->stepy;
			side = 1;
		}
		if (look->w_map[look->mapx][look->mapy] > 0)
			look->hit = 1;
	}
	return (side);
}

void	init_calcs(t_look *look, int x)
{
	look->camx = 2 * x / (double)WIN_W - 1;
	look->rayp_x = look->p_x;
	look->rayp_y = look->p_y;
	look->raydx = look->dirx + look->planx * look->camx;
	look->raydy = look->diry + look->plany * look->camx;
	look->mapx = (int)look->rayp_x;
	look->mapy = (int)look->rayp_y;
	look->deltax = sqrt(1 + (look->raydy * look->raydy) /
			(look->raydx * look->raydx));
	look->deltay = sqrt(1 + (look->raydx * look->raydx) /
			(look->raydy * look->raydy));
}

void	calc_verlines(t_look *look, int side)
{
	int	lineheight;

	if (side == 0)
		look->perpwalld = (look->mapx - look->rayp_x +
				(1 - look->stepx) / 2) / look->raydx;
	else
		look->perpwalld = (look->mapy - look->rayp_y +
				(1 - look->stepy) / 2) / look->raydy;
	lineheight = (int)(WIN_H / look->perpwalld);
	look->drawstart = -lineheight / 2 + WIN_H / 2;
	if (look->drawstart < 0)
		look->drawstart = 0;
	look->drawend = lineheight / 2 + WIN_H / 2;
	if (look->drawend >= WIN_H)
		look->drawend = WIN_H - 1;
}

void	ray_cast_loop(t_look *tmp)
{
	int				x;
	int				side;
	t_look			look;
	unsigned int	color;

	look = *tmp;
	x = 0;
	floor_ceiling(&look);
	while (x < WIN_W)
	{
		init_calcs(&look, x);
		side_d(&look);
		side = hit_loop(&look);
		look.hit = 0;
		calc_verlines(&look, side);
		color = color_pixel(look.w_map[look.mapx][look.mapy]);
		if (side == 1)
			color = color / 3;
		verline(x, color, &look);
		x++;
	}
}
