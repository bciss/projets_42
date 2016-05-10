// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gfournie <gfournie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/11/18 02:25:27 by gfournie          #+#    #+#             //
/*   Updated: 2015/11/18 23:13:51 by jdelmar          ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "../inc/ft_gkrellm.hpp"

t_env e;

void initmlx()
{
	char name[2];
	name[0] = '1';
	name[1] = 0;
	e.l = 1280;
	e.h = 800;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.l, e.h, name);
	e.img = mlx_new_image(e.mlx, e.l, e.h);
	e.addr = mlx_get_data_addr(e.img, &(e.bpp), &(e.sizel), &(e.endian));
}

int loop_hook(void *v)
{
	(void)v;
	usleep(100000);
	preparator(e);
	render2(e);
	return (0);
}

void	start_term(void)
{
	initscr();
	if (has_colors()) {
		start_color();
		init_pair(1, COLOR_BLACK, COLOR_RED);
		init_pair(2, COLOR_BLACK, COLOR_GREEN);
	}
	curs_set(0);
	timeout(1);
	noecho();
}

void	end_term(void)
{
	endwin();
}

int	main(int argc, char **argv)
{
	void *v = NULL;
	int (*ptr)(int,void*);
	ptr = key_hook;
	int (*ptr2)(void*);
	ptr2 = loop_hook;

	if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2'))
	{
		std::cout << "Usage: ./ft_gkrellm 1 for terminal mode or, 2 for graphic mode." << std::endl;
		return (0);
	}
	if (argv[1][0] == '1')
	{
		start_term();
		while (42)
		{
			req_render();
			controller();
		}
	}
	else
	{
		initmlx();
		mlx_key_hook(e.win, ptr, v);
        mlx_loop_hook(e.mlx, ptr2, v);
        mlx_loop(e.mlx);
	}
	return (0);
}
