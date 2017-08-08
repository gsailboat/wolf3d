/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/05/19 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/wolf.h>

void	moving_keys(int keycode, t_look *t)
{
	if (keycode == UP)
		t->s_up = 1;
	else if (keycode == DOWN)
		t->s_down = 1;
	else if (keycode == LEFT)
		t->s_left = 1;
	else if (keycode == RIGHT)
		t->s_right = 1;
	mlx_clear_window(t->mlx, t->win);
	all_movements(t);
}

int		keyhooks(int keycode, t_look *t)
{
	if (keycode == 36 && t->in == 0)
	{
		t->in = 1;
		mlx_clear_window(t->mlx, t->win);
		all_movements(t);
	}
	else if (keycode == 46 && t->in == 1)
	{
		t->map = (t->map == 1) ? 2 : 1;
		mlx_clear_window(t->mlx, t->win);
		init_struct(t);
		all_movements(t);
	}
	else if (keycode == ESC)
	{
		mlx_destroy_window(t->mlx, t->win);
		exit(0);
	}
	if ((keycode == UP || keycode == DOWN || keycode == RIGHT ||
		keycode == LEFT) && t->in == 1)
		moving_keys(keycode, t);
	return (0);
}

int		exit_hook(t_look *look)
{
	mlx_destroy_window(look->mlx, look->win);
	exit(0);
}
