/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/05/19 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/wolf.h>

unsigned int	color_pixel(int mappoint)
{
	unsigned int color;

	if (mappoint == 1)
		color = RGB_RED;
	if (mappoint == 2)
		color = RGB_BLUE;
	if (mappoint == 3)
		color = RGB_GREEN;
	if (mappoint == 4)
		color = RGB_WHITE;
	if (mappoint > 4)
		color = RGB_YELLOW;
	return (color);
}

void			floor_ceiling(t_look *look)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H)
		{
			if (y < WIN_H / 2)
			{
				color = RGB_SKY;
				mlx_pixel_put(look->mlx, look->win, x, y, color);
			}
			else
			{
				color = RGB_EARTH;
				mlx_pixel_put(look->mlx, look->win, x, y, color);
			}
			y++;
		}
		x++;
	}
}

void			verline(int x, int color, t_look *win)
{
	int y;

	y = win->drawstart;
	while (y++ < win->drawend)
		mlx_pixel_put(win->mlx, win->win, x, y, color);
}
