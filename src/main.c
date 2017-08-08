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

void		welcome(t_look *look)
{
	char	*welcome;
	char	*tmp;

	tmp = ft_strjoin("Welcome, ", look->user);
	welcome = ft_strjoin(tmp, ", to Gregenstein!");
	free(tmp);
	mlx_string_put(look->mlx, look->win, 90, 30, 0x000099FF, welcome);
	mlx_string_put(look->mlx, look->win, 85, 110, 0x000099FF,
		"Use the arrow keys to find the door ");
	mlx_string_put(look->mlx, look->win, 75, 130, 0x000099FF,
		"as fast as possible to see if you are");
	mlx_string_put(look->mlx, look->win, 170, 149, 0x000099FF,
		"a top three time.");
	mlx_string_put(look->mlx, look->win, 150, 220, 0x000099FF,
		"Press Enter to Play.");
	free(welcome);
}

int			main(int ac, char **av)
{
	t_look	*look;

	look = (t_look*)ft_memalloc(sizeof(t_look));
	if (ac == 2)
	{
		if (ft_strlen(av[1]) > 0 && ft_strlen(av[1]) <= 10)
		{
			ft_strcpy(look->user, av[1]);
			look->map = 1;
			look->in = 0;
			init_struct(look);
			welcome(look);
			mlx_hook(look->win, 2, 3, keyhooks, look);
			mlx_hook(look->win, 17, 0, exit_hook, look);
			mlx_loop(look->mlx);
		}
		else if (av[1] <= 0)
			ft_putstr("Please write a valid username.\n");
		else
			ft_putstr("Please make username less than 11 characters.\n");
	}
	else
		ft_putstr("Usage error ./wolf [username]\n");
	free(look);
}
