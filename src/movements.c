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

void	rotate_movement(t_look *look)
{
	double	olddirx;
	double	oldplanx;
	double	r_speed;

	r_speed = .75 * .5;
	if (look->s_right)
	{
		olddirx = look->dirx;
		look->dirx = look->dirx * cos(-r_speed) - look->diry * sin(-r_speed);
		look->diry = olddirx * sin(-r_speed) + look->diry * cos(-r_speed);
		oldplanx = look->planx;
		look->planx = look->planx * cos(-r_speed) - look->plany * sin(-r_speed);
		look->plany = oldplanx * sin(-r_speed) + look->plany * cos(-r_speed);
		look->s_right = 0;
	}
	if (look->s_left)
	{
		olddirx = look->dirx;
		look->dirx = look->dirx * cos(r_speed) - look->diry * sin(r_speed);
		look->diry = olddirx * sin(r_speed) + look->diry * cos(r_speed);
		oldplanx = look->planx;
		look->planx = look->planx * cos(r_speed) - look->plany * sin(r_speed);
		look->plany = oldplanx * sin(r_speed) + look->plany * cos(r_speed);
		look->s_left = 0;
	}
}

void	all_movements(t_look *look)
{
	double	m_sp;

	m_sp = .75 * .75;
	if (look->s_up)
	{
		if (look->w_map[(int)(look->p_x + look->dirx * m_sp)]
				[(int)(look->p_y)] == 0)
			look->p_x += look->dirx * m_sp;
		if (look->w_map[(int)(look->p_x)]
				[(int)(look->p_y + look->diry * m_sp)] == 0)
			look->p_y += look->diry * m_sp;
		look->s_up = 0;
	}
	if (look->s_down)
	{
		if (look->w_map[(int)(look->p_x - look->dirx * m_sp)]
				[(int)(look->p_y)] == 0)
			look->p_x -= look->dirx * m_sp;
		if (look->w_map[(int)(look->p_x)]
				[(int)(look->p_y - look->diry * m_sp)] == 0)
			look->p_y -= look->diry * m_sp;
		look->s_down = 0;
	}
	rotate_movement(look);
	ray_cast_loop(look);
}
